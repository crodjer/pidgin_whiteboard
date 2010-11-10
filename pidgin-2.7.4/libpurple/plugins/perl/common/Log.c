/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2002 from the
 * contents of Log.xs. Do not edit this file, edit Log.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "Log.xs"
#include "module.h"

#line 13 "Log.c"
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

#line 56 "Log.c"

XS(XS_Purple__Log_get_handle); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_get_handle)
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

	RETVAL = purple_log_get_handle();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Handle");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Purple__Log_common_sizer); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_common_sizer)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "log");
    {
	Purple__Log	log = purple_perl_ref_object(ST(0));
	int	RETVAL;
	dXSTARG;

	RETVAL = purple_log_common_sizer(log);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Purple__Log_common_writer); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_common_writer)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "log, ext");
    {
	Purple__Log	log = purple_perl_ref_object(ST(0));
	const char *	ext = (const char *)SvPV_nolen(ST(1));

	purple_log_common_writer(log, ext);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Log_compare); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_compare)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "y, z");
    {
	gconstpointer	y = INT2PTR(gconstpointer,SvIV(ST(0)));
	gconstpointer	z = INT2PTR(gconstpointer,SvIV(ST(1)));
	gint	RETVAL;
	dXSTARG;

	RETVAL = purple_log_compare(y, z);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Purple__Log_free); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_free)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "log");
    {
	Purple__Log	log = purple_perl_ref_object(ST(0));

	purple_log_free(log);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Log_get_log_dir); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_get_log_dir)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "type, name, account");
    {
	Purple__LogType	type = (Purple__LogType)SvIV(ST(0));
	const char *	name = (const char *)SvPV_nolen(ST(1));
	Purple__Account	account = purple_perl_ref_object(ST(2));
	gchar_own *	RETVAL;

	RETVAL = purple_log_get_log_dir(type, name, account);
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


XS(XS_Purple__Log_get_log_sets); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_get_log_sets)
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
#line 60 "Log.xs"
	GHashTable *l;
#line 209 "Log.c"
#line 62 "Log.xs"
	l = purple_log_get_log_sets();
	XPUSHs(sv_2mortal(purple_perl_bless_object(l, "GHashTable")));
#line 213 "Log.c"
	PUTBACK;
	return;
    }
}


XS(XS_Purple__Log_get_logs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_get_logs)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "type, name, account");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__LogType	type = (Purple__LogType)SvIV(ST(0));
	const char *	name = (const char *)SvPV_nolen(ST(1));
	Purple__Account	account = purple_perl_ref_object(ST(2));
#line 71 "Log.xs"
	GList *l, *ll;
#line 238 "Log.c"
#line 73 "Log.xs"
	ll = purple_log_get_logs(type, name, account);
	for (l = ll; l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::Log")));
	}
	/* We can free the list here but the script needs to free the
	 * Purple::Log 'objects' itself. */
	g_list_free(ll);
#line 247 "Log.c"
	PUTBACK;
	return;
    }
}


XS(XS_Purple__Log_get_size); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_get_size)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "log");
    {
	Purple__Log	log = purple_perl_ref_object(ST(0));
	int	RETVAL;
	dXSTARG;

	RETVAL = purple_log_get_size(log);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Purple__Log_get_system_logs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_get_system_logs)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "account");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Account	account = purple_perl_ref_object(ST(0));
#line 89 "Log.xs"
	GList *l, *ll;
#line 292 "Log.c"
#line 91 "Log.xs"
	ll = purple_log_get_system_logs(account);
	for (l = ll; l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::Log")));
	}
	/* We can free the list here but the script needs to free the
	 * Purple::Log 'objects' itself. */
	g_list_free(ll);
#line 301 "Log.c"
	PUTBACK;
	return;
    }
}


XS(XS_Purple__Log_get_total_size); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_get_total_size)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "type, name, account");
    {
	Purple__LogType	type = (Purple__LogType)SvIV(ST(0));
	const char *	name = (const char *)SvPV_nolen(ST(1));
	Purple__Account	account = purple_perl_ref_object(ST(2));
	int	RETVAL;
	dXSTARG;

	RETVAL = purple_log_get_total_size(type, name, account);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Purple__Log_logger_free); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_logger_free)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "logger");
    {
	Purple__Log__Logger	logger = purple_perl_ref_object(ST(0));

	purple_log_logger_free(logger);
    }
    XSRETURN_EMPTY;
}


