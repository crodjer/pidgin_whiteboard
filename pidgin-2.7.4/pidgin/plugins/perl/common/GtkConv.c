/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2002 from the
 * contents of GtkConv.xs. Do not edit this file, edit GtkConv.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "GtkConv.xs"
#include "gtkmodule.h"

#line 13 "GtkConv.c"
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

#line 56 "GtkConv.c"

XS(XS_Pidgin__Conversation_update_buddy_icon); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversation_update_buddy_icon)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0));

	pidgin_conv_update_buddy_icon(conv);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__Conversation_switch_active_conversation); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversation_switch_active_conversation)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0));

	pidgin_conv_switch_active_conversation(conv);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__Conversation_update_buttons_by_protocol); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversation_update_buttons_by_protocol)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0));

	pidgin_conv_update_buttons_by_protocol(conv);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__Conversation_present_conversation); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversation_present_conversation)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0));

	pidgin_conv_present_conversation(conv);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__Conversation_get_window); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversation_get_window)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Pidgin__Conversation	conv = purple_perl_ref_object(ST(0));
	Pidgin__Conversation__Window	RETVAL;

	RETVAL = pidgin_conv_get_window(conv);
	ST(0) = purple_perl_bless_object(RETVAL, "Pidgin::Conversation::Window");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Pidgin__Conversation_new); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversation_new)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(1));

	pidgin_conv_new(conv);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__Conversation_is_hidden); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversation_is_hidden)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "gtkconv");
    {
	Pidgin__Conversation	gtkconv = purple_perl_ref_object(ST(0));
	gboolean	RETVAL;

	RETVAL = pidgin_conv_is_hidden(gtkconv);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Pidgin__Conversation_get_gtkconv); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversation_get_gtkconv)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0));
#line 40 "GtkConv.xs"
	if (conv != NULL && PIDGIN_IS_PIDGIN_CONVERSATION(conv))
		XPUSHs(sv_2mortal(purple_perl_bless_object(
				PIDGIN_CONVERSATION(conv),
				"Pidgin::Conversation")));
#line 217 "GtkConv.c"
	PUTBACK;
	return;
    }
}


XS(XS_Pidgin__Conversations_find_unseen_list); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversations_find_unseen_list)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 4)
       croak_xs_usage(cv,  "type, min_state, hidden_only, max_count");
    {
	Purple__ConversationType	type = (Purple__ConversationType)SvIV(ST(0));
	Pidgin__UnseenState	min_state = (Pidgin__UnseenState)SvIV(ST(1));
	gboolean	hidden_only = (bool)SvTRUE(ST(2));
	guint	max_count = (guint)SvIV(ST(3));

	pidgin_conversations_find_unseen_list(type, min_state, hidden_only, max_count);
    }
    XSRETURN_EMPTY;
}


XS(XS_Pidgin__Conversations_get_handle); /* prototype to pass -Wmissing-prototypes */
XS(XS_Pidgin__Conversations_get_handle)
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

	RETVAL = pidgin_conversations_get_handle();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Handle");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Pidgin__Conversation); /* prototype to pass -Wmissing-prototypes */
XS(boot_Pidgin__Conversation)
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

        newXSproto("Pidgin::Conversation::update_buddy_icon", XS_Pidgin__Conversation_update_buddy_icon, file, "$");
        newXSproto("Pidgin::Conversation::switch_active_conversation", XS_Pidgin__Conversation_switch_active_conversation, file, "$");
        newXSproto("Pidgin::Conversation::update_buttons_by_protocol", XS_Pidgin__Conversation_update_buttons_by_protocol, file, "$");
        newXSproto("Pidgin::Conversation::present_conversation", XS_Pidgin__Conversation_present_conversation, file, "$");
        newXSproto("Pidgin::Conversation::get_window", XS_Pidgin__Conversation_get_window, file, "$");
        newXSproto("Pidgin::Conversation::new", XS_Pidgin__Conversation_new, file, "$$");
        newXSproto("Pidgin::Conversation::is_hidden", XS_Pidgin__Conversation_is_hidden, file, "$");
        newXSproto("Pidgin::Conversation::get_gtkconv", XS_Pidgin__Conversation_get_gtkconv, file, "$");
        newXSproto("Pidgin::Conversations::find_unseen_list", XS_Pidgin__Conversations_find_unseen_list, file, "$$$$");
        newXSproto("Pidgin::Conversations::get_handle", XS_Pidgin__Conversations_get_handle, file, "");
    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}

