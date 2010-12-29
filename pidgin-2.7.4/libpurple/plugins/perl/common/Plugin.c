/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2002 from the
 * contents of Plugin.xs. Do not edit this file, edit Plugin.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "Plugin.xs"
#include "module.h"

#line 13 "Plugin.c"
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

#line 56 "Plugin.c"

XS(XS_Purple__Plugin_new); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_new)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "native, path");
    {
	gboolean	native = (bool)SvTRUE(ST(0));
	const char *	path = (const char *)SvPV_nolen(ST(1));
	Purple__Plugin	RETVAL;

	RETVAL = purple_plugin_new(native, path);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Plugin");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_probe); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_probe)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "filename");
    {
	const char *	filename = (const char *)SvPV_nolen(ST(0));
	Purple__Plugin	RETVAL;

	RETVAL = purple_plugin_probe(filename);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Plugin");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_register); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_register)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	gboolean	RETVAL;

	RETVAL = purple_plugin_register(plugin);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_load); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_load)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	gboolean	RETVAL;

	RETVAL = purple_plugin_load(plugin);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_unload); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_unload)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	gboolean	RETVAL;

	RETVAL = purple_plugin_unload(plugin);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_reload); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_reload)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	gboolean	RETVAL;

	RETVAL = purple_plugin_reload(plugin);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_destroy); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_destroy)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));

	purple_plugin_destroy(plugin);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Plugin_is_loaded); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_is_loaded)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	gboolean	RETVAL;

	RETVAL = purple_plugin_is_loaded(plugin);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_is_unloadable); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_is_unloadable)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	gboolean	RETVAL;

	RETVAL = purple_plugin_is_unloadable(plugin);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_get_id); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_get_id)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	const gchar *	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_get_id(plugin);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_get_name); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_get_name)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	const gchar *	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_get_name(plugin);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_get_version); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_get_version)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	const gchar *	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_get_version(plugin);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_get_summary); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_get_summary)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	const gchar *	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_get_summary(plugin);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_get_description); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_get_description)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	const gchar *	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_get_description(plugin);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_get_author); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_get_author)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	const gchar *	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_get_author(plugin);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin_get_homepage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin_get_homepage)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	const gchar *	RETVAL;
	dXSTARG;

	RETVAL = purple_plugin_get_homepage(plugin);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugin__IPC_unregister); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin__IPC_unregister)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "plugin, command");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));
	const char *	command = (const char *)SvPV_nolen(ST(1));

	purple_plugin_ipc_unregister(plugin, command);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Plugin__IPC_unregister_all); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugin__IPC_unregister_all)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "plugin");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0));

	purple_plugin_ipc_unregister_all(plugin);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Plugins_add_search_path); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_add_search_path)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "path");
    {
	const char *	path = (const char *)SvPV_nolen(ST(0));

	purple_plugins_add_search_path(path);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Plugins_unload_all); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_unload_all)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	purple_plugins_unload_all();
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Plugins_destroy_all); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_destroy_all)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	purple_plugins_destroy_all();
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Plugins_load_saved); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_load_saved)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "key");
    {
	const char *	key = (const char *)SvPV_nolen(ST(0));

	purple_plugins_load_saved(key);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Plugins_probe); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_probe)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "ext");
    {
	const char *	ext = (const char *)SvPV_nolen(ST(0));

	purple_plugins_probe(ext);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Plugins_enabled); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_enabled)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	gboolean	RETVAL;

	RETVAL = purple_plugins_enabled();
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugins_find_with_name); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_find_with_name)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "name");
    {
	const char *	name = (const char *)SvPV_nolen(ST(0));
	Purple__Plugin	RETVAL;

	RETVAL = purple_plugins_find_with_name(name);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Plugin");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugins_find_with_filename); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_find_with_filename)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "filename");
    {
	const char *	filename = (const char *)SvPV_nolen(ST(0));
	Purple__Plugin	RETVAL;

	RETVAL = purple_plugins_find_with_filename(filename);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Plugin");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugins_find_with_basename); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_find_with_basename)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "basename");
    {
	const char *	basename = (const char *)SvPV_nolen(ST(0));
	Purple__Plugin	RETVAL;

	RETVAL = purple_plugins_find_with_basename(basename);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Plugin");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugins_find_with_id); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_find_with_id)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "id");
    {
	const char *	id = (const char *)SvPV_nolen(ST(0));
	Purple__Plugin	RETVAL;

	RETVAL = purple_plugins_find_with_id(id);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Plugin");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Plugins_get_loaded); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_get_loaded)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 141 "Plugin.xs"
	GList *l;
#line 670 "Plugin.c"
#line 143 "Plugin.xs"
	for (l = purple_plugins_get_loaded(); l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::Plugin")));
	}
#line 675 "Plugin.c"
	PUTBACK;
	return;
    }
}


XS(XS_Purple__Plugins_get_protocols); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_get_protocols)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 150 "Plugin.xs"
	GList *l;
#line 697 "Plugin.c"
#line 152 "Plugin.xs"
	for (l = purple_plugins_get_protocols(); l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::Plugin")));
	}
#line 702 "Plugin.c"
	PUTBACK;
	return;
    }
}


