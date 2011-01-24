/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2002 from the
 * contents of GtkIMHtml.xs. Do not edit this file, edit GtkIMHtml.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "GtkIMHtml.xs"
#include "gtkmodule.h"

/* This can't work at the moment since I don't have a typemap for Gtk::Widget.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
Gtk::Widget
gtk_imhtml_new(a, b)
*/

/* This can't work at the moment since I don't have a typemap for
 * Gtk::TextIter.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
void
gtk_imhtml_insert_html_at_iter(imhtml, text, options, iter)
	Pidgin::IMHtml imhtml
	const gchar * text
	Pidgin::IMHtml::Options options
	Gtk::TextIter iter
*/

/* This can't work at the moment since I don't have a typemap for Gtk::Widget.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
void
gtk_imhtml_delete(imhtml, start, end)
	Pidgin::IMHtml imhtml
	Gtk::TextIter start
	Gtk::TextIter end
*/

/* This can't work at the moment since I don't have a typemap for Gtk::Widget.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
void
gtk_imhtml_insert_link(imhtml, mark, url, text)
	Pidgin::IMHtml imhtml
	Gtk::TextMark mark
	const char * url
	const char * text
*/

/* This can't work at the moment since I don't have a typemap for Gtk::Widget.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
void
gtk_imhtml_insert_smiley_at_iter(imhtml, sml, smiley, iter)
	Pidgin::IMHtml imhtml
	const char * sml
	char * smiley
	Gtk::TextIter iter

void
gtk_imhtml_insert_image_at_iter(imhtml, id, iter)
	Pidgin::IMHtml imhtml
	int id
	Gtk::TextIter iter
*/

/* This can't work at the moment since I don't have a typemap for Gtk::Widget.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
gchar_own *
gtk_imhtml_get_markup_range(imhtml, start, end)
	Pidgin::IMHtml imhtml
	Gtk::TextIter start
	Gtk::TextIter end
*/

/* This can't work at the moment since I don't have a typemap for Gtk::Widget.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
gchar_own *
gtk_imhtml_get_text(imhtml, start, end)
	Pidgin::IMHtml imhtml
	Gtk::TextIter start
	Gtk::TextIter end
*/

/* This can't work at the moment since I don't have a typemap for Gdk::Pixbuf.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
Pidgin::IMHtml::Scalable
gtk_imhtml_image_new(img, filename, id)
	Gdk::Pixbuf img
	const gchar * filename
	int id
*/

/* This can't work at the moment since I don't have a typemap for Gtk::Widget.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
void
gtk_imhtml_image_add_to(scale, imhtml, iter)
	Pidgin::IMHtml::Scalable scale
	Pidgin::IMHtml imhtml
	Gtk::TextIter iter
*/

/* This can't work at the moment since I don't have a typemap for Gtk::Widget.
 * I thought about using the one from libgtk2-perl but wasn't sure how to go
 * about doing that.
void
gtk_imhtml_hr_add_to(scale, imhtml, iter)
	Pidgin::IMHtml::Scalable scale
	Pidgin::IMHtml imhtml
	Gtk::TextIter iter
*/

/* This can't work at the moment since I don't have a typemap for gboolean *.
void
gtk_imhtml_get_current_format(imhtml, bold, italic, underline)
	Pidgin::IMHtml imhtml
	gboolean * bold
	gboolean * italic
	gboolean * underline
*/

#line 129 "GtkIMHtml.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
#endif

#endif

#line 172 "GtkIMHtml.c"

