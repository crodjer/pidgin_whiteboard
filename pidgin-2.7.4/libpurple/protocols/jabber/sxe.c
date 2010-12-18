/*
 * @file sxe.c
 *
 * purple
 *
 * Purple is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 *
 */

/******************************************************************************
 * INCLUDES
 *****************************************************************************/
#include "internal.h"
#include "account.h"
#include "accountopt.h"
#include "blist.h"
#include "cipher.h"
#include "cmds.h"
#include "debug.h"
#include "jabber.h"
#include "jingle/jingle.h"
#include "jingle/content.h"
#include "iq.h"
#include "message.h"
#include "notify.h"
#include "privacy.h"
#include "prpl.h"
#include "proxy.h"
#include "request.h"
#include "server.h"
#include "string.h"
#include "util.h"
#include "version.h"
#include "string.h"
#include "sxe.h"

static GList *sxeList = NULL;

static void handle_sxe_accept_state(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handling SXE State Accept from %s\n", sxe_message_get_buddy(jsm));
	sxe_message_free(jsm);
}

static void handle_sxe_connect(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handling SXE Connect from %s\n", sxe_message_get_buddy(jsm));
	sxe_message_free(jsm);
}

static void handle_sxe_offer_state(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handling SXE State Offer from %s\n", sxe_message_get_buddy(jsm));
	sxe_message_free(jsm);
}

static void handle_sxe_refuse_state(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handling SXE State Refuse from %s\n", sxe_message_get_buddy(jsm));
	sxe_message_free(jsm);
}

static void handle_sxe_send_state(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handling SXE State Send from %s\n", sxe_message_get_buddy(jsm));
	sxe_message_free(jsm);
}

/*
 * Start the debug thread
 */
void sxe_initiate(PurpleConnection *gc, const char *name)
{
	JabberBuddyResource *jbr;
	JabberBuddy *jb = jabber_buddy_find(purple_connection_get_protocol_data(gc), name, FALSE);
	SXESession *sxes;
	gchar *resource = NULL, *to = NULL;
	if (!jb) {
		purple_debug_error("sxe", "Could not find Jabber buddy\n");
		return;
	}
	resource = jabber_get_resource(name);
	jbr = jabber_buddy_find_resource(jb, resource);
	g_free(resource);
	if (!jbr) {
		purple_debug_error("jabber-wb", "Could not find buddy's resource\n");
		return;
	}
	to = g_strdup_printf("%s/%s", name, jbr->name);
	purple_debug_info("sxe", "\n");
	purple_debug_info("sxe", "Initiating thread...\n");
	sxes = sxe_session_create(gc, "test-session");
	sxe_session_add_user(sxes,  to);
	sxe_send_generic(gc, to, SXE_SESSION_INIT, "test-session");
}

static void handle_sxe_session_init(JabberSXEMessage *jsm)
{
	SXESession *sxes ;
	purple_debug_info("sxe", "Handling SXE Session Init from %s\n",sxe_message_get_buddy(jsm));
	sxes = sxe_message_create_session(jsm);
	sxe_session_add_user(sxes,  sxe_message_get_buddy(jsm));
	sxe_send_generic(sxe_message_get_connection(jsm), sxe_message_get_buddy(jsm), SXE_SESSION_ACCEPT, jsm->session);
	sxe_message_free(jsm);
}

static void handle_sxe_session_accept(JabberSXEMessage *jsm)
{
	SXESession *sxes;

	purple_debug_info("sxe", "Handling SXE Session Accept from %s\n",sxe_message_get_buddy(jsm));
	sxes = sxe_message_get_session(jsm);
	if (sxes){
		sxe_session_get_users(sxes);
		sxe_session_end(sxes);
		/*
		 * End sxe session and send end message.
		 */
		sxe_send_generic(sxe_message_get_connection(jsm), sxe_message_get_buddy(jsm), SXE_SESSION_END, jsm->session);
	}
	else{
		purple_debug_error("sxe", "SXE session with ID:%s does not exists!!\n", jsm->session);
	}
	sxe_message_free(jsm);
}

static void handle_sxe_session_end(JabberSXEMessage *jsm)
{
	SXESession *sxes;
	purple_debug_info("sxe", "Handling SXE Session End from %s\n", sxe_message_get_buddy(jsm));
	sxes = sxe_message_get_session(jsm);
	if (sxes){
		sxe_session_get_users(sxes);
		/*
		* End sxe session.
		*/
		sxe_session_end(sxes);
	}
	else{
		purple_debug_error("sxe", "SXE session Account:%s ID:%s does not exists!!\n", sxe_message_get_account(jsm)->username, jsm->session);
	}
	sxe_message_free(jsm);
}

