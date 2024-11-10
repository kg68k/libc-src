/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fcvt.c,v 1.2 1994/11/27 06:05:08 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <string.h>
#include <sys/xmath.h>
#include <sys/xstdlib.h>

/* File scope variables */
static char floating[512];

/* Functions */
char *ecvt (double value, int precision, int *dec, int *sign)
{
    /* 浮動小数点を E Format で変換する */
    return econvert (value, precision, dec, sign, floating);
}

/* Functions */
char *fcvt (double value, int precision, int *dec, int *sign)
{
    /* 浮動小数点を F Format で変換する */
    return fconvert (value, precision, dec, sign, floating);
}
