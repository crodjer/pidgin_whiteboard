/**
 * @file jabber_wb.h The Yahoo! protocol plugin Doodle IMVironment object
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
 */

#ifndef _JABBER_WB_H_
#define _JABBER_WB_H_

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "whiteboard.h"
#include "cmds.h"
#include "message.h"


typedef struct _JabberWbMessage {
	JabberMessage *jm;
	enum {
			JABBER_WB_INITIATE,
			JABBER_WB_ACCEPT,
			JABBER_WB_UPDATE,
			JABBER_WB_TERMINATE,
		}action;
	char *data;
}JabberWbMessage;

void handle_wb_initiate(JabberWbMessage *jwm);
void handle_wb_accept(JabberWbMessage *jwm);
void jabber_wb_accept(JabberWbMessage *jwm, const char *name);
PurpleWhiteboard *jabber_wb_create(PurpleAccount *account, char *to);
void jabber_wb_initiate(PurpleConnection *gc, const char *name);
xmlnode *jabber_wb_message_new(PurpleConnection *gc, const char *to, const char *sid);
PurpleConnection *jabber_wb_message_get_connection(JabberWbMessage *jwm);
void jabber_wb_message_parse(JabberMessage *jm, xmlnode *packet);
void jabber_wb_start(PurpleWhiteboard *wb);
#endif