SXESession *sxe_message_create_session(JabberSXEMessage *jsm)
{
	return sxe_session_create(sxe_message_get_connection(jsm), jsm->session);
}

PurpleAccount *sxe_message_get_account(JabberSXEMessage *jsm)
{
	PurpleConnection *gc = sxe_message_get_connection(jsm);
	return purple_connection_get_account(gc);
}

const char*sxe_message_get_buddy(JabberSXEMessage *jsm)
{
	return jsm->jm->from;
}

PurpleConnection *sxe_message_get_connection(JabberSXEMessage *jsm)
{
	return jsm->jm->js->gc;
}

SXESession *sxe_message_get_session(JabberSXEMessage *jsm)
{
	return sxe_session_get(sxe_message_get_connection(jsm), jsm->session);
}

void sxe_message_free(JabberSXEMessage *jsm)
{
	//jabber_message_free(jsm->jm); 	Program received signal SIGSEGV, Segmentation fault.	0x00ea08bb in ?? ()
	//g_free((char *)jsm->session);  	*** glibc detected *** /usr/local/bin/pidgin: double free or corruption (fasttop)
	g_free(jsm->state);
	g_free(jsm);
}

void sxe_message_parse(JabberMessage *jm, xmlnode *packet)
{
	xmlnode *child, *sxe;
	JabberSXEMessage *jsm;
	jsm = g_new0(JabberSXEMessage, 1);
	jsm->jm = jm;
	sxe = xmlnode_get_child(packet, "sxe");
	jsm->session = xmlnode_get_attrib(sxe, "session");
	for(child = sxe->child; child; child = child->next) {
		if(!strcmp(child->name, "connect")){
			jsm->type= SXE_CONNECT;
			handle_sxe_connect(jsm);
		}
		else if(!strcmp(child->name, "session-init")){
			jsm->type= SXE_SESSION_INIT;
			handle_sxe_session_init(jsm);
		}
		else if(!strcmp(child->name, "session-accept")){
			jsm->type= SXE_SESSION_ACCEPT;
			handle_sxe_session_accept(jsm);
		}
		else if(!strcmp(child->name, "session-end")){
			jsm->type= SXE_SESSION_END;
			handle_sxe_session_end(jsm);
		}
		else if(!strcmp(child->name, "state-offer")){
			jsm->type= SXE_OFFER_STATE;
			handle_sxe_offer_state(jsm);
		}
		else if(!strcmp(child->name, "accept-state")){
			jsm->type= SXE_ACCEPT_STATE;
			handle_sxe_accept_state(jsm);
		}
		else if(!strcmp(child->name, "refuse-state")){
			jsm->type= SXE_REFUSE_STATE;
			handle_sxe_refuse_state(jsm);
		}
		else if(!strcmp(child->name, "state")){
			jsm->type= SXE_SEND_STATE;
			handle_sxe_send_state(jsm);
		}
	}
}

void sxe_send_generic(PurpleConnection *gc, const char *to, SXEMessageType type, const char *session)
{
	JabberStream *js = purple_connection_get_protocol_data(gc);
	xmlnode *message, *child;
	SXESession *sxes = sxe_session_get(gc, session);
	gchar *me = g_strdup_printf("%s@%s/%s", js->user->node, js->user->domain,js->user->resource);
	message = xmlnode_new("message");
	xmlnode_set_attrib(message, "to", to);
	xmlnode_set_attrib(message, "from", me);
	child = xmlnode_new_child(message, "sxe");
	xmlnode_set_attrib(child, "xmlns", "urn:xmpp:sxe:0");
	xmlnode_set_attrib(child, "session", session);
	xmlnode_set_attrib(child, "id", jabber_get_next_id(js));
	if (type==SXE_CONNECT){
		child = xmlnode_new_child(child, "connect");
	}
	else if (type==SXE_SESSION_INIT){
		child = xmlnode_new_child(child, "session-init");
	}
	else if (type==SXE_SESSION_ACCEPT){
		child = xmlnode_new_child(child, "session-accept");
	}
	else if (type==SXE_SESSION_END){
		child = xmlnode_new_child(child, "session-end");
	}
	else if (type==SXE_OFFER_STATE){
		child = xmlnode_new_child(child, "state-offer");
		child = xmlnode_new_child(child, "description");
		xmlnode_set_attrib(child, "xmlns", JINGLE_APP_XML);
	}
	else if (type==SXE_ACCEPT_STATE){
		child = xmlnode_new_child(child, "accept-state");
	}
	else if (type==SXE_REFUSE_STATE){
		child = xmlnode_new_child(child, "refuse-state");
	}
	else if (type==SXE_SEND_STATE){
		child = xmlnode_new_child(child, "state");
		xmlnode_insert_data(child,sxes->state,strlen(sxes->state));
		purple_debug_info("sxe", "Sent the document state\n");
	}
	jabber_send(purple_connection_get_protocol_data(gc), message);
	purple_debug_info("sxe", "Sent SXE message, Buddy: %s, Session: %s, Action: %d\n\n", to, session, type);
	g_free(message);
}