XS(XS_Pidgin__IMHtml_smiley_get); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_smiley_get)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "imhtml, sml, text");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const gchar *	sml = (const gchar *)SvPV_nolen(ST(1));
	const gchar *	text = (const gchar *)SvPV_nolen(ST(2));
	Pidgin__IMHtml__Smiley	RETVAL;

	RETVAL = gtk_imhtml_smiley_get(imhtml, sml, text);
	ST(0) = purple_perl_bless_object(RETVAL, "Pidgin::IMHtml::Smiley");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_associate_smiley); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_associate_smiley)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "imhtml, sml, smiley");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const gchar *	sml = (const gchar *)SvPV_nolen(ST(1));
	Pidgin__IMHtml__Smiley	smiley = purple_perl_ref_object(ST(2));

	gtk_imhtml_associate_smiley(imhtml, sml, smiley);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_remove_smileys); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_remove_smileys)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_remove_smileys(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_set_funcs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_set_funcs)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, f");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	Pidgin__IMHtml__Funcs	f = purple_perl_ref_object(ST(1));

	gtk_imhtml_set_funcs(imhtml, f);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_show_comments); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_show_comments)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, show");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gboolean	show = (bool)SvTRUE(ST(1));

	gtk_imhtml_show_comments(imhtml, show);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_get_protocol_name); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_protocol_name)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const char *	RETVAL;
	dXSTARG;

	RETVAL = gtk_imhtml_get_protocol_name(imhtml);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_set_protocol_name); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_set_protocol_name)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, protocol_name");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const gchar *	protocol_name = (const gchar *)SvPV_nolen(ST(1));

	gtk_imhtml_set_protocol_name(imhtml, protocol_name);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_append_text); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_append_text)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "imhtml, text, options");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const gchar *	text = (const gchar *)SvPV_nolen(ST(1));
	Pidgin__IMHtml__Options	options = (Pidgin__IMHtml__Options)SvIV(ST(2));

	gtk_imhtml_append_text(imhtml, text, options);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_append_text_with_images); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_append_text_with_images)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 3 || items > 4)
       croak_xs_usage(cv,  "imhtml, text, options, unused = NULL");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const gchar *	text = (const gchar *)SvPV_nolen(ST(1));
	Pidgin__IMHtml__Options	options = (Pidgin__IMHtml__Options)SvIV(ST(2));
	SV *	unused;
#line 170 "GtkIMHtml.xs"
	GSList *t_GL;
	int i, t_len;
#line 362 "GtkIMHtml.c"

	if (items < 4)
	    unused = NULL;
	else {
	    unused = ST(3);
	}
#line 173 "GtkIMHtml.xs"
	t_GL = NULL;
	t_len = av_len((AV *)SvRV(unused));

	for (i = 0; i <= t_len; i++) {
		STRLEN t_sl;
		t_GL = g_slist_append(t_GL, SvPV(*av_fetch((AV *)SvRV(unused), i, 0), t_sl));
	}
	gtk_imhtml_append_text_with_images(imhtml, text, options, t_GL);
#line 378 "GtkIMHtml.c"
	PUTBACK;
	return;
    }
}


