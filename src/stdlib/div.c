/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: div.c,v 1.1.1.1 1993/04/18 16:24:10 mura Exp $
 */

/* System headers */
#include <stdlib.h>

/* Functions */
div_t div (int numerator, int denominator)
{
    div_t v;

    /* まず代数的に計算する */
    v.quot = numerator / denominator;
    v.rem = numerator % denominator;

    /* 結果を補正する */
    if (v.quot < 0 && v.rem > 0) {
	v.quot++;
	v.rem -= denominator;
    }

    return v;
}
