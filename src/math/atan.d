/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: atan.d,v 1.1 1993/06/24 17:33:35 mura Exp $
 */

/* System headers */
#include <math.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
#pragma 68881 on
#pragma inline-functions off
double _fpu_atan (double x)
{
    double value;

    asm volatile ("fatan.x %1,%0" : "=f" (value) : "f" (x));
    FPU_ERRCHK ();
    return value;
}
#pragma 68881 off

/* Functions */
double _fe_atan (double x)
{
    return FPACK (__ATAN, x);
}

/* Functions */
double atan (double x)
{
    int ssp;
    double value;

    if (_havefpu & _FLG_IOFPU) {
	ssp = SUPERVISOR ();
	value = _fpu_atan (x);
	USERMODE (ssp);
    }
    else if (_havefpu & _FLG_FPU)
	value = _f_atan (x);
    else
	value = _fe_atan (x);

    return value;
}