XS(XS_Pidgin__IMHtml_scroll_to_end); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_scroll_to_end)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, smooth");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gboolean	smooth = (bool)SvTRUE(ST(1));

	gtk_imhtml_scroll_to_end(imhtml, smooth);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_clear); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_clear)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_clear(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_page_up); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_page_up)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_page_up(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_page_down); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_page_down)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_page_down(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_set_editable); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_set_editable)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, editable");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gboolean	editable = (bool)SvTRUE(ST(1));

	gtk_imhtml_set_editable(imhtml, editable);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_set_whole_buffer_formatting_only); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_set_whole_buffer_formatting_only)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, wbo");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gboolean	wbo = (bool)SvTRUE(ST(1));

	gtk_imhtml_set_whole_buffer_formatting_only(imhtml, wbo);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_set_format_functions); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_set_format_functions)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, buttons");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	Pidgin__IMHtml__Buttons	buttons = (Pidgin__IMHtml__Buttons)SvIV(ST(1));

	gtk_imhtml_set_format_functions(imhtml, buttons);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_get_format_functions); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_format_functions)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	Pidgin__IMHtml__Buttons	RETVAL;
	dXSTARG;

	RETVAL = gtk_imhtml_get_format_functions(imhtml);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_get_current_fontface); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_current_fontface)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gchar_own *	RETVAL;

	RETVAL = gtk_imhtml_get_current_fontface(imhtml);
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
	 * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
	g_free (RETVAL);

    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_get_current_forecolor); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_current_forecolor)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gchar_own *	RETVAL;

	RETVAL = gtk_imhtml_get_current_forecolor(imhtml);
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
	 * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
	g_free (RETVAL);

    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_get_current_backcolor); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_current_backcolor)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gchar_own *	RETVAL;

	RETVAL = gtk_imhtml_get_current_backcolor(imhtml);
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
	 * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
	g_free (RETVAL);

    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_get_current_background); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_current_background)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gchar_own *	RETVAL;

	RETVAL = gtk_imhtml_get_current_background(imhtml);
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
	 * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
	g_free (RETVAL);

    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_get_current_fontsize); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_current_fontsize)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gint	RETVAL;
	dXSTARG;

	RETVAL = gtk_imhtml_get_current_fontsize(imhtml);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_get_editable); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_editable)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gboolean	RETVAL;

	RETVAL = gtk_imhtml_get_editable(imhtml);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_clear_formatting); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_clear_formatting)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_clear_formatting(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_toggle_bold); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_toggle_bold)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_toggle_bold(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_toggle_italic); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_toggle_italic)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_toggle_italic(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_toggle_underline); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_toggle_underline)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_toggle_underline(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_toggle_strike); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_toggle_strike)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_toggle_strike(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_toggle_forecolor); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_toggle_forecolor)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, color");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const char *	color = (const char *)SvPV_nolen(ST(1));

	gtk_imhtml_toggle_forecolor(imhtml, color);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_toggle_backcolor); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_toggle_backcolor)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, color");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const char *	color = (const char *)SvPV_nolen(ST(1));

	gtk_imhtml_toggle_backcolor(imhtml, color);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_toggle_background); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_toggle_background)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, color");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const char *	color = (const char *)SvPV_nolen(ST(1));

	gtk_imhtml_toggle_background(imhtml, color);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_toggle_fontface); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_toggle_fontface)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, face");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const char *	face = (const char *)SvPV_nolen(ST(1));

	gtk_imhtml_toggle_fontface(imhtml, face);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_toggle_link); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_toggle_link)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, url");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const char *	url = (const char *)SvPV_nolen(ST(1));

	gtk_imhtml_toggle_link(imhtml, url);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_insert_smiley); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_insert_smiley)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "imhtml, sml, smiley");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const char *	sml = (const char *)SvPV_nolen(ST(1));
	char *	smiley = (char *)SvPV_nolen(ST(2));

	gtk_imhtml_insert_smiley(imhtml, sml, smiley);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_font_set_size); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_font_set_size)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, size");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gint	size = (gint)SvIV(ST(1));

	gtk_imhtml_font_set_size(imhtml, size);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_font_shrink); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_font_shrink)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_font_shrink(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_font_grow); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_font_grow)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_font_grow(imhtml);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml_get_markup); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_markup)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	gchar_own *	RETVAL;

	RETVAL = gtk_imhtml_get_markup(imhtml);
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
	 * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
	g_free (RETVAL);

    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml_get_markup_lines); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml_get_markup_lines)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
#line 315 "GtkIMHtml.xs"
	gint i;
	AV *lines;
	gchar **bufs;
#line 1020 "GtkIMHtml.c"
#line 319 "GtkIMHtml.xs"
	bufs = gtk_imhtml_get_markup_lines(imhtml);
	lines = newAV();
	for (i = 0; bufs[i] != NULL; i++) {
	    av_push(lines, newSVpv(bufs[i], 0));
	}
	XPUSHs(sv_2mortal(newRV_noinc((SV *)lines)));
#line 1028 "GtkIMHtml.c"
	PUTBACK;
	return;
    }
}


