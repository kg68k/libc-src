/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: isnan.c,v 1.1.1.1 1993/04/18 16:18:23 mura Exp $
 */

/* System headers */
#include <math.h>
#include <sys/xmath.h>

/* Functions */
int isnan (double value)
{
    xdouble_t *val = (xdouble_t *) &value;

    /* 指数部が全部 1 で、かつ有効数字の LSB が 1 ならば非数 NaN */
    return ((val->w[0] & 0x7ff0) == 0x7ff0 && (val->b[7] & 1) == 1);
}
