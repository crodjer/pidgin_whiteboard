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
#include "util.h"
#include "version.h"
#include "string.h"
#include "sxe.h"


void handle_sxe_accept_state(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handeling SXE State Accept\n");
}

void handle_sxe_connect(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handeling SXE Connect\n");
}

void handle_sxe_offer_state(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handeling SXE State Offer\n");
}

void handle_sxe_refuse_state(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handeling SXE State Refuse\n");
}

void handle_sxe_send_state(JabberSXEMessage *jsm)
{
	purple_debug_info("sxe", "Handeling SXE State Send\n");
}

void sxe_message_parse(JabberMessage *jm, xmlnode *packet)
{
	xmlnode *child, *sxe;
	JabberSXEMessage *jsm;
	jsm = g_new0(JabberSXEMessage, 1);
	jsm->jm = jm;
	sxe = xmlnode_get_child(packet, "sxe");
	for(child = sxe->child; child; child = child->next) {
		if(!strcmp(child->name, "connect")){
			jsm->type= SXE_CONNECT;
		}
		else if(!strcmp(child->name, "state-offer")){
			jsm->type= SXE_OFFER_STATE;
		}
		else if(!strcmp(child->name, "accept-state")){
			jsm->type= SXE_ACCEPT_STATE;
		}
		else if(!strcmp(child->name, "refuse-state")){
			jsm->type= SXE_REFUSE_STATE;
		}
		else {
			jsm->type= SXE_SEND_STATE;
		}
	}
	purple_debug_info("sxe", "SXE message, Buddy: %s, Data: %s, Action: %d\n", jsm->jm->to, jsm->data, jsm->type);
	switch (jsm->type) {
		case SXE_CONNECT:
			handle_sxe_connect(jsm);
			break;
		case SXE_OFFER_STATE:
			handle_sxe_offer_state(jsm);
			break;
		case SXE_ACCEPT_STATE:
			handle_sxe_accept_state(jsm);
			break;
		case SXE_REFUSE_STATE:
			handle_sxe_refuse_state(jsm);
			break;
		case SXE_SEND_STATE:
			handle_sxe_send_state(jsm);
			break;
	}
}

void sxe_send_generic(PurpleConnection *gc, const char *to, const char *session, SXEMessageType type)
{
	JabberStream *js = purple_connection_get_protocol_data(gc);
	JabberBuddy *jb;
	JabberBuddyResource *jbr;
	xmlnode *message, *child;
	gchar *resource = NULL, *me = NULL, *who = NULL;
	jb = jabber_buddy_find(js, to, FALSE);
	if (!jb) {
		purple_debug_error("sxe", "Could not find Jabber buddy\n");
		return;
	}
	resource = jabber_get_resource(to);
	jbr = jabber_buddy_find_resource(jb, resource);
	g_free(resource);
	if (!jbr) {
		purple_debug_error("jabber-wb", "Could not find buddy's resource\n");
		return;
	}
	who = g_strdup_printf("%s/%s", to, jbr->name);
	me = g_strdup_printf("%s@%s/%s", js->user->node, js->user->domain,js->user->resource);
	message = xmlnode_new("message");
	xmlnode_set_attrib(message, "to", who);
	xmlnode_set_attrib(message, "from", me);
	child = xmlnode_new_child(message, "sxe");
	xmlnode_set_attrib(child, "xmlns", "urn:xmpp:sxe:0");
	xmlnode_set_attrib(child, "session", session);
	xmlnode_set_attrib(child, "id", jabber_get_next_id(js));
	if (type==SXE_CONNECT){
		child = xmlnode_new_child(child, "connect");
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
	}
	jabber_send(purple_connection_get_protocol_data(gc), message);
	purple_debug_info("sxe", "Sent an sxe message!\n");

}
