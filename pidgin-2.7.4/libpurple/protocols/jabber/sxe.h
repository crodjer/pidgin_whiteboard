/**
 * @file sxe.h
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

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "cmds.h"
#include "message.h"

typedef enum _SXEMessageType {
	SXE_SESSION_INIT,
	SXE_SESSION_ACCEPT,
	SXE_SESSION_END,
	SXE_CONNECT,
	SXE_OFFER_STATE,
	SXE_ACCEPT_STATE,
	SXE_REFUSE_STATE,
	SXE_SEND_STATE,
} SXEMessageType;

typedef struct _JabberSXEMessage {
	JabberMessage *jm;
	SXEMessageType type;
	const char *session;
	char *state;
}JabberSXEMessage;

typedef struct _SXESession{
	PurpleAccount *account;
	GList  *users;
	char *state;
	const char *id;
}SXESession;

void handle_sxe_accept_state(JabberSXEMessage *jsm);
void handle_sxe_connect(JabberSXEMessage *jsm);
void handle_sxe_offer_state(JabberSXEMessage *jsm);
void handle_sxe_refuse_state(JabberSXEMessage *jsm);
void handle_sxe_send_state(JabberSXEMessage *jsm);
void handle_sxe_session_init(JabberSXEMessage *jsm);
void handle_sxe_session_accept(JabberSXEMessage *jsm);
void handle_sxe_session_end(JabberSXEMessage *jsm);
PurpleAccount *sxe_message_get_account(JabberSXEMessage *jsm);
const char*sxe_message_get_buddy(JabberSXEMessage *jsm);
PurpleConnection *sxe_message_get_connection(JabberSXEMessage *jsm);
SXESession *sxe_message_create_session(JabberSXEMessage *jsm);
SXESession *sxe_message_get_session(JabberSXEMessage *jsm);
void sxe_initiate(PurpleConnection *gc, const char *name);
void sxe_message_parse(JabberMessage *jm, xmlnode *packet);
void sxe_send_generic(PurpleConnection *gc, const char *to, SXEMessageType type, const char *session);
SXESession *sxe_session_add_user(SXESession *sxes, const char *who);
SXESession *sxe_session_get(PurpleConnection *gc, const char *session);
SXESession *sxe_session_get_by_account(PurpleConnection *gc, const char *who);
char *sxe_session_get_users(SXESession *sxes);
SXESession *sxe_session_create(PurpleConnection *gc, const char *session);
void sxe_session_end(SXESession *sxes );
