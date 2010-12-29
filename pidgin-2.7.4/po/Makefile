# Makefile for program source directory in GNU NLS utilities package.
# Copyright (C) 1995, 1996, 1997 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
# Copyright (C) 2004-2008 Rodney Dawes <dobey.pwns@gmail.com>
#
# This file may be copied and used freely without restrictions.  It may
# be used in projects which are not available under a GNU Public License,
# but which still want to provide support for the GNU gettext functionality.
#
# - Modified by Owen Taylor <otaylor@redhat.com> to use GETTEXT_PACKAGE
#   instead of PACKAGE and to look for po2tbl in ./ not in intl/
#
# - Modified by jacob berkman <jacob@ximian.com> to install
#   Makefile.in.in and po2tbl.sed.in for use with glib-gettextize
#
# - Modified by Rodney Dawes <dobey.pwns@gmail.com> for use with intltool
#
# We have the following line for use by intltoolize:
# INTLTOOL_MAKEFILE

GETTEXT_PACKAGE = pidgin
PACKAGE = pidgin
VERSION = 2.7.4

SHELL = /bin/bash

srcdir = .
top_srcdir = ..
top_builddir = ..


prefix = /usr/local
exec_prefix = ${prefix}
datadir = ${datarootdir}
datarootdir = ${prefix}/share
libdir = ${exec_prefix}/lib
DATADIRNAME = share
itlocaledir = $(prefix)/$(DATADIRNAME)/locale
subdir = po
install_sh = ${SHELL} /home/pankaj/git_repo/pidgin_whiteboard/pidgin-2.7.4/install-sh
# Automake >= 1.8 provides /bin/mkdir -p.
# Until it can be supposed, use the safe fallback:
mkdir_p = $(install_sh) -d

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

GMSGFMT = /usr/bin/msgfmt
MSGFMT = /usr/bin/msgfmt
XGETTEXT = /usr/bin/xgettext
INTLTOOL_UPDATE = /usr/bin/intltool-update
INTLTOOL_EXTRACT = /usr/bin/intltool-extract
MSGMERGE = INTLTOOL_EXTRACT=$(INTLTOOL_EXTRACT) srcdir=$(srcdir) $(INTLTOOL_UPDATE) --gettext-package $(GETTEXT_PACKAGE) --dist
GENPOT   = INTLTOOL_EXTRACT=$(INTLTOOL_EXTRACT) srcdir=$(srcdir) $(INTLTOOL_UPDATE) --gettext-package $(GETTEXT_PACKAGE) --pot

ALL_LINGUAS = af am ar az be@latin bg bn bn_IN bs ca ca@valencia cs da de dz el en_AU en_CA en_GB eo es et eu fa fi fr ga gl gu he hi hu hy id it ja ka km kn ko ku lo lt mai mk mn mr ms_MY my_MM nb ne nl nn oc or pa pl pt_BR pt ps ro ru si sk sl sq sr sr@latin sv sw ta te th tr uk ur vi xh zh_CN zh_HK zh_TW

PO_LINGUAS=$(shell if test -r $(srcdir)/LINGUAS; then grep -v "^\#" $(srcdir)/LINGUAS; else echo "$(ALL_LINGUAS)"; fi)

USER_LINGUAS=$(shell if test -n "$(LINGUAS)"; then LLINGUAS="$(LINGUAS)"; ALINGUAS="$(ALL_LINGUAS)"; for lang in $$LLINGUAS; do if test -n "`grep \^$$lang$$ $(srcdir)/LINGUAS 2>/dev/null`" -o -n "`echo $$ALINGUAS|tr ' ' '\n'|grep \^$$lang$$`"; then printf "$$lang "; fi; done; fi)

USE_LINGUAS=$(shell if test -n "$(USER_LINGUAS)" -o -n "$(LINGUAS)"; then LLINGUAS="$(USER_LINGUAS)"; else if test -n "$(PO_LINGUAS)"; then LLINGUAS="$(PO_LINGUAS)"; else LLINGUAS="$(ALL_LINGUAS)"; fi; fi; for lang in $$LLINGUAS; do printf "$$lang "; done)

