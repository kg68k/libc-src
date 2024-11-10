/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: modf.d,v 1.1 1993/06/24 17:34:21 mura Exp $
 */

/* System headers */
#include <math.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
#pragma 68881 on
#pragma inline-functions off
double _fpu_modf (double x, double *iptr)
{
    double value;

    asm volatile ("fintrz.x %1,%0" : "=f" (value) : "f" (x));
    FPU_ERRCHK ();
    *iptr = value;
    return x - value;
}
#pragma 68881 off

/* Functions */
double _fe_modf (double x, double *iptr)
{
    double value;

    value = FPACK (__DFIX, x);
    *iptr = value;
    return x - value;
}

/* Functions */
double modf (double x, double *iptr)
{
    int ssp;
    double value;

    if (_havefpu & _FLG_IOFPU) {
	ssp = SUPERVISOR ();
	value = _fpu_modf (x, iptr);
	USERMODE (ssp);
    }
    else if (_havefpu & _FLG_FPU)
	value = _f_modf (x, iptr);
    else
	value = _fe_modf (x, iptr);

    return value;
}
