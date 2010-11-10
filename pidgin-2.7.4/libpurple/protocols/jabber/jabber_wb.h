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

#define JABBER_WB_CANVAS_WIDTH  368
#define JABBER_WB_CANVAS_HEIGHT 256

/* color codes (most likely RGB) */
#define	JABBER_WB_COLOR_RED    13369344
#define	JABBER_WB_COLOR_ORANGE 16737792
#define	JABBER_WB_COLOR_YELLOW 15658496
#define	JABBER_WB_COLOR_GREEN     52224
#define	JABBER_WB_COLOR_CYAN      52428
#define	JABBER_WB_COLOR_BLUE        204
#define	JABBER_WB_COLOR_VIOLET  5381277
#define	JABBER_WB_COLOR_PURPLE 13369548
#define	JABBER_WB_COLOR_TAN    12093547
#define	JABBER_WB_COLOR_BROWN   5256485
#define	JABBER_WB_COLOR_BLACK         0
#define	JABBER_WB_COLOR_GREY   11184810
#define	JABBER_WB_COLOR_WHITE  16777215

#define PALETTE_NUM_OF_COLORS 12

/* Doodle brush sizes (most likely variable) */
#define JABBER_WB_BRUSH_SMALL   2
#define JABBER_WB_BRUSH_MEDIUM  5
#define JABBER_WB_BRUSH_LARGE  10

#define JABBER_WB_MAX_BRUSH_MOTIONS 100

typedef struct _JabberWbMessage {
	JabberMessage *jm;
	enum {
			JABBER_WB_INITIATE,
			JABBER_WB_ACCEPT,
			JABBER_WB_DRAW,
			JABBER_WB_CLEAR,
			JABBER_WB_END,
		}action;
	char *data;
}JabberWbMessage;

typedef struct _wb_session
{
	int brush_size;  /* Size of drawing brush */
	int brush_color; /* Color of drawing brush */
} wb_session;


void handle_wb_initiate(JabberWbMessage *jwm);
void handle_wb_accept(JabberWbMessage *jwm);
static void jabber_wb_command_got_draw(JabberWbMessage *jwm);
PurpleWhiteboard *jabber_wb_create(PurpleAccount *account, char *to);
void jabber_wb_accept(JabberWbMessage *jwm, const char *name);
void jabber_wb_initiate(PurpleConnection *gc, const char *name);
static char *jabber_wb_build_draw_string(wb_session *ds, GList *draw_list);
void jabber_wb_send_draw_list(PurpleWhiteboard *wb, GList *draw_list);
void jabber_wb_draw_stroke(PurpleWhiteboard *wb, GList *draw_list);
void jabber_wb_get_brush(const PurpleWhiteboard *wb, int *size, int *color);
void jabber_wb_set_brush(PurpleWhiteboard *wb, int size, int color);
void jabber_wb_send_generic(PurpleConnection *gc, const char *to, const char *action, const char *data);
PurpleConnection *jabber_wb_message_get_connection(JabberWbMessage *jwm);
void jabber_wb_message_parse(JabberMessage *jm, xmlnode *packet);
void jabber_wb_start(PurpleWhiteboard *wb);
#endif