POFILES=$(shell LINGUAS="$(PO_LINGUAS)"; for lang in $$LINGUAS; do printf "$$lang.po "; done)

DISTFILES = Makefile.in.in POTFILES.in $(POFILES)
EXTRA_DISTFILES = ChangeLog POTFILES.skip Makevars LINGUAS

POTFILES = \
	../finch/finch.c \
	../finch/gntaccount.c \
	../finch/gntblist.c \
	../finch/gntcertmgr.c \
	../finch/gntconn.c \
	../finch/gntconv.c \
	../finch/gntdebug.c \
	../finch/gntft.c \
	../finch/gntlog.c \
	../finch/gntmedia.c \
	../finch/gntnotify.c \
	../finch/gntplugin.c \
	../finch/gntpounce.c \
	../finch/gntprefs.c \
	../finch/gntrequest.c \
	../finch/gntroomlist.c \
	../finch/gntsound.c \
	../finch/gntstatus.c \
	../finch/gntui.c \
	../finch/libgnt/gntbox.c \
	../finch/libgnt/gntbutton.c \
	../finch/libgnt/gntcheckbox.c \
	../finch/libgnt/gntcolors.c \
	../finch/libgnt/gntcombobox.c \
	../finch/libgnt/gntentry.c \
	../finch/libgnt/gntkeys.c \
	../finch/libgnt/gntlabel.c \
	../finch/libgnt/gntline.c \
	../finch/libgnt/gntstyle.c \
	../finch/libgnt/gnttextview.c \
	../finch/libgnt/gnttree.c \
	../finch/libgnt/gntutils.c \
	../finch/libgnt/gntwidget.c \
	../finch/plugins/gntclipboard.c \
	../finch/plugins/gntgf.c \
	../finch/plugins/gnthistory.c \
	../finch/plugins/gnttinyurl.c \
	../finch/plugins/grouping.c \
	../finch/plugins/lastlog.c \
	../libpurple/account.c \
	../libpurple/blist.c \
	../libpurple/certificate.c \
	../libpurple/connection.c \
	../libpurple/conversation.c \
	../libpurple/dbus-server.c \
	../libpurple/dbus-server.h \
	../libpurple/desktopitem.c \
	../libpurple/dnsquery.c \
	../libpurple/ft.c \
	../libpurple/gconf/purple.schemas.in \
	../libpurple/log.c \
	../libpurple/media/backend-fs2.c \
	../libpurple/plugin.c \
	../libpurple/plugins/autoaccept.c \
	../libpurple/plugins/buddynote.c \
	../libpurple/plugins/ciphertest.c \
	../libpurple/plugins/dbus-example.c \
	../libpurple/plugins/filectl.c \
	../libpurple/plugins/idle.c \
	../libpurple/plugins/ipc-test-client.c \
	../libpurple/plugins/ipc-test-server.c \
	../libpurple/plugins/joinpart.c \
	../libpurple/plugins/log_reader.c \
	../libpurple/plugins/mono/loader/mono.c \
	../libpurple/plugins/newline.c \
	../libpurple/plugins/offlinemsg.c \
	../libpurple/plugins/one_time_password.c \
	../libpurple/plugins/perl/perl.c \
	../libpurple/plugins/psychic.c \
	../libpurple/plugins/signals-test.c \
	../libpurple/plugins/simple.c \
	../libpurple/plugins/ssl/ssl-gnutls.c \
	../libpurple/plugins/ssl/ssl-nss.c \
	../libpurple/plugins/ssl/ssl.c \
	../libpurple/plugins/statenotify.c \
	../libpurple/plugins/tcl/tcl.c \
	../libpurple/protocols/bonjour/bonjour.c \
	../libpurple/protocols/bonjour/bonjour.h \
	../libpurple/protocols/bonjour/jabber.c \
	../libpurple/protocols/bonjour/mdns_win32.c \
	../libpurple/protocols/gg/gg.c \
	../libpurple/protocols/irc/cmds.c \
	../libpurple/protocols/irc/dcc_send.c \
	../libpurple/protocols/irc/irc.c \
	../libpurple/protocols/irc/msgs.c \
	../libpurple/protocols/irc/parse.c \
	../libpurple/protocols/jabber/adhoccommands.c \
	../libpurple/protocols/jabber/auth.c \
	../libpurple/protocols/jabber/auth_cyrus.c \
	../libpurple/protocols/jabber/auth_digest_md5.c \
	../libpurple/protocols/jabber/auth_plain.c \
	../libpurple/protocols/jabber/auth_scram.c \
	../libpurple/protocols/jabber/bosh.c \
	../libpurple/protocols/jabber/buddy.c \
	../libpurple/protocols/jabber/chat.c \
	../libpurple/protocols/jabber/jabber.c \
	../libpurple/protocols/jabber/jutil.c \
	../libpurple/protocols/jabber/libxmpp.c \
	../libpurple/protocols/jabber/message.c \
	../libpurple/protocols/jabber/parser.c \
	../libpurple/protocols/jabber/presence.c \
	../libpurple/protocols/jabber/roster.c \
	../libpurple/protocols/jabber/si.c \
	../libpurple/protocols/jabber/usermood.c \
	../libpurple/protocols/jabber/usernick.c \
	../libpurple/protocols/jabber/xdata.c \
	../libpurple/protocols/msn/contact.c \
	../libpurple/protocols/msn/dialog.c \
	../libpurple/protocols/msn/error.c \
	../libpurple/protocols/msn/group.h \
	../libpurple/protocols/msn/msg.c \
	../libpurple/protocols/msn/msn.c \
	../libpurple/protocols/msn/nexus.c \
	../libpurple/protocols/msn/notification.c \
	../libpurple/protocols/msn/oim.c \
	../libpurple/protocols/msn/servconn.c \
	../libpurple/protocols/msn/session.c \
	../libpurple/protocols/msn/slp.c \
	../libpurple/protocols/msn/state.c \
	../libpurple/protocols/msn/switchboard.c \
	../libpurple/protocols/msn/userlist.c \
	../libpurple/protocols/mxit/actions.c \
	../libpurple/protocols/mxit/filexfer.c \
	../libpurple/protocols/mxit/http.c \
	../libpurple/protocols/mxit/login.c \
	../libpurple/protocols/mxit/mxit.c \
	../libpurple/protocols/mxit/multimx.c \
	../libpurple/protocols/mxit/profile.c \
	../libpurple/protocols/mxit/protocol.c \
	../libpurple/protocols/mxit/roster.c \
	../libpurple/protocols/mxit/splashscreen.c \
	../libpurple/protocols/myspace/myspace.c \
	../libpurple/protocols/myspace/user.c \
	../libpurple/protocols/myspace/zap.c \
	../libpurple/protocols/novell/nmuser.c \
	../libpurple/protocols/novell/novell.c \
	../libpurple/protocols/oscar/authorization.c \
	../libpurple/protocols/oscar/clientlogin.c \
	../libpurple/protocols/oscar/encoding.c \
	../libpurple/protocols/oscar/family_chatnav.c \
	../libpurple/protocols/oscar/family_icbm.c \
	../libpurple/protocols/oscar/family_locate.c \
	../libpurple/protocols/oscar/flap_connection.c \
	../libpurple/protocols/oscar/libaim.c \
	../libpurple/protocols/oscar/libicq.c \
	../libpurple/protocols/oscar/odc.c \
	../libpurple/protocols/oscar/oft.c \
	../libpurple/protocols/oscar/oscar.c \
	../libpurple/protocols/oscar/peer.c \
	../libpurple/protocols/oscar/util.c \
	../libpurple/protocols/oscar/userinfo.c \
	../libpurple/protocols/oscar/visibility.c \
	../libpurple/protocols/qq/buddy_info.c \
	../libpurple/protocols/qq/buddy_list.c \
	../libpurple/protocols/qq/buddy_memo.c \
	../libpurple/protocols/qq/buddy_opt.c \
	../libpurple/protocols/qq/group.c \
	../libpurple/protocols/qq/group_im.c \
	../libpurple/protocols/qq/group_info.c \
	../libpurple/protocols/qq/group_internal.c \
	../libpurple/protocols/qq/group_join.c \
	../libpurple/protocols/qq/group_opt.c \
	../libpurple/protocols/qq/im.c \
	../libpurple/protocols/qq/qq.c \
	../libpurple/protocols/qq/qq_base.c \
	../libpurple/protocols/qq/qq_network.c \
	../libpurple/protocols/qq/qq_process.c \
	../libpurple/protocols/qq/send_file.c \
	../libpurple/protocols/sametime/sametime.c \
	../libpurple/protocols/silc/buddy.c \
	../libpurple/protocols/silc/chat.c \
	../libpurple/protocols/silc/ft.c \
	../libpurple/protocols/silc/ops.c \
	../libpurple/protocols/silc/pk.c \
	../libpurple/protocols/silc/silc.c \
	../libpurple/protocols/silc/util.c \
	../libpurple/protocols/silc/wb.c \
	../libpurple/protocols/silc10/buddy.c \
	../libpurple/protocols/silc10/chat.c \
	../libpurple/protocols/silc10/ft.c \
	../libpurple/protocols/silc10/ops.c \
	../libpurple/protocols/silc10/pk.c \
	../libpurple/protocols/silc10/silc.c \
	../libpurple/protocols/silc10/util.c \
	../libpurple/protocols/silc10/wb.c \
	../libpurple/protocols/simple/simple.c \
	../libpurple/protocols/yahoo/libyahoo.c \
	../libpurple/protocols/yahoo/libyahoojp.c \
	../libpurple/protocols/yahoo/libymsg.c \
	../libpurple/protocols/yahoo/yahoo_aliases.c \
	../libpurple/protocols/yahoo/yahoo_doodle.c \
	../libpurple/protocols/yahoo/yahoo_filexfer.c \
	../libpurple/protocols/yahoo/yahoo_packet.c \
	../libpurple/protocols/yahoo/yahoo_profile.c \
	../libpurple/protocols/yahoo/yahoochat.c \
	../libpurple/protocols/yahoo/ycht.c \
	../libpurple/protocols/zephyr/zephyr.c \
	../libpurple/proxy.c \
	../libpurple/prpl.c \
	../libpurple/request.h \
	../libpurple/savedstatuses.c \
	../libpurple/server.c \
	../libpurple/smiley.c \
	../libpurple/sslconn.c \
	../libpurple/status.c \
	../libpurple/util.c \
	../libpurple/win32/libc_interface.c \
	../libpurple/xmlnode.c \
	../pidgin.desktop.in \
	../pidgin/gtkaccount.c \
	../pidgin/gtkblist-theme.c \
	../pidgin/gtkblist.c \
	../pidgin/gtkcertmgr.c \
	../pidgin/gtkconn.c \
	../pidgin/gtkconv.c \
	../pidgin/gtkdebug.c \
	../pidgin/gtkdialogs.c \
	../pidgin/gtkdocklet.c \
	../pidgin/gtkft.c \
	../pidgin/gtkimhtml.c \
	../pidgin/gtkimhtmltoolbar.c \
	../pidgin/gtklog.c \
	../pidgin/gtkmain.c \
	../pidgin/gtkmedia.c \
	../pidgin/gtknotify.c \
	../pidgin/gtkplugin.c \
	../pidgin/gtkpounce.c \
	../pidgin/gtkprefs.c \
	../pidgin/gtkprivacy.c \
	../pidgin/gtkrequest.c \
	../pidgin/gtkroomlist.c \
	../pidgin/gtksavedstatuses.c \
	../pidgin/gtksmiley.c \
	../pidgin/gtksound.c \
	../pidgin/gtkstatusbox.c \
	../pidgin/gtkutils.c \
	../pidgin/gtkwhiteboard.c \
	../pidgin/pidgin.h \
	../pidgin/pidginstock.c \
	../pidgin/pidgintooltip.c \
	../pidgin/pixmaps/emotes/default/24/default.theme.in \
	../pidgin/pixmaps/emotes/none/none.theme.in \
	../pidgin/pixmaps/emotes/small/16/small.theme.in \
	../pidgin/plugins/cap/cap.c \
	../pidgin/plugins/contact_priority.c \
	../pidgin/plugins/convcolors.c \
	../pidgin/plugins/disco/gtkdisco.c \
	../pidgin/plugins/disco/xmppdisco.c \
	../pidgin/plugins/extplacement.c \
	../pidgin/plugins/gestures/gestures.c \
	../pidgin/plugins/gevolution/add_buddy_dialog.c \
	../pidgin/plugins/gevolution/assoc-buddy.c \
	../pidgin/plugins/gevolution/eds-utils.c \
	../pidgin/plugins/gevolution/gevo-util.c \
	../pidgin/plugins/gevolution/gevolution.c \
	../pidgin/plugins/gevolution/new_person_dialog.c \
	../pidgin/plugins/gtk-signals-test.c \
	../pidgin/plugins/gtkbuddynote.c \
	../pidgin/plugins/history.c \
	../pidgin/plugins/iconaway.c \
	../pidgin/plugins/mailchk.c \
	../pidgin/plugins/markerline.c \
	../pidgin/plugins/musicmessaging/musicmessaging.c \
	../pidgin/plugins/notify.c \
	../pidgin/plugins/pidgininc.c \
	../pidgin/plugins/pidginrc.c \
	../pidgin/plugins/raw.c \
	../pidgin/plugins/relnot.c \
	../pidgin/plugins/sendbutton.c \
	../pidgin/plugins/spellchk.c \
	../pidgin/plugins/themeedit-icon.c \
	../pidgin/plugins/themeedit.c \
	../pidgin/plugins/ticker/ticker.c \
	../pidgin/plugins/timestamp.c \
	../pidgin/plugins/timestamp_format.c \
	../pidgin/plugins/vvconfig.c \
	../pidgin/plugins/win32/transparency/win2ktrans.c \
	../pidgin/plugins/win32/winprefs/winprefs.c \
	../pidgin/plugins/xmppconsole.c \
	../pidgin/win32/nsis/nsis_translations.desktop.in

