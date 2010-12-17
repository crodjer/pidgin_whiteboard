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
	SXE_CONNECT,
	SXE_OFFER_STATE,
	SXE_ACCEPT_STATE,
	SXE_REFUSE_STATE,
	SXE_SEND_STATE,
} SXEMessageType;

typedef struct _JabberSXEMessage {
	JabberMessage *jm;
	SXEMessageType type;
	char *data;
	char *state;
}JabberSXEMessage;

typedef struct _SXESession{
	PurpleAccount *account;
	char *who;
	char *state;
	char *id;
}SXESession;

void handle_sxe_accept_state(JabberSXEMessage *jsm);
void handle_sxe_connect(JabberSXEMessage *jsm);
void handle_sxe_offer_state(JabberSXEMessage *jsm);
void handle_sxe_refuse_state(JabberSXEMessage *jsm);
void handle_sxe_send_state(JabberSXEMessage *jsm);
void sxe_message_parse(JabberMessage *jm, xmlnode *packet);
void sxe_send_generic(PurpleConnection *gc, const char *to, SXEMessageType type);
SXESession *sxe_get_session(const PurpleAccount *account, const char *who);
SXESession *sxe_session_create(PurpleAccount *account, const char *who, char *state, JabberStream *js);
