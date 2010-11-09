/*
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
#include "notify.h"
#include "privacy.h"
#include "prpl.h"
#include "proxy.h"
#include "request.h"
#include "server.h"
#include "util.h"
#include "version.h"
#include "string.h"
#include "jabber.h"
#include "iq.h"
#include "message.h"
#include "whiteboard.h"
#include "jabber_wb.h"

void handle_wb_initiate(JabberWbMessage *jwm) {
	purple_debug_info("jabber-wb", "Handling Wb Initiate request\n");
	jabber_wb_accept(jwm, jwm->jm->from);
}

void handle_wb_accept(JabberWbMessage *jwm) {
	PurpleAccount *account;
	PurpleWhiteboard *wb;
	PurpleConnection *gc = jabber_wb_message_get_connection(jwm);
	char *to = jwm->jm->from;
	purple_debug_info("jabber-wb", "Handling Wb Accept request\n");
	account = purple_connection_get_account(gc);
	wb = purple_whiteboard_get_session(account, to);
	if (wb == NULL) {
		wb = jabber_wb_create(account, to);
	}
}

void jabber_wb_accept(JabberWbMessage *jwm, const char *name)
{
	PurpleAccount *account;
	PurpleWhiteboard *wb;
	PurpleConnection *gc = jabber_wb_message_get_connection(jwm);
	char *to = (char*) name;
	g_return_if_fail(gc);
	g_return_if_fail(name);
	account = purple_connection_get_account(gc);
	wb = purple_whiteboard_get_session(account, to);
	if (wb == NULL) {
		wb = jabber_wb_create(account, to);
		jabber_wb_send_generic(gc, to, "accept", "");
	}
}

PurpleWhiteboard *jabber_wb_create(PurpleAccount *account, char *to) {
	PurpleWhiteboard *wb;
	wb_session *wbs = g_new0(wb_session, 1);
	purple_debug_info("jabber-wb", "Createing a new jabber whiteboard session.\n");
	wb = purple_whiteboard_create(account, to, 0);
	wbs->brush_size = JABBER_WB_BRUSH_MEDIUM;
	wbs->brush_color = JABBER_WB_COLOR_CYAN;
	wb->proto_data = wbs;
	return wb;
}

void jabber_wb_initiate(PurpleConnection *gc, const char *name) {
	PurpleAccount *account;
	PurpleWhiteboard *wb;
	//JabberStream *js = purple_connection_get_protocol_data(gc);
	//gchar *sid = NULL;
	char *to = (char*) name;
	g_return_if_fail(gc);
	g_return_if_fail(name);
	account = purple_connection_get_account(gc);
	wb = purple_whiteboard_get_session(account, to);
	if (wb == NULL) {
		//sid = jabber_get_next_id(js);
		purple_debug_info("jabber-wb", "Initiating a new whiteboard session.\n");
		jabber_wb_send_generic(gc, to, "initiate", "");
		//wb = purple_whiteboard_create(account, to);
		/* Insert this 'session' in the list.  At this point, it's only a
		 * requested session.
		 */
	}

	/* NOTE Perhaps some careful handling of remote assumed established
	 * sessions
	 */
}

void jabber_wb_send_generic(PurpleConnection *gc, const char *to, const char *action, const char *data)
{
	JabberStream *js = purple_connection_get_protocol_data(gc);
	JabberBuddy *jb;
	JabberBuddyResource *jbr;
	xmlnode *message, *child;
	gchar *resource = NULL, *me = NULL, *who = NULL;
	jb = jabber_buddy_find(js, to, FALSE);
	if (!jb) {
		purple_debug_error("jabber-wb", "Could not find Jabber buddy\n");
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
	me = g_strdup_printf("%s@%s/%s", js->user->node, js->user->domain,
			js->user->resource);
	message = xmlnode_new("message");
	xmlnode_set_attrib(message, "type", "chat");
	xmlnode_set_attrib(message, "id", jabber_get_next_id(js));
	xmlnode_set_attrib(message, "to", who);
	xmlnode_set_attrib(message, "from", me);
	child = xmlnode_new_child(message, "whiteboard");
	xmlnode_set_attrib(child, "action", action);
	xmlnode_insert_data(child,data,strlen(data));
	jabber_send(js, message);
}

PurpleConnection *jabber_wb_message_get_connection(JabberWbMessage *jwm) {
	return jwm->jm->js->gc;
}

void jabber_wb_message_parse(JabberMessage *jm, xmlnode *packet) {
	xmlnode *child;
	gchar *action;
	JabberWbMessage *jwm;
	jwm = g_new0(JabberWbMessage, 1);
	jwm->jm = jm;
	child = xmlnode_get_child(packet, "whiteboard");
	action = (char*) xmlnode_get_attrib(child, "action");
	jwm->data = xmlnode_get_data(child);
	if (!strcmp(action, "initiate")) {
		jwm->action = JABBER_WB_INITIATE;
	} else if (!strcmp(action, "accept")) {
		jwm->action = JABBER_WB_ACCEPT;
	} else if (!strcmp(action, "draw")) {
		jwm->action = JABBER_WB_DRAW;
	} else if (!strcmp(action, "clear")) {
		jwm->action = JABBER_WB_CLEAR;
	} else if (!strcmp(action, "end")) {
		jwm->action = JABBER_WB_END;
	}
	purple_debug_info("jabber-wb",
			"Sent a whiteboard message, Buddy: %s, Data: %s, Action: %s\n",
			jwm->jm->to, jwm->data, action);
	switch (jwm->action) {
		case JABBER_WB_INITIATE:
			handle_wb_initiate(jwm);
			break;
		case JABBER_WB_ACCEPT:
			handle_wb_accept(jwm);
			break;
		case JABBER_WB_DRAW:
			//jabber_wb_command_got_draw(jwm);
			break;
		case JABBER_WB_CLEAR:
			//handle_wb_got_clear(jwm);
			break;
		case JABBER_WB_END:
			break;
	}
}
void jabber_wb_start(PurpleWhiteboard *wb) {
	purple_debug_info("jabber-wb", "calling the jabber wb start function\n");
	purple_whiteboard_start(wb); /* Builds the UI, in place for POC */
}