XS(XS_Purple__Log_logger_get_options); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_logger_get_options)
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
#line 112 "Log.xs"
	GList *l, *ll;
#line 366 "Log.c"
#line 114 "Log.xs"
	/* This might want to be massaged to a hash, since that's essentially
	 * what the key/value list is emulating. */
	for (l = ll = purple_log_logger_get_options(); l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(newSVpv(l->data, 0)));
	}
	g_list_free(ll);
#line 374 "Log.c"
	PUTBACK;
	return;
    }
}


XS(XS_Purple__Log_read); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_read)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "log, flags");
    {
	Purple__Log	log = purple_perl_ref_object(ST(0));
	Purple__Log__ReadFlags	flags = purple_perl_ref_object(ST(1));
	gchar_own *	RETVAL;

	RETVAL = purple_log_read(log, flags);
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


XS(XS_Purple__Log_set_compare); /* prototype to pass -Wmissing-prototypes */
XS(XS_Purple__Log_set_compare)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "y, z");
    {
	gconstpointer	y = INT2PTR(gconstpointer,SvIV(ST(0)));
	gconstpointer	z = INT2PTR(gconstpointer,SvIV(ST(1)));
	gint	RETVAL;
	dXSTARG;

	RETVAL = purple_log_set_compare(y, z);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Purple__Log); /* prototype to pass -Wmissing-prototypes */
XS(boot_Purple__Log)
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

        newXSproto("Purple::Log::get_handle", XS_Purple__Log_get_handle, file, "");
        newXSproto("Purple::Log::common_sizer", XS_Purple__Log_common_sizer, file, "$");
        newXSproto("Purple::Log::common_writer", XS_Purple__Log_common_writer, file, "$$");
        newXSproto("Purple::Log::compare", XS_Purple__Log_compare, file, "$$");
        newXSproto("Purple::Log::free", XS_Purple__Log_free, file, "$");
        newXSproto("Purple::Log::get_log_dir", XS_Purple__Log_get_log_dir, file, "$$$");
        newXSproto("Purple::Log::get_log_sets", XS_Purple__Log_get_log_sets, file, "");
        newXSproto("Purple::Log::get_logs", XS_Purple__Log_get_logs, file, "$$$");
        newXSproto("Purple::Log::get_size", XS_Purple__Log_get_size, file, "$");
        newXSproto("Purple::Log::get_system_logs", XS_Purple__Log_get_system_logs, file, "$");
        newXSproto("Purple::Log::get_total_size", XS_Purple__Log_get_total_size, file, "$$$");
        newXSproto("Purple::Log::logger_free", XS_Purple__Log_logger_free, file, "$");
        newXSproto("Purple::Log::logger_get_options", XS_Purple__Log_logger_get_options, file, "");
        newXSproto("Purple::Log::read", XS_Purple__Log_read, file, "$$");
        newXSproto("Purple::Log::set_compare", XS_Purple__Log_set_compare, file, "$$");

    /* Initialisation Section */

#line 7 "Log.xs"
{
	HV *type_stash = gv_stashpv("Purple::Log::Type", 1);
	HV *flags_stash = gv_stashpv("Purple::Log::ReadFlags", 1);

	static const constiv *civ, type_const_iv[] = {
#define const_iv(name) {#name, (IV)PURPLE_LOG_##name}
		const_iv(IM),
		const_iv(CHAT),
		const_iv(SYSTEM),
	};
	static const constiv flags_const_iv[] = {
#undef const_iv
#define const_iv(name) {#name, (IV)PURPLE_LOG_READ_##name}
		const_iv(NO_NEWLINE),
	};

	for (civ = type_const_iv + sizeof(type_const_iv) / sizeof(type_const_iv[0]); civ-- > type_const_iv; )
		newCONSTSUB(type_stash, (char *)civ->name, newSViv(civ->iv));

	for (civ = flags_const_iv + sizeof(flags_const_iv) / sizeof(flags_const_iv[0]); civ-- > flags_const_iv; )
		newCONSTSUB(flags_stash, (char *)civ->name, newSViv(civ->iv));
}

#line 491 "Log.c"

    /* End of Initialisation Section */

    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}

