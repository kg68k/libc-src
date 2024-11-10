/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: locale.h,v 1.3 1993/10/06 16:44:18 mura Exp $
 */

#ifndef __locale_h__
#define __locale_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5

struct lconv {
    char *currency_symbol;
    char *int_curr_symbol;
    char *mon_decimal_point;
    char *mon_grouping;
    char *mon_thousands_sep;
    char *negative_sign;
    char *positive_sign;
    char frac_digits;
    char int_frac_digits;
    char n_cs_precedes;
    char n_sep_by_space;
    char n_sign_posn;
    char p_cs_precedes;
    char p_sep_by_space;
    char p_sign_posn;
    char *decimal_point;
    char *grouping;
    char *thousands_sep;
};

extern struct lconv *_locale;

_EXTERN (char *setlocale (int_, const char *));
_EXTERN (struct lconv *localeconv (void_));

#ifndef __NO_LOCALE_INLINE__

#define localeconv() (_locale)

#endif

#endif