CATALOGS=$(shell LINGUAS="$(USE_LINGUAS)"; for lang in $$LINGUAS; do printf "$$lang.gmo "; done)

.SUFFIXES:
.SUFFIXES: .po .pox .gmo .mo .msg .cat

.po.pox:
	$(MAKE) $(GETTEXT_PACKAGE).pot
	$(MSGMERGE) $< $(GETTEXT_PACKAGE).pot -o $*.pox

.po.mo:
	$(MSGFMT) -o $@ $<

.po.gmo:
	file=`echo $* | sed 's,.*/,,'`.gmo \
	  && rm -f $$file && $(GMSGFMT) -o $$file $<

.po.cat:
	sed -f ../intl/po2msg.sed < $< > $*.msg \
	  && rm -f $@ && gencat $@ $*.msg


all: all-yes

all-yes: $(CATALOGS)
all-no:

$(GETTEXT_PACKAGE).pot: $(POTFILES)
	$(GENPOT)

install: install-data
install-data: install-data-yes
install-data-no: all
install-data-yes: all
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  dir=$(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $$dir; \
	  if test -r $$lang.gmo; then \
	    $(INSTALL_DATA) $$lang.gmo $$dir/$(GETTEXT_PACKAGE).mo; \
	    echo "installing $$lang.gmo as $$dir/$(GETTEXT_PACKAGE).mo"; \
	  else \
	    $(INSTALL_DATA) $(srcdir)/$$lang.gmo $$dir/$(GETTEXT_PACKAGE).mo; \
	    echo "installing $(srcdir)/$$lang.gmo as" \
		 "$$dir/$(GETTEXT_PACKAGE).mo"; \
	  fi; \
	  if test -r $$lang.gmo.m; then \
	    $(INSTALL_DATA) $$lang.gmo.m $$dir/$(GETTEXT_PACKAGE).mo.m; \
	    echo "installing $$lang.gmo.m as $$dir/$(GETTEXT_PACKAGE).mo.m"; \
	  else \
	    if test -r $(srcdir)/$$lang.gmo.m ; then \
	      $(INSTALL_DATA) $(srcdir)/$$lang.gmo.m \
		$$dir/$(GETTEXT_PACKAGE).mo.m; \
	      echo "installing $(srcdir)/$$lang.gmo.m as" \
		   "$$dir/$(GETTEXT_PACKAGE).mo.m"; \
	    else \
	      true; \
	    fi; \
	  fi; \
	done

# Empty stubs to satisfy archaic automake needs
dvi info ctags tags CTAGS TAGS ID:

# Define this as empty until I found a useful application.
install-exec installcheck:

uninstall:
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  rm -f $(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES/$(GETTEXT_PACKAGE).mo; \
	  rm -f $(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES/$(GETTEXT_PACKAGE).mo.m; \
	done

check: all $(GETTEXT_PACKAGE).pot
	rm -f missing notexist
	srcdir=$(srcdir) $(INTLTOOL_UPDATE) -m
	if [ -r missing -o -r notexist ]; then \
	  exit 1; \
	fi

mostlyclean:
	rm -f *.pox $(GETTEXT_PACKAGE).pot *.old.po cat-id-tbl.tmp
	rm -f .intltool-merge-cache

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES stamp-it
	rm -f *.mo *.msg *.cat *.cat.m *.gmo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f Makefile.in.in

distdir = ../$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir: $(DISTFILES)
	dists="$(DISTFILES)"; \
	extra_dists="$(EXTRA_DISTFILES)"; \
	for file in $$extra_dists; do \
	  test -f $(srcdir)/$$file && dists="$$dists $(srcdir)/$$file"; \
	done; \
	for file in $$dists; do \
	  test -f $$file || file="$(srcdir)/$$file"; \
	  ln $$file $(distdir) 2> /dev/null \
	    || cp -p $$file $(distdir); \
	done

update-po: Makefile
	$(MAKE) $(GETTEXT_PACKAGE).pot
	tmpdir=`pwd`; \
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  echo "$$lang:"; \
	  result="`$(MSGMERGE) -o $$tmpdir/$$lang.new.po $$lang`"; \
	  if $$result; then \
	    if cmp $(srcdir)/$$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	      rm -f $$tmpdir/$$lang.new.po; \
            else \
	      if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	        :; \
	      else \
	        echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	        rm -f $$tmpdir/$$lang.new.po; \
	        exit 1; \
	      fi; \
	    fi; \
	  else \
	    echo "msgmerge for $$lang.gmo failed!"; \
	    rm -f $$tmpdir/$$lang.new.po; \
	  fi; \
	done

Makefile POTFILES: stamp-it
	@if test ! -f $@; then \
	  rm -f stamp-it; \
	  $(MAKE) stamp-it; \
	fi

stamp-it: Makefile.in.in $(top_builddir)/config.status POTFILES.in
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/Makefile.in CONFIG_HEADERS= CONFIG_LINKS= \
	       $(SHELL) ./config.status

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
