/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: tanh.d,v 1.1 1993/06/24 17:34:40 mura Exp $
 */

/* System headers */
#include <math.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
#pragma 68881 on
#pragma inline-functions off
double _fpu_tanh (double x)
{
    double value;

    asm volatile ("ftanh.x %1,%0" : "=f" (value) : "f" (x));
    FPU_ERRCHK ();
    return value;
}
#pragma 68881 off

/*
** tanh(x) = (exp(x) - exp(-x)) / (exp(x) + exp(-x))
*/

/* Functions */
double _fe_tanh (double x)
{
     return FPACK (__TANH, x);
}

/* Functions */
double tanh (double x)
{
    int ssp;
    double value;

    if (_havefpu & _FLG_IOFPU) {
	ssp = SUPERVISOR ();
	value = _fpu_tanh (x);
	USERMODE (ssp);
    }
    else if (_havefpu & _FLG_FPU)
	value = _f_tanh (x);
    else
	value = _fe_tanh (x);

    return value;
}
