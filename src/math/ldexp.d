/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ldexp.d,v 1.1 1993/06/24 17:34:09 mura Exp $
 */

/* System headers */
#include <math.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
#pragma 68881 on
#pragma inline-functions off
double _fpu_ldexp (double x, int exp)
{
    double value;

    asm ("fscale.l %2,%0" : "=f" (value) : "0" (x), "g" (exp));
    FPU_ERRCHK ();
    return value;
}
#pragma 68881 off

/* Functions */
double _fe_ldexp (double x, int exp)
{
    xdouble_t value;

    if (isnan (x)) {
	errno = EDOM;
	return x;
    }

    if ((value.d = x) == 0.0) {
	errno = ERANGE;
	return 0;
    }

    if ((exp += value.ieee.exp) < 1) {
	errno = ERANGE;
	return HUGE_VAL;
    }
    else if (exp > 0x7ff) {
	errno = ERANGE;
	return HUGE_VAL;
    }

    value.ieee.exp = exp;

    return value.d;
}

/* Functions */
double ldexp (double x, int exp)
{
    int ssp;
    double value;

    if (_havefpu & _FLG_IOFPU) {
	ssp = SUPERVISOR ();
	value = _fpu_ldexp (x, exp);
	USERMODE (ssp);
    }
    else if (_havefpu & _FLG_FPU)
	value = _f_ldexp (x, exp);
    else
	value = _fe_ldexp (x, exp);

    return value;
}
