/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: cmpdf2.d,v 1.1 1993/06/24 17:33:46 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
#pragma 68881 on
#pragma inline-functions off
int _fpu_cmpdf2 (double x, double y)
{
    xdouble_t value;

    asm volatile ("fsub.x %2,%0" : "=f" (value.d) : "0" (x), "f" (y));
    if ((value.l[0] & 0x7fffffff) == 0 && value.l[1] == 0)
	return 0;

    return (value.ieee.s) ? -1 : 1;
}
#pragma 68881 off

/* Functions */
int _fe_cmpdf2 (double x, double y)
{
    xdouble_t value;

    value.d = FPACK2_NOERR (__DSUB, x, y);
    if ((value.l[0] & 0x7fffffff) == 0 && value.l[1] == 0)
	return 0;

    return (value.ieee.s) ? -1 : 1;
}

/* Functions */
int __cmpdf2 (double x, double y)
{
    int value, ssp;

    if (_havefpu & _FLG_IOFPU) {
	ssp = SUPERVISOR ();
	value = _fpu_cmpdf2 (x, y);
	USERMODE (ssp);
    }
    else if (_havefpu & _FLG_FPU)
	value = _f_cmpdf2 (x, y);
    else
	value = _fe_cmpdf2 (x, y);

    return value;
}
