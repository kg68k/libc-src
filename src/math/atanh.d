/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: atanh.d,v 1.1 1993/06/24 17:33:43 mura Exp $
 */

/* System headers */
#include <math.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
double _fpu_atanh (double x)
{
    return 0.50 * _fpu_log ((1.0 + x) / (1.0 - x));
}

/* Functions */
double _fe_atanh (double x)
{
    return FPACK (__ATANH, x);
}

/* Functions */
double atanh (double x)
{
    int ssp;
    double value;

    if (_havefpu & _FLG_IOFPU) {
	ssp = SUPERVISOR ();
	value = _fpu_atanh (x);
	USERMODE (ssp);
    }
    else if (_havefpu & _FLG_FPU)
	value = _f_atanh (x);
    else
	value = _fe_atanh (x);

    return value;
}