SXESession *sxe_session_create(PurpleConnection *gc, const char *session)
{
	char *new_state = "\
			<documen-begin  prolog='data:text/xml,%3C%3Fxml%20version%3D%271.\
			0%27%20standalone%3D%27no%27%3F%3E%0A%3C%21DOCTYPE%20svg%\
			20PUBLIC%20%27-%2F%2FW3C%2F%2FDTD%20SVG%201.1%2F%2FEN%27%\
			20%27http%3A%2F%2Fwww.w3.org%2FGraphics%2FSVG%2F1.1%2FDTD\
			%2Fsvg11.dtd%27%3E%0A'/><document-end last-sender='' last-id=''>\
	";
	PurpleAccount *account = purple_connection_get_account(gc);
	SXESession *sxes = sxe_session_get(gc, session);
	if (sxes){

		purple_debug_error("sxe", "SXE session with ID:%s, already exists!!\n", sxes->id);
	}
	else{
		sxes = g_new0(SXESession , 1);
		sxes->account = account;
		sxes->state = new_state;
		sxes->users = NULL;
		sxes->id = g_malloc(strlen(session)+1);
		strcpy((char *)sxes->id, session);
		sxeList = g_list_append(sxeList, sxes);
		purple_debug_info("sxe", "Created SXE Session (Account:%s, ID: %s)\n", sxes->account->username, sxes->id);
	}
	return sxes;
}

SXESession *sxe_session_add_user(SXESession *sxes, const char *who)
{
	char *user = g_malloc(strlen(who)+1);
	strcpy(user, who);
	purple_debug_info("sxe", "Adding Buddy: %s to Session (Account:%s, ID: %s, User List: %s)\n", who, sxes->account->username, sxes->id, sxe_session_get_users(sxes));
	sxes->users =  g_list_append(sxes->users, (gchar *)user);
	return sxes;
}

SXESession *sxe_session_get(PurpleConnection *gc, const char *session)
{
	PurpleAccount *account = purple_connection_get_account(gc);
	SXESession *sxes;
	GList *l = sxeList;
	//purple_debug_info("sxe", "Available Sessions: \n%s", sxe_session_get_list());
	while(l != NULL)
	{
		sxes = l->data;
		if(sxes->account == account && purple_strequal(sxes->id, session))
		{
			purple_debug_info("sxe", "Got SXE Session (Account:%s, ID: %s, User List: %s)\n", sxes->account->username, sxes->id, sxe_session_get_users(sxes));
			return sxes;
		}
		l = l->next;
	}
	return NULL;
}

char *sxe_session_get_list(void)
{
	SXESession *sxes;
	GList *l = sxeList;
	char *session_list="";
	while(l != NULL)
	{
		sxes = l->data;
		session_list = g_strdup_printf("%sAccount:%s, ID: %s, User List: %s\n",session_list ,sxes->account->username, sxes->id, sxe_session_get_users(sxes));
		l = l->next;
	}
	return session_list;
}

char *sxe_session_get_users(SXESession *sxes)
{
	char *user, *user_list = "";
	GList *l = sxes->users;
	while(l!=NULL)
	{
		user = l->data;
		user_list = g_strdup_printf("%s%s;",user_list ,user);
		l=l->next;
	}
	return (!strcmp(user_list, ""))?"Empty":user_list;
}

/*
 * Gives Error:
 * *** glibc detected *** /usr/local/bin/pidgin: double free or corruption (fasttop): 0x08761268 ***
 */
void sxe_session_users_free(GList *l)
{
	while(l != NULL)
	{
		g_free(l->data);
	}
}
/*
 * Free the memory here
 */
void sxe_session_end(SXESession *sxes)
{
	g_return_if_fail(sxes != NULL);
	purple_debug_info("sxe", "Ending SXE Session (Account:%s, ID: %s)\n", sxes->account->username, sxes->id);
	g_free((char *)sxes->id);
	//sxe_session_users_free(sxes->users);
	sxeList = g_list_remove(sxeList, sxes);
	g_free(sxes);
}