XS(XS_Purple__Plugins_get_all); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_get_all)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 159 "Plugin.xs"
	GList *l;
#line 724 "Plugin.c"
#line 161 "Plugin.xs"
	for (l = purple_plugins_get_all(); l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::Plugin")));
	}
#line 729 "Plugin.c"
	PUTBACK;
	return;
    }
}


XS(XS_Purple__Plugins_get_handle); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Plugins_get_handle)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__Handle	RETVAL;

	RETVAL = purple_plugins_get_handle();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Handle");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Purple__Plugin); /* prototype to pass -Wmissing-prototypes */
XS(boot_Purple__Plugin)
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

        newXSproto("Purple::Plugin::new", XS_Purple__Plugin_new, file, "$$");
        newXSproto("Purple::Plugin::probe", XS_Purple__Plugin_probe, file, "$");
        newXSproto("Purple::Plugin::register", XS_Purple__Plugin_register, file, "$");
        newXSproto("Purple::Plugin::load", XS_Purple__Plugin_load, file, "$");
        newXSproto("Purple::Plugin::unload", XS_Purple__Plugin_unload, file, "$");
        newXSproto("Purple::Plugin::reload", XS_Purple__Plugin_reload, file, "$");
        newXSproto("Purple::Plugin::destroy", XS_Purple__Plugin_destroy, file, "$");
        newXSproto("Purple::Plugin::is_loaded", XS_Purple__Plugin_is_loaded, file, "$");
        newXSproto("Purple::Plugin::is_unloadable", XS_Purple__Plugin_is_unloadable, file, "$");
        newXSproto("Purple::Plugin::get_id", XS_Purple__Plugin_get_id, file, "$");
        newXSproto("Purple::Plugin::get_name", XS_Purple__Plugin_get_name, file, "$");
        newXSproto("Purple::Plugin::get_version", XS_Purple__Plugin_get_version, file, "$");
        newXSproto("Purple::Plugin::get_summary", XS_Purple__Plugin_get_summary, file, "$");
        newXSproto("Purple::Plugin::get_description", XS_Purple__Plugin_get_description, file, "$");
        newXSproto("Purple::Plugin::get_author", XS_Purple__Plugin_get_author, file, "$");
        newXSproto("Purple::Plugin::get_homepage", XS_Purple__Plugin_get_homepage, file, "$");
        newXSproto("Purple::Plugin::IPC::unregister", XS_Purple__Plugin__IPC_unregister, file, "$$");
        newXSproto("Purple::Plugin::IPC::unregister_all", XS_Purple__Plugin__IPC_unregister_all, file, "$");
        newXSproto("Purple::Plugins::add_search_path", XS_Purple__Plugins_add_search_path, file, "$");
        newXSproto("Purple::Plugins::unload_all", XS_Purple__Plugins_unload_all, file, "");
        newXSproto("Purple::Plugins::destroy_all", XS_Purple__Plugins_destroy_all, file, "");
        newXSproto("Purple::Plugins::load_saved", XS_Purple__Plugins_load_saved, file, "$");
        newXSproto("Purple::Plugins::probe", XS_Purple__Plugins_probe, file, "$");
        newXSproto("Purple::Plugins::enabled", XS_Purple__Plugins_enabled, file, "");
        newXSproto("Purple::Plugins::find_with_name", XS_Purple__Plugins_find_with_name, file, "$");
        newXSproto("Purple::Plugins::find_with_filename", XS_Purple__Plugins_find_with_filename, file, "$");
        newXSproto("Purple::Plugins::find_with_basename", XS_Purple__Plugins_find_with_basename, file, "$");
        newXSproto("Purple::Plugins::find_with_id", XS_Purple__Plugins_find_with_id, file, "$");
        newXSproto("Purple::Plugins::get_loaded", XS_Purple__Plugins_get_loaded, file, "");
        newXSproto("Purple::Plugins::get_protocols", XS_Purple__Plugins_get_protocols, file, "");
        newXSproto("Purple::Plugins::get_all", XS_Purple__Plugins_get_all, file, "");
        newXSproto("Purple::Plugins::get_handle", XS_Purple__Plugins_get_handle, file, "");

    /* Initialisation Section */

#line 7 "Plugin.xs"
{
	HV *stash = gv_stashpv("Purple::Plugin::Type", 1);

	static const constiv *civ, const_iv[] = {
#define const_iv(name) {#name, (IV)PURPLE_PLUGIN_##name}
		const_iv(UNKNOWN),
		const_iv(STANDARD),
		const_iv(LOADER),
		const_iv(PROTOCOL),
	};

	for (civ = const_iv + sizeof(const_iv) / sizeof(const_iv[0]); civ-- > const_iv; )
		newCONSTSUB(stash, (char *)civ->name, newSViv(civ->iv));
}

#line 825 "Plugin.c"

    /* End of Initialisation Section */

    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}

