/*
 * @file jabber_wb.c
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
#include "jabber_wb.h"
#include "iq.h"
#include "message.h"
#include "notify.h"
#include "privacy.h"
#include "prpl.h"
#include "proxy.h"
#include "request.h"
#include "server.h"
#include "sxe.h"
#include "util.h"
#include "version.h"
#include "string.h"
#include "whiteboard.h"

void handle_wb_accept(JabberWbMessage *jwm)
{
	PurpleAccount *account;
	PurpleWhiteboard *wb;
	PurpleConnection *gc = jabber_wb_message_get_connection(jwm);
	char *to = jwm->jm->from;
	purple_debug_info("jabber-wb", "Handling Wb Accept request\n");
	account = purple_connection_get_account(gc);
	wb = purple_whiteboard_get_session(account, to);
	test_sxe();
	if (wb == NULL) {
		wb = jabber_wb_create(account, to);
	}
}

void handle_wb_clear(JabberWbMessage *jwm)
{
	PurpleAccount *account;
	PurpleWhiteboard *wb;
	PurpleConnection *gc = jabber_wb_message_get_connection(jwm);
	purple_debug_info("jabber-wb", "Got Clear (%s)\n", jwm->jm->from);
	account = purple_connection_get_account(gc);
	/* Only handle this if local client requested Doodle session (else local
	 * client would have sent one)
	 */
	wb = purple_whiteboard_get_session(account, jwm->jm->from);
	if(wb == NULL)
		return;

	if(wb->state == JABBER_WB_STATE_ESTABLISHED)
	{
		/* TODO Ask user whether to save the image before clearing it */
		purple_whiteboard_clear(wb);
	}
}

void handle_wb_end(JabberWbMessage *jwm)
{
	PurpleAccount *account;
	PurpleWhiteboard *wb;
	PurpleConnection *gc = jabber_wb_message_get_connection(jwm);
	g_return_if_fail(jwm->jm->from != NULL);
	purple_debug_info("jabber-wb", "Got End (%s)\n", jwm->jm->from);
	account = purple_connection_get_account(gc);
	wb = purple_whiteboard_get_session(account, jwm->jm->from);
	if(wb == NULL)
		return;
	if (wb->state==JABBER_WB_STATE_ESTABLISHED)
	{
		wb->state=JABBER_WB_STATE_CANCELLED;
		purple_whiteboard_destroy(wb);
	}
}