XS(XS_Pidgin__IMHtml__Scalable_free); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml__Scalable_free)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "scale");
    {
	Pidgin__IMHtml__Scalable	scale = purple_perl_ref_object(ST(0));

	gtk_imhtml_image_free(scale);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml__Scalable_scale); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml__Scalable_scale)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "scale, width, height");
    {
	Pidgin__IMHtml__Scalable	scale = purple_perl_ref_object(ST(0));
	int	width = (int)SvIV(ST(1));
	int	height = (int)SvIV(ST(2));

	gtk_imhtml_image_scale(scale, width, height);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml__Hr_new); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml__Hr_new)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Pidgin__IMHtml__Scalable	RETVAL;

	RETVAL = gtk_imhtml_hr_new();
	ST(0) = purple_perl_bless_object(RETVAL, "Pidgin::IMHtml::Scalable");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml__Hr_free); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml__Hr_free)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "scale");
    {
	Pidgin__IMHtml__Scalable	scale = purple_perl_ref_object(ST(0));

	gtk_imhtml_hr_free(scale);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml__Hr_scale); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml__Hr_scale)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "scale, width, height");
    {
	Pidgin__IMHtml__Scalable	scale = purple_perl_ref_object(ST(0));
	int	width = (int)SvIV(ST(1));
	int	height = (int)SvIV(ST(2));

	gtk_imhtml_hr_scale(scale, width, height);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__IMHtml__Search_find); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml__Search_find)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "imhtml, text");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));
	const gchar *	text = (const gchar *)SvPV_nolen(ST(1));
	gboolean	RETVAL;

	RETVAL = gtk_imhtml_search_find(imhtml, text);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Pidgin__IMHtml__Search_clear); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__IMHtml__Search_clear)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "imhtml");
    {
	Pidgin__IMHtml	imhtml = purple_perl_ref_object(ST(0));

	gtk_imhtml_search_clear(imhtml);
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Pidgin__IMHtml); /* prototype to pass -Wmissing-prototypes */
XS(boot_Pidgin__IMHtml)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    const char* file = __FILE__;

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
    XS_VERSION_BOOTCHECK ;

        newXSproto("Pidgin::IMHtml::smiley_get", XS_Pidgin__IMHtml_smiley_get, file, "$$$");
        newXSproto("Pidgin::IMHtml::associate_smiley", XS_Pidgin__IMHtml_associate_smiley, file, "$$$");
        newXSproto("Pidgin::IMHtml::remove_smileys", XS_Pidgin__IMHtml_remove_smileys, file, "$");
        newXSproto("Pidgin::IMHtml::set_funcs", XS_Pidgin__IMHtml_set_funcs, file, "$$");
        newXSproto("Pidgin::IMHtml::show_comments", XS_Pidgin__IMHtml_show_comments, file, "$$");
        newXSproto("Pidgin::IMHtml::get_protocol_name", XS_Pidgin__IMHtml_get_protocol_name, file, "$");
        newXSproto("Pidgin::IMHtml::set_protocol_name", XS_Pidgin__IMHtml_set_protocol_name, file, "$$");
        newXSproto("Pidgin::IMHtml::append_text", XS_Pidgin__IMHtml_append_text, file, "$$$");
        newXSproto("Pidgin::IMHtml::append_text_with_images", XS_Pidgin__IMHtml_append_text_with_images, file, "$$$;$");
        newXSproto("Pidgin::IMHtml::scroll_to_end", XS_Pidgin__IMHtml_scroll_to_end, file, "$$");
        newXSproto("Pidgin::IMHtml::clear", XS_Pidgin__IMHtml_clear, file, "$");
        newXSproto("Pidgin::IMHtml::page_up", XS_Pidgin__IMHtml_page_up, file, "$");
        newXSproto("Pidgin::IMHtml::page_down", XS_Pidgin__IMHtml_page_down, file, "$");
        newXSproto("Pidgin::IMHtml::set_editable", XS_Pidgin__IMHtml_set_editable, file, "$$");
        newXSproto("Pidgin::IMHtml::set_whole_buffer_formatting_only", XS_Pidgin__IMHtml_set_whole_buffer_formatting_only, file, "$$");
        newXSproto("Pidgin::IMHtml::set_format_functions", XS_Pidgin__IMHtml_set_format_functions, file, "$$");
        newXSproto("Pidgin::IMHtml::get_format_functions", XS_Pidgin__IMHtml_get_format_functions, file, "$");
        newXSproto("Pidgin::IMHtml::get_current_fontface", XS_Pidgin__IMHtml_get_current_fontface, file, "$");
        newXSproto("Pidgin::IMHtml::get_current_forecolor", XS_Pidgin__IMHtml_get_current_forecolor, file, "$");
        newXSproto("Pidgin::IMHtml::get_current_backcolor", XS_Pidgin__IMHtml_get_current_backcolor, file, "$");
        newXSproto("Pidgin::IMHtml::get_current_background", XS_Pidgin__IMHtml_get_current_background, file, "$");
        newXSproto("Pidgin::IMHtml::get_current_fontsize", XS_Pidgin__IMHtml_get_current_fontsize, file, "$");
        newXSproto("Pidgin::IMHtml::get_editable", XS_Pidgin__IMHtml_get_editable, file, "$");
        newXSproto("Pidgin::IMHtml::clear_formatting", XS_Pidgin__IMHtml_clear_formatting, file, "$");
        newXSproto("Pidgin::IMHtml::toggle_bold", XS_Pidgin__IMHtml_toggle_bold, file, "$");
        newXSproto("Pidgin::IMHtml::toggle_italic", XS_Pidgin__IMHtml_toggle_italic, file, "$");
        newXSproto("Pidgin::IMHtml::toggle_underline", XS_Pidgin__IMHtml_toggle_underline, file, "$");
        newXSproto("Pidgin::IMHtml::toggle_strike", XS_Pidgin__IMHtml_toggle_strike, file, "$");
        newXSproto("Pidgin::IMHtml::toggle_forecolor", XS_Pidgin__IMHtml_toggle_forecolor, file, "$$");
        newXSproto("Pidgin::IMHtml::toggle_backcolor", XS_Pidgin__IMHtml_toggle_backcolor, file, "$$");
        newXSproto("Pidgin::IMHtml::toggle_background", XS_Pidgin__IMHtml_toggle_background, file, "$$");
        newXSproto("Pidgin::IMHtml::toggle_fontface", XS_Pidgin__IMHtml_toggle_fontface, file, "$$");
        newXSproto("Pidgin::IMHtml::toggle_link", XS_Pidgin__IMHtml_toggle_link, file, "$$");
        newXSproto("Pidgin::IMHtml::insert_smiley", XS_Pidgin__IMHtml_insert_smiley, file, "$$$");
        newXSproto("Pidgin::IMHtml::font_set_size", XS_Pidgin__IMHtml_font_set_size, file, "$$");
        newXSproto("Pidgin::IMHtml::font_shrink", XS_Pidgin__IMHtml_font_shrink, file, "$");
        newXSproto("Pidgin::IMHtml::font_grow", XS_Pidgin__IMHtml_font_grow, file, "$");
        newXSproto("Pidgin::IMHtml::get_markup", XS_Pidgin__IMHtml_get_markup, file, "$");
        newXSproto("Pidgin::IMHtml::get_markup_lines", XS_Pidgin__IMHtml_get_markup_lines, file, "$");
        newXSproto("Pidgin::IMHtml::Scalable::free", XS_Pidgin__IMHtml__Scalable_free, file, "$");
        newXSproto("Pidgin::IMHtml::Scalable::scale", XS_Pidgin__IMHtml__Scalable_scale, file, "$$$");
        newXSproto("Pidgin::IMHtml::Hr::new", XS_Pidgin__IMHtml__Hr_new, file, "");
        newXSproto("Pidgin::IMHtml::Hr::free", XS_Pidgin__IMHtml__Hr_free, file, "$");
        newXSproto("Pidgin::IMHtml::Hr::scale", XS_Pidgin__IMHtml__Hr_scale, file, "$$$");
        newXSproto("Pidgin::IMHtml::Search::find", XS_Pidgin__IMHtml__Search_find, file, "$$");
        newXSproto("Pidgin::IMHtml::Search::clear", XS_Pidgin__IMHtml__Search_clear, file, "$");
    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}

