/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: frexp.c,v 1.1.1.1 1993/04/18 16:18:20 mura Exp $
 */

/* System headers */
#include <math.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
double frexp (double x, int *exp)
{
    xdouble_t value;

    /* 非数チェック */
    if (isnan (x)) {
	errno = EDOM;
	return x;
    }

    /* 計算 */
    if ((value.d = x) == 0.0) {
	*exp = 0;
    }
    else {
	*exp = value.ieee.exp - 0x03fe;
	value.ieee.exp = 0x3fe;
    }

    /* 結果を返す */
    return value.d;
}
