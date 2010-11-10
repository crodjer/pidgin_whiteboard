/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2002 from the
 * contents of PluginPref.xs. Do not edit this file, edit PluginPref.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "PluginPref.xs"
#include "module.h"

#line 13 "PluginPref.c"
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

#line 56 "PluginPref.c"

XS(XS_Purple__PluginPref__Frame_add); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref__Frame_add)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "frame, pref");
    {
	Purple__PluginPref__Frame	frame = purple_perl_ref_object(ST(0));
	Purple__PluginPref	pref = purple_perl_ref_object(ST(1));

	purple_plugin_pref_frame_add(frame, pref);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref__Frame_destroy); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref__Frame_destroy)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "frame");
    {
	Purple__PluginPref__Frame	frame = purple_perl_ref_object(ST(0));

	purple_plugin_pref_frame_destroy(frame);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref__Frame_get_prefs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref__Frame_get_prefs)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "frame");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__PluginPref__Frame	frame = purple_perl_ref_object(ST(0));
#line 46 "PluginPref.xs"
	GList *l;
#line 113 "PluginPref.c"
#line 48 "PluginPref.xs"
	for (l = purple_plugin_pref_frame_get_prefs(frame); l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::PluginPref")));
	}
#line 118 "PluginPref.c"
	PUTBACK;
	return;
    }
}


XS(XS_Purple__PluginPref__Frame_new); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref__Frame_new)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	Purple__PluginPref__Frame	RETVAL;

	RETVAL = purple_plugin_pref_frame_new(/* void */);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::PluginPref::Frame");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_add_choice); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_add_choice)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "pref, label, choice");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	const char *	label = (const char *)SvPV_nolen(ST(1));
	gpointer	choice = (SvPOKp(ST(2)) ? SvPVutf8_nolen(ST(2)) : (SvIOKp(ST(2)) ? GINT_TO_POINTER(SvIV(ST(2))) : NULL));

	purple_plugin_pref_add_choice(pref, label, choice);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref_destroy); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_destroy)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "pref");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));

	purple_plugin_pref_destroy(pref);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref_get_bounds); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_get_bounds)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "pref");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	int	min;
	int	max;

	purple_plugin_pref_get_bounds(pref, &min, &max);
	XSprePUSH;	EXTEND(SP,2);
	PUSHs(sv_newmortal());
	sv_setiv(ST(0), (IV)min);
	PUSHs(sv_newmortal());
	sv_setiv(ST(1), (IV)max);
    }
    XSRETURN(2);
}


XS(XS_Purple__PluginPref_get_choices); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_get_choices)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "pref");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
#line 88 "PluginPref.xs"
	GList *l;
#line 229 "PluginPref.c"
#line 90 "PluginPref.xs"
	for (l = purple_plugin_pref_get_choices(pref); l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::ListItem")));
	}
#line 234 "PluginPref.c"
	PUTBACK;
	return;
    }
}


