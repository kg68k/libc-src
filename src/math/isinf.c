/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: isinf.c,v 1.1.1.1 1993/04/18 16:18:21 mura Exp $
 */

/* System headers */
#include <math.h>
#include <sys/xmath.h>

/* Functions */
int isinf (double value)
{
    xdouble_t *val = (xdouble_t *) &value;

    /* 指数部が全部 1 で、かつ有効数字が全て 0 ならば無限大 0 */
    return ((val->l[0] & 0x7fffffff) == 0x7ff00000 && val->l[1] == 0);
}
