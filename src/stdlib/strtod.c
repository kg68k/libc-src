/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strtod.c,v 1.1.1.1 1993/04/18 16:24:49 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <sys/xmath.h>
#include <sys/xstdlib.h>

/* Functions */
double strtod (const char *str, char **endptr)
{
    double x;

    /* 文字列を浮動小数点に */
    x = FPACK1 (__STOD, str);

    /* 終端を記録する */
    if (endptr)
	*endptr = (char *) str;

    /* x を返す */
    return x;
}
