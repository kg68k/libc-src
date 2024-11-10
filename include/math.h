/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: math.h,v 1.4 1993/10/06 16:44:22 mura Exp $
 */

#ifndef __math_h__
#define __math_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __float_h__
#include <float.h>
#endif

#ifndef __errno_h__
#include <errno.h>
#endif

#define M_1_PI     (0.31830988618379067154) /* 1/pi */
#define M_2_PI     (0.63661977236758134308) /* 2/pi */
#define M_2_SQRTPI (1.12837916709551257390) /* 2/sqrt(pi) */
#define M_E        (2.71828182845904523540) /* e */
#define M_LN10     (2.30258509299404568402) /* log.e(10) */
#define M_LN2      (0.69314718055994530942) /* log.e(2) */
#define M_LOG10E   (0.43429448190325182765) /* log.10(e) */
#define M_LOG2E    (1.44269504088896340741) /* log.2(e) */
#define M_PI       (3.14159265358979323846) /* pi */
#define M_PI_2     (1.57079632679489661923) /* pi/2 */
#define M_PI_4     (0.78539816339744830962) /* pi/4 */
#define M_SQRT1_2  (0.70710678118654752440) /* 1/sqrt(2) */
#define M_SQRT2    (1.41421356237309504880) /* sqrt(2) */

#define HUGE       DBL_MAX
#define HUGE_VAL   DBL_MAX
#define MAXFLOAT   FLT_MAX

extern int_ signgam;

#if defined (__DIRECT_FPU__)

#define acos  _f_acos
#define acosh _f_acosh
#define asin  _f_asin
#define asinh _f_asinh
#define atan  _f_atan
#define atan2 _f_atan2
#define atanh _f_atanh
#define cos   _f_cos
#define cosh  _f_cosh
#define exp   _f_exp
#define fabs  _f_fabs
#define fmod  _f_fmod
#define ldexp _f_ldexp
#define log   _f_log
#define log10 _f_log10
#define modf  _f_modf
#define sin   _f_sin
#define sinh  _f_sinh
#define sqrt  _f_sqrt
#define tan   _f_tan
#define tanh  _f_tanh

#elif defined (__DIRECT_IOFPU__)

#define acos  _fpu_acos
#define acosh _fpu_acosh
#define asin  _fpu_asin
#define asinh _fpu_asinh
#define atan  _fpu_atan
#define atan2 _fpu_atan2
#define atanh _fpu_atanh
#define cos   _fpu_cos
#define cosh  _fpu_cosh
#define exp   _fpu_exp
#define fabs  _fpu_fabs
#define fmod  _fpu_fmod
#define ldexp _fpu_ldexp
#define log   _fpu_log
#define log10 _fpu_log10
#define modf  _fpu_modf
#define sin   _fpu_sin
#define sinh  _fpu_sinh
#define sqrt  _fpu_sqrt
#define tan   _fpu_tan
#define tanh  _fpu_tanh

#elif defined (__DIRECT_FLOAT__)

#define acos  _fe_acos
#define acosh _fe_acosh
#define asin  _fe_asin
#define asinh _fe_asinh
#define atan  _fe_atan
#define atan2 _fe_atan2
#define atanh _fe_atanh
#define cos   _fe_cos
#define cosh  _fe_cosh
#define exp   _fe_exp
#define fabs  _fe_fabs
#define fmod  _fe_fmod
#define ldexp _fe_ldexp
#define log   _fe_log
#define log10 _fe_log10
#define modf  _fe_modf
#define sin   _fe_sin
#define sinh  _fe_sinh
#define sqrt  _fe_sqrt
#define tan   _fe_tan
#define tanh  _fe_tanh

#endif

_EXTERN (double __const acos (double));
_EXTERN (double __const acosh (double));
_EXTERN (double __const asin (double));
_EXTERN (double __const asinh (double));
_EXTERN (double __const atan (double));
_EXTERN (double __const atan2 (double, double));
_EXTERN (double __const atanh (double));
_EXTERN (double __const ceil (double));
_EXTERN (double __const cos (double));
_EXTERN (double __const cosh (double));
_EXTERN (double __const exp (double));
_EXTERN (double __const erf (double));
_EXTERN (double __const erfc (double));
_EXTERN (double __const fabs (double));
_EXTERN (double __const floor (double));
_EXTERN (double __const fmod (double, double));
_EXTERN (double __const hypot (double, double));
_EXTERN (double __const ldexp (double, int_));
_EXTERN (double __const log (double));
_EXTERN (double __const log10 (double));
_EXTERN (double __const pow (double, double));
_EXTERN (double __const sin (double));
_EXTERN (double __const sinh (double));
_EXTERN (double __const sqrt (double));
_EXTERN (double __const tan (double));
_EXTERN (double __const tanh (double));
_EXTERN (double frexp (double, int_ *));
_EXTERN (double modf (double, double *));
_EXTERN (double gamma (double));
_EXTERN (double j0 (double));
_EXTERN (double j1 (double));
_EXTERN (double jn (double));
_EXTERN (double lgamma (double));
_EXTERN (double y0 (double));
_EXTERN (double y1 (double));
_EXTERN (double yn (double));
_EXTERN (int_ __const isinf (double));
_EXTERN (int_ __const isnan (double));

#endif