void handle_wb_initiate(JabberWbMessage *jwm)
{
	purple_debug_info("jabber-wb", "Handling Wb Initiate request\n");

	jabber_wb_accept(jwm, jwm->jm->from);
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

static char *jabber_wb_build_draw_string(wb_session *wbs, GList *draw_list)
{
	GString *message;

	g_return_val_if_fail(draw_list != NULL, NULL);

	message = g_string_new("");
	g_string_printf(message, "\"%d,%d", wbs->brush_color, wbs->brush_size);

	for (; draw_list != NULL; draw_list = draw_list->next) {
		g_string_append_printf(message, ",%d", GPOINTER_TO_INT(draw_list->data));
	}
	g_string_append_c(message, '"');
	return g_string_free(message, FALSE);

}

void jabber_wb_clear(PurpleWhiteboard *wb)
{
	PurpleConnection *gc = purple_account_get_connection(wb->account);
	if (gc && wb->state==JABBER_WB_STATE_ESTABLISHED)
		jabber_wb_send_generic(gc, wb->who, "clear", "");

}

static void jabber_wb_command_got_draw(JabberWbMessage *jwm)
{
	PurpleAccount *account;
	PurpleWhiteboard *wb;
	char **tokens, *from = jwm->jm->from, *message = jwm->data;
	int i;
	PurpleConnection *gc = jabber_wb_message_get_connection(jwm);
	GList *d_list = NULL; /* a local list of drawing info */

	g_return_if_fail(message != NULL);

	purple_debug_info("jabber-wb", "Got Draw (%s)\n", from);
	purple_debug_info("jabber-wb", "Draw message: %s\n", message);

	account = purple_connection_get_account(gc);

	/* Only handle this if local client requested whiteboard session (else local
	 * client would have sent one)
	 */
	wb = purple_whiteboard_get_session(account, from);

	if (wb == NULL)
		return;

	/* TODO Functionalize
	 * Convert drawing packet message to an integer list
	 */

	/* Check to see if the message begans and ends with quotes */
	if ((message[0] != '\"') || (message[strlen(message) - 1] != '\"'))
		return;

	/* Ignore the inital quotation mark. */
	message += 1;

	tokens = g_strsplit(message, ",", 0);

	/* Traverse and extract all integers divided by commas */
	for (i = 0; tokens[i] != NULL; i++) {
		int last = strlen(tokens[i]) - 1;
		if (tokens[i][last] == '"')
			tokens[i][last] = '\0';

		d_list = g_list_prepend(d_list, GINT_TO_POINTER(atoi(tokens[i])));
	}
	d_list = g_list_reverse(d_list);

	g_strfreev(tokens);

	jabber_wb_draw_stroke(wb, d_list);

	/* goodle_doodle_session_set_canvas_as_icon(ds); */

	g_list_free(d_list);
}

PurpleWhiteboard *jabber_wb_create(PurpleAccount *account, char *to)
{
	PurpleWhiteboard *wb;
	wb_session *wbs = g_new0(wb_session, 1);
	purple_debug_info("jabber-wb", "Createing a new jabber whiteboard session.\n");
	wb = purple_whiteboard_create(account, to, 0);
	wb->state=JABBER_WB_STATE_ESTABLISHED;
	wb->proto_data = wbs;
	jabber_wb_set_default_brush(wb);
	return wb;
}

/* Traverse through the list and draw the points and lines */
void jabber_wb_draw_stroke(PurpleWhiteboard *wb, GList *draw_list)
{
	int brush_color;
	int brush_size;
	int x;
	int y;

	g_return_if_fail(draw_list != NULL);

	brush_color = GPOINTER_TO_INT(draw_list->data);
	draw_list = draw_list->next;
	g_return_if_fail(draw_list != NULL);

	brush_size = GPOINTER_TO_INT(draw_list->data);
	draw_list = draw_list->next;
	g_return_if_fail(draw_list != NULL);

	x = GPOINTER_TO_INT(draw_list->data);
	draw_list = draw_list->next;
	g_return_if_fail(draw_list != NULL);

	y = GPOINTER_TO_INT(draw_list->data);
	draw_list = draw_list->next;
	g_return_if_fail(draw_list != NULL);

	while (draw_list != NULL && draw_list->next != NULL) {
		int dx = GPOINTER_TO_INT(draw_list->data);
		int dy = GPOINTER_TO_INT(draw_list->next->data);

		purple_whiteboard_draw_line(wb, x, y, x + dx, y + dy, brush_color,
				brush_size);

		x += dx;
		y += dy;

		draw_list = draw_list->next->next;
	}
}

void jabber_wb_end(PurpleWhiteboard *wb)
{
	PurpleConnection *gc = purple_account_get_connection(wb->account);
	if (gc && wb->state==JABBER_WB_STATE_ESTABLISHED)
		jabber_wb_send_generic(gc, wb->who, "end", "");
	g_free(wb->proto_data);

}

void jabber_wb_get_brush(const PurpleWhiteboard *wb, int *size, int *color)
{
	wb_session *wbs = wb->proto_data;
	*size = wbs->brush_size;
	*color = wbs->brush_color;
}

void jabber_wb_initiate(PurpleConnection *gc, const char *name)
{
	PurpleAccount *account;
	PurpleWhiteboard *wb;
	char *to = (char*) name;
	g_return_if_fail(gc);
	g_return_if_fail(name);
	account = purple_connection_get_account(gc);
	wb = purple_whiteboard_get_session(account, to);
	if (wb == NULL) {
		purple_debug_info("jabber-wb", "Initiating a new whiteboard session.\n");
		jabber_wb_send_generic(gc, to, "initiate", "");
	}

	/* NOTE Perhaps some careful handling of remote assumed established
	 * sessions
	 */
}

PurpleConnection *jabber_wb_message_get_connection(JabberWbMessage *jwm)
{
	return jwm->jm->js->gc;
}

void jabber_wb_message_parse(JabberMessage *jm, xmlnode *packet)
{
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
			"Whiteboard message, Buddy: %s, Data: %s, Action: %s\n",
			jwm->jm->to, jwm->data, action);
	switch (jwm->action) {
		case JABBER_WB_INITIATE:
			handle_wb_initiate(jwm);
			break;
		case JABBER_WB_ACCEPT:
			handle_wb_accept(jwm);
			break;
		case JABBER_WB_DRAW:
			jabber_wb_command_got_draw(jwm);
			break;
		case JABBER_WB_CLEAR:
			handle_wb_clear(jwm);
			break;
		case JABBER_WB_END:
			handle_wb_end(jwm);
			break;
	}
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

void jabber_wb_send_draw_list(PurpleWhiteboard *wb, GList *draw_list)
{
	char *message;
	wb_session *wbs = wb->proto_data;
	purple_debug_info("jabber-wb", "Send draw list is called.\n");
	g_return_if_fail(draw_list != NULL);
	message = jabber_wb_build_draw_string(wbs, draw_list);
	jabber_wb_send_generic(wb->account->gc, wb->who, "draw", message);
	g_free(message);

}

void jabber_wb_set_brush(PurpleWhiteboard *wb, int size, int color)
{
	wb_session *wbs = wb->proto_data;
	wbs->brush_size = size;
	wbs->brush_color = color;

	/* Notify the core about the changes */
	purple_whiteboard_set_brush(wb, size, color);
}

void jabber_wb_set_default_brush(PurpleWhiteboard *wb)
{
	jabber_wb_set_brush(wb, JABBER_WB_BRUSH_MEDIUM, JABBER_WB_COLOR_GREEN);
}


void jabber_wb_start(PurpleWhiteboard *wb)
{
	purple_debug_info("jabber-wb", "calling the jabber wb start function\n");
	purple_whiteboard_start(wb); /* Builds the UI, in place for POC */
}
