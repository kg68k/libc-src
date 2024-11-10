/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: localeconv.c,v 1.1.1.1 1993/04/18 16:17:40 mura Exp $
 */

/*
** 現在は C ロケールしかサポートしていない
*/

/* System headers */
#include <locale.h>
#include <limits.h>
#undef localeconv

/* File scope functions */
static struct lconv _C_locale = {
    "",				/* currency_symbol */
    "",				/* int_curr_symbol */
    "",				/* mon_decimal_point */
    "",				/* mon_grouping */
    "",				/* mon_thousands_sep */
    "",				/* negative_sign */
    "",				/* positive_sign */
    CHAR_MAX,			/* frac_digits */
    CHAR_MAX,			/* int_frac_digits */
    CHAR_MAX,			/* n_cs_precedes */
    CHAR_MAX,			/* n_sep_by_space */
    CHAR_MAX,			/* n_sign_posn */
    CHAR_MAX,			/* p_cs_precedes */
    CHAR_MAX,			/* p_sep_by_space */
    CHAR_MAX,			/* p_sign_posn */
    ",",			/* decimal_point */
    "",				/* grouping */
    "",				/* thousands_sep */
};

/* External variables */
struct lconv *_locale = &_C_locale;

/* Functions */
struct lconv *localeconv (void)
{
    /* _locale を返す */
    return _locale;
}