XS(XS_Purple__PluginPref_get_label); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_get_label)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "pref");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_pref_get_label(pref);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_get_masked); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_get_masked)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "pref");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	gboolean	RETVAL;

	RETVAL = purple_plugin_pref_get_masked(pref);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_get_format_type); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_get_format_type)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "pref");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	Purple__String__Format__Type	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_pref_get_format_type(pref);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_get_max_length); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_get_max_length)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "pref");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	unsigned int	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_pref_get_max_length(pref);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_get_name); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_get_name)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "pref");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_pref_get_name(pref);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_get_type); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_get_type)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "pref");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	Purple__PluginPrefType	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_pref_get_type(pref);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_new); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_new)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	Purple__PluginPref	RETVAL;

	RETVAL = purple_plugin_pref_new(/* void */);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::PluginPref");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_new_with_label); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_new_with_label)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, label");
    {
	const char *	label = (const char *)SvPV_nolen(ST(1));
	Purple__PluginPref	RETVAL;

	RETVAL = purple_plugin_pref_new_with_label(label);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::PluginPref");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_new_with_name); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_new_with_name)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, name");
    {
	const char *	name = (const char *)SvPV_nolen(ST(1));
	Purple__PluginPref	RETVAL;

	RETVAL = purple_plugin_pref_new_with_name(name);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::PluginPref");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_new_with_name_and_label); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_new_with_name_and_label)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "class, name, label");
    {
	const char *	name = (const char *)SvPV_nolen(ST(1));
	const char *	label = (const char *)SvPV_nolen(ST(2));
	Purple__PluginPref	RETVAL;

	RETVAL = purple_plugin_pref_new_with_name_and_label(name, label);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::PluginPref");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__PluginPref_set_bounds); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_set_bounds)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "pref, min, max");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	int	min = (int)SvIV(ST(1));
	int	max = (int)SvIV(ST(2));

	purple_plugin_pref_set_bounds(pref, min, max);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref_set_label); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_set_label)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "pref, label");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	const char *	label = (const char *)SvPV_nolen(ST(1));

	purple_plugin_pref_set_label(pref, label);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref_set_masked); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_set_masked)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "pref, mask");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	gboolean	mask = (bool)SvTRUE(ST(1));

	purple_plugin_pref_set_masked(pref, mask);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref_set_format_type); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_set_format_type)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "pref, format");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	Purple__String__Format__Type	format = (Purple__String__Format__Type)SvIV(ST(1));

	purple_plugin_pref_set_format_type(pref, format);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref_set_max_length); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_set_max_length)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "pref, max_length");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	unsigned int	max_length = (unsigned int)SvUV(ST(1));

	purple_plugin_pref_set_max_length(pref, max_length);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref_set_name); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_set_name)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "pref, name");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	const char *	name = (const char *)SvPV_nolen(ST(1));

	purple_plugin_pref_set_name(pref, name);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__PluginPref_set_type); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__PluginPref_set_type)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "pref, type");
    {
	Purple__PluginPref	pref = purple_perl_ref_object(ST(0));
	Purple__PluginPrefType	type = (Purple__PluginPrefType)SvIV(ST(1));
#line 177 "PluginPref.xs"
	PurplePluginPrefType gpp_type;
#line 601 "PluginPref.c"
#line 179 "PluginPref.xs"
	gpp_type = PURPLE_PLUGIN_PREF_NONE;

	if (type == 1) {
		gpp_type = PURPLE_PLUGIN_PREF_CHOICE;
	} else if (type == 2) {
		gpp_type = PURPLE_PLUGIN_PREF_INFO;
	} else if (type == 3) {
		gpp_type = PURPLE_PLUGIN_PREF_STRING_FORMAT;
	}
	purple_plugin_pref_set_type(pref, gpp_type);
#line 613 "PluginPref.c"
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Purple__PluginPref); /* prototype to pass -Wmissing-prototypes */
XS(boot_Purple__PluginPref)
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

        newXSproto("Purple::PluginPref::Frame::add", XS_Purple__PluginPref__Frame_add, file, "$$");
        newXSproto("Purple::PluginPref::Frame::destroy", XS_Purple__PluginPref__Frame_destroy, file, "$");
        newXSproto("Purple::PluginPref::Frame::get_prefs", XS_Purple__PluginPref__Frame_get_prefs, file, "$");
        newXSproto("Purple::PluginPref::Frame::new", XS_Purple__PluginPref__Frame_new, file, "$");
        newXSproto("Purple::PluginPref::add_choice", XS_Purple__PluginPref_add_choice, file, "$$$");
        newXSproto("Purple::PluginPref::destroy", XS_Purple__PluginPref_destroy, file, "$");
        newXSproto("Purple::PluginPref::get_bounds", XS_Purple__PluginPref_get_bounds, file, "$");
        newXSproto("Purple::PluginPref::get_choices", XS_Purple__PluginPref_get_choices, file, "$");
        newXSproto("Purple::PluginPref::get_label", XS_Purple__PluginPref_get_label, file, "$");
        newXSproto("Purple::PluginPref::get_masked", XS_Purple__PluginPref_get_masked, file, "$");
        newXSproto("Purple::PluginPref::get_format_type", XS_Purple__PluginPref_get_format_type, file, "$");
        newXSproto("Purple::PluginPref::get_max_length", XS_Purple__PluginPref_get_max_length, file, "$");
        newXSproto("Purple::PluginPref::get_name", XS_Purple__PluginPref_get_name, file, "$");
        newXSproto("Purple::PluginPref::get_type", XS_Purple__PluginPref_get_type, file, "$");
        newXSproto("Purple::PluginPref::new", XS_Purple__PluginPref_new, file, "$");
        newXSproto("Purple::PluginPref::new_with_label", XS_Purple__PluginPref_new_with_label, file, "$$");
        newXSproto("Purple::PluginPref::new_with_name", XS_Purple__PluginPref_new_with_name, file, "$$");
        newXSproto("Purple::PluginPref::new_with_name_and_label", XS_Purple__PluginPref_new_with_name_and_label, file, "$$$");
        newXSproto("Purple::PluginPref::set_bounds", XS_Purple__PluginPref_set_bounds, file, "$$$");
        newXSproto("Purple::PluginPref::set_label", XS_Purple__PluginPref_set_label, file, "$$");
        newXSproto("Purple::PluginPref::set_masked", XS_Purple__PluginPref_set_masked, file, "$$");
        newXSproto("Purple::PluginPref::set_format_type", XS_Purple__PluginPref_set_format_type, file, "$$");
        newXSproto("Purple::PluginPref::set_max_length", XS_Purple__PluginPref_set_max_length, file, "$$");
        newXSproto("Purple::PluginPref::set_name", XS_Purple__PluginPref_set_name, file, "$$");
        newXSproto("Purple::PluginPref::set_type", XS_Purple__PluginPref_set_type, file, "$$");

    /* Initialisation Section */

#line 7 "PluginPref.xs"
{
	HV *string_format_stash = gv_stashpv("Purple::String::Format::Type", 1);
	HV *plugin_pref_stash = gv_stashpv("Purple::PluginPref::Type", 1);

	static const constiv *civ, string_format_const_iv[] = {
#define const_iv(name) {#name, (IV)PURPLE_STRING_FORMAT_TYPE_##name}
		const_iv(NONE),
		const_iv(MULTILINE),
		const_iv(HTML),
	};
	static const constiv plugin_pref_const_iv[] = {
#undef const_iv
#define const_iv(name) {#name, (IV)PURPLE_PLUGIN_PREF_##name}
		const_iv(NONE),
		const_iv(CHOICE),
		const_iv(INFO),
		const_iv(STRING_FORMAT),
	};

	for (civ = string_format_const_iv + sizeof(string_format_const_iv) / sizeof(string_format_const_iv[0]); civ-- > string_format_const_iv; )
		newCONSTSUB(string_format_stash, (char *)civ->name, newSViv(civ->iv));

	for (civ = plugin_pref_const_iv + sizeof(plugin_pref_const_iv) / sizeof(plugin_pref_const_iv[0]); civ-- > plugin_pref_const_iv; )
		newCONSTSUB(plugin_pref_stash, (char *)civ->name, newSViv(civ->iv));
}

#line 690 "PluginPref.c"

    /* End of Initialisation Section */

    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}

