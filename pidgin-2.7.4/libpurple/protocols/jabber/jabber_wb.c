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

#include "whiteboard.h"
#include "jabber_wb.h"

void jabber_wb_initiate(PurpleConnection *gc, const char *name)
{
	PurpleAccount *account;
	char *to = (char*)name;
	PurpleWhiteboard *wb;
	g_return_if_fail(gc);
	g_return_if_fail(name);

	account = purple_connection_get_account(gc);
	wb = purple_whiteboard_get_session(account, to);

	if(wb == NULL)
	{
		purple_debug_info("***WB***", "whiteboard is not null!");
		/* Insert this 'session' in the list.  At this point, it's only a
		 * requested session.
		 */
		wb = purple_whiteboard_create(account, to, 0);
	}

	/* NOTE Perhaps some careful handling of remote assumed established
	 * sessions
	 */
}

void jabber_wb_start(PurpleWhiteboard *wb)
{
	purple_debug_info("***WB***", "calling the jabber wb start function");
	purple_whiteboard_start(wb);	/* Builds the UI, in place for POC */
}
