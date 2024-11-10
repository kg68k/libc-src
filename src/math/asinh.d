/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: asinh.d,v 1.1 1993/06/24 17:33:31 mura Exp $
 */

/* System headers */
#include <math.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
double _fpu_asinh (double x)
{
    return _fpu_log (x + _fpu_sqrt ((x * x) + 1.0));
}

/* Functions */
double _fe_asinh (double x)
{
    return _fe_log (x + _fe_sqrt ((x * x) + 1.0));
}

/* Functions */
double asinh (double x)
{
    int ssp;
    double value;

    if (_havefpu & _FLG_IOFPU) {
	ssp = SUPERVISOR ();
	value = _fpu_asinh (x);
	USERMODE (ssp);
    }
    else if (_havefpu & _FLG_FPU)
	value = _f_asinh (x);
    else
	value = _fe_asinh (x);

    return value;
}
