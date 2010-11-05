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

#include "jabber.h"
#include "iq.h"
#include "message.h"
#include "whiteboard.h"
#include "jabber_wb.h"

void jabber_wb_initiate(PurpleConnection *gc, const char *name)
{
	PurpleAccount *account;
	PurpleWhiteboard *wb;
	JabberStream *js = purple_connection_get_protocol_data(gc);
	xmlnode *message;
	gchar *sid = NULL;
	char *to = (char*)name;
	g_return_if_fail(gc);
	g_return_if_fail(name);
	account = purple_connection_get_account(gc);
	wb = purple_whiteboard_get_session(account, to);
	if(wb == NULL)
	{
		sid = jabber_get_next_id(js);
		purple_debug_info("jabber-wb", "Initiating a new whiteboard session.\n");
		message = jabber_wb_message_new(gc, to, sid);
		if (message){
			jabber_send(js, message);
		}
		//wb = purple_whiteboard_create(account, to);
		/* Insert this 'session' in the list.  At this point, it's only a
		 * requested session.
		 */
	}

	/* NOTE Perhaps some careful handling of remote assumed established
	 * sessions
	 */
}

PurpleWhiteboard *jabber_wb_create(PurpleAccount *account, char *to)
{
	PurpleWhiteboard *wb;
	purple_debug_info("jabber-wb", "Createing a jabber whiteboard\n");
	wb = purple_whiteboard_create(account, to, 0);
	return wb;
}

xmlnode *jabber_wb_message_new(PurpleConnection *gc, const char *to, const char *sid){
	JabberStream *js = purple_connection_get_protocol_data(gc);
	JabberBuddy *jb;
	JabberBuddyResource *jbr;
	xmlnode *message, *child;
	gchar *resource = NULL, *me = NULL,  *who = NULL;
	jb = jabber_buddy_find(js, to, FALSE);
	if (!jb) {
		purple_debug_error("jabber-wb", "Could not find Jabber buddy\n");
		return NULL;
	}
	resource = jabber_get_resource(to);
	jbr = jabber_buddy_find_resource(jb, resource);
	g_free(resource);
	if (!jbr) {
		purple_debug_error("jabber-wb", "Could not find buddy's resource\n");
		return NULL;
	}
	who = g_strdup_printf("%s/%s", to, jbr->name);
	me = g_strdup_printf("%s@%s/%s", js->user->node, js->user->domain, js->user->resource);
	message = xmlnode_new("message");
	xmlnode_set_attrib(message, "type", "chat");
	xmlnode_set_attrib(message, "id", sid);
	xmlnode_set_attrib(message, "to", who);
	xmlnode_set_attrib(message, "from", me);
	xmlnode_new_child(message, "whiteboard");
	child = xmlnode_get_child(message, "whiteboard");
	xmlnode_set_attrib(child, "action", "initiate");
	return message;
}
void jabber_wb_start(PurpleWhiteboard *wb)
{
	purple_debug_info("jabber-wb", "calling the jabber wb start function\n");
	purple_whiteboard_start(wb);	/* Builds the UI, in place for POC */
}
