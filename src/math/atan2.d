/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: atan2.d,v 1.1 1993/06/24 17:33:39 mura Exp $
 */

/* System headers */
#include <math.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
#pragma 68881 on
#pragma inline-functions off
double _fpu_atan2 (double y, double x)
{
    double pi;

    if (x > 0.0) {
	asm volatile ("fatan.x %1,%0" : "=f" (x) : "f" (y / x));
	FPU_ERRCHK ();
	return x;
    }

    asm volatile ("fmovecr.x #$0,%0" : "=f" (pi));

    if (x < 0.0) {
	if (y > 0.0) {
	    asm volatile ("fatan.x %1,%0" : "=f" (x):"f" (y / x));
	    FPU_ERRCHK ();
	    return x + pi;
	}
	else if (y < 0.0) {
	    asm volatile ("fatan.x %1,%0" : "=f" (x):"f" (y / x));
	    FPU_ERRCHK ();
	    return x - pi;
	}
	else
	    return pi;
    }
    else {
	double pi_2;

	asm volatile ("fscale.w #-1,%0" : "=f" (pi_2) : "0" (pi));

	if (y < 0.0)
	    return -pi_2;
	else if (y > 0.0)
	    return +pi_2;
	else {
	    errno = EDOM;
	    return _NAN;
	}
    }
}
#pragma 68881 off

/* Functions */
double _fe_atan2 (double y, double x)
{
    if (isnan (y) || isnan (x)) {
	errno = EDOM;
	return _NAN;
    }

    if (x > 0.0) {
	return _fe_atan (y / x);
    }
    else if (x < 0.0) {
	if (y > 0.0)
	    return _fe_atan (y / x) + M_PI;
	else if (y < 0.0)
	    return _fe_atan (y / x) - M_PI;
	else
	    return M_PI;
    }
    else {
	if (y < 0.0)
	    return -M_PI_2;
	else if (y > 0.0)
	    return +M_PI_2;
	else {
	    errno = EDOM;
	    return _NAN;
	}
    }
}

/* Functions */
double atan2 (double y, double x)
{
    int ssp;
    double value;

    if (_havefpu & _FLG_IOFPU) {
	ssp = SUPERVISOR ();
	value = _fpu_atan2 (y, x);
	USERMODE (ssp);
    }
    else if (_havefpu & _FLG_FPU)
	value = _f_atan2 (y, x);
    else
	value = _fe_atan2 (y, x);

    return value;
}
