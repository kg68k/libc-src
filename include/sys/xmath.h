/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xmath.h,v 1.3 1993/10/06 16:47:11 mura Exp $
 */

#ifndef __sys_xmath_h__
#define __sys_xmath_h__

#if !defined (__GNUC__) && !defined (__GNUG__)
#error You lose. This file can be compiled only by GNU-C compiler.
#endif

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __math_h__
#include <math.h>
#endif

#define __LMUL      0xfe00
#define __LDIV      0xfe01
#define __LMOD      0xfe02
#define __UMUL      0xfe04
#define __UDIV      0xfe05
#define __UMOD      0xfe06
#define __IMUL      0xfe08
#define __IDIV      0xfe09
#define __RANDOMIZE 0xfe0c
#define __SRAND     0xfe0d
#define __RAND      0xfe0e
#define __STOL      0xfe10
#define __LTOS      0xfe11
#define __STOH      0xfe12
#define __HTOS      0xfe13
#define __STOO      0xfe14
#define __OTOS      0xfe15
#define __STOB      0xfe16
#define __BTOS      0xfe17
#define __IUSING    0xfe18
#define __LTOD      0xfe1a
#define __DTOL      0xfe1b
#define __LTOF      0xfe1c
#define __FTOL      0xfe1d
#define __FTOD      0xfe1e
#define __DTOF      0xfe1f
#define __VAL       0xfe20
#define __USING     0xfe21
#define __STOD      0xfe22
#define __DTOS      0xfe23
#define __ECVT      0xfe24
#define __FCVT      0xfe25
#define __GCVT      0xfe26
#define __DTST      0xfe28
#define __DCMP      0xfe29
#define __DNEG      0xfe2a
#define __DADD      0xfe2b
#define __DSUB      0xfe2c
#define __DMUL      0xfe2d
#define __DDIV      0xfe2e
#define __DMOD      0xfe2f
#define __DABS      0xfe30
#define __DCEIL     0xfe31
#define __DFIX      0xfe32
#define __DFLOOR    0xfe33
#define __DFRAC     0xfe34
#define __DSGN      0xfe35
#define __SIN       0xfe36
#define __COS       0xfe37
#define __TAN       0xfe38
#define __ATAN      0xfe39
#define __LOG       0xfe3a
#define __EXP       0xfe3b
#define __SQR       0xfe3c
#define __PI        0xfe3d
#define __NPI       0xfe3e
#define __POWER     0xfe3f
#define __RND       0xfe40
#define __DFREXP    0xfe49
#define __DLDEXP    0xfe4a
#define __DADDONE   0xfe4b
#define __DSUBONE   0xfe4c
#define __DDIVTWO   0xfe4d
#define __DIEECNV   0xfe4e
#define __IEEDCNV   0xfe4f
#define __FVAL      0xfe50
#define __FUSING    0xfe51
#define __STOF      0xfe52
#define __FTOS      0xfe53
#define __FECVT     0xfe54
#define __FFCVT     0xfe55
#define __FGCVT     0xfe56
#define __FTST      0xfe58
#define __FCMP      0xfe59
#define __FNEG      0xfe5a
#define __FADD      0xfe5b
#define __FSUB      0xfe5c
#define __FMUL      0xfe5d
#define __FDIV      0xfe5e
#define __FMOD      0xfe5f
#define __FABS      0xfe60
#define __FCEIL     0xfe61
#define __FFIX      0xfe62
#define __FFLOOR    0xfe63
#define __FFRAC     0xfe64
#define __FSGN      0xfe65
#define __FSIN      0xfe66
#define __FCOS      0xfe67
#define __FTAN      0xfe68
#define __FATAN     0xfe69
#define __FLOG      0xfe6a
#define __FEXP      0xfe6b
#define __FSQR      0xfe6c
#define __FPI       0xfe6d
#define __FNPI      0xfe6e
#define __FPOWER    0xfe6f
#define __FRND      0xfe70
#define __FFREXP    0xfe79
#define __FLDEXP    0xfe7a
#define __FADDONE   0xfe7b
#define __FSUBONE   0xfe7c
#define __FDIVTWO   0xfe7d
#define __FIEECNV   0xfe7e
#define __IEEFCNV   0xfe7f
#define __CLMUL     0xfee0
#define __CLDIV     0xfee1
#define __CLMOD     0xfee2
#define __CUMUL     0xfee3
#define __CUDIV     0xfee4
#define __CUMOD     0xfee5
#define __CLTOD     0xfee6
#define __CDTOL     0xfee7
#define __CLTOF     0xfee8
#define __CFTOL     0xfee9
#define __CFTOD     0xfeea
#define __CDTOF     0xfeeb
#define __CDCMP     0xfeec
#define __CDADD     0xfeed
#define __CDSUB     0xfeee
#define __CDMUL     0xfeef
#define __CDDIV     0xfef0
#define __CDMOD     0xfef1
#define __CFCMP     0xfef2
#define __CFADD     0xfef3
#define __CFSUB     0xfef4
#define __CFMUL     0xfef5
#define __CFDIV     0xfef6
#define __CFMOD     0xfef7
#define __CDTST     0xfef8
#define __CFTST     0xfef9
#define __CDINC     0xfefa
#define __CFINC     0xfefb
#define __CDDEC     0xfefc
#define __CFDEC     0xfefd
#define __FEVARG    0xfefe
#define __FEVECS    0xfeff

#ifndef __OLD_FLOAT_PACK__
#define __SINH      0xfe41
#define __COSH      0xfe42
#define __TANH      0xfe43
#define __ATANH     0xfe44
#define __ASIN      0xfe45
#define __ACOS      0xfe46
#define __LOG10     0xfe47
#define __LOG2      0xfe48
#define __FSINH     0xfe71
#define __FCOSH     0xfe72
#define __FTANH     0xfe73
#define __FATANH    0xfe74
#define __FASIN     0xfe75
#define __FACOS     0xfe76
#define __FLOG10    0xfe77
#define __FLOG2     0xfe78
#endif

#define SUPERVISOR()					\
    ({							\
	long ssp;					\
	int_ sr;					\
	if(_havefpu & _FLG_ILCPU)			\
	    ssp = _dos_super (0);	       		\
	else {						\
	    asm volatile ("move.w sr,%0" : "=g" (sr));	\
	    ssp = (sr & (1<<13)) ? 0 : _dos_super (0);	\
	}						\
	ssp;						\
    })

#define USERMODE(ssp)					\
    {							\
	if ((ssp) > 0) { 				\
	    int_ stack;					\
	    asm volatile ("move.l sp,%1\n\t"		\
			  "move.l %0,sp\n\t"		\
			  "andi.w #$dfff,sr\n\t"	\
			  "move.l %1,sp"		\
			  :"=r" ((ssp)), "=r" (stack)	\
			  :"0" ((ssp)));    		\
	}						\
    }

#define FPACK(func, x)					\
    ({							\
	register double val asm ("d0");			\
	asm volatile("dc.w %c2\n\t"			\
		     "bcc @@f\n\t"			\
		     "bvc @f\n\t"			\
		     "move.l %5,%3\n\t"			\
		     "bra @@f\n"			\
		     "@@:\n\t"				\
		     "move.l %4,%3\n\t"			\
		     "@@:"				\
		     : "=d" (val)			\
		     : "0" (x), "i" (func),		\
		       "g" (errno), "i" (EDOM),		\
		       "i" (ERANGE)); 			\
	val;						\
    })

#define FPACKZ(func, x)					\
    ({							\
	register double val asm ("d0");			\
	asm volatile("dc.w %c2\n\t"			\
		     "bcc @@f\n\t"			\
		     "bnz @f\n\t"			\
		     "move.l %5,%3\n\t"			\
		     "bra @@f\n"			\
		     "@@:\n\t"				\
		     "move.l %4,%3\n\t"			\
		     "@@:"				\
		     : "=d" (val)			\
		     : "0" (x), "i" (func),		\
		       "g" (errno), "i" (EDOM),		\
		       "i" (ERANGE)); 			\
	val;						\
    })

#define FPACK2(func, x, y)				\
    ({							\
	register double val asm ("d0");			\
	register double _y asm ("d2");			\
	_y = y;						\
	asm volatile("dc.w %c3\n\t"			\
		     "bcc @@f\n\t"			\
		     "bvc @f\n\t"			\
		     "move.l %6,%4\n\t"			\
		     "bra @@f\n"			\
		     "@@:\n\t"				\
		     "move.l %5,%4\n\t"			\
		     "@@:"				\
		     : "=d" (val)			\
		     : "0" (x), "d" (_y),		\
		       "i" (func), "g" (errno),		\
		       "i" (EDOM), "i" (ERANGE));	\
	val;						\
    })

#define FPACK2_NOERR(func, x, y)			\
    ({							\
	register double val asm ("d0");			\
	register double _y asm ("d2");			\
	_y = y;						\
	asm volatile("dc.w %c3\n\t"			\
		     : "=d" (val)			\
		     : "0" (x), "d" (_y),		\
		       "i" (func));			\
	val;						\
    })

#define _INEX1		  (1 << 8)
#define _INEX2		  (1 << 9)
#define _UNFL		  (1 << 11)
#define _OVFL		  (1 << 12)
#define _INFI		  (1 << 25)

#define IS_NAN(fpsr)	  ((fpsr) & (1 << 24))
#define IS_INFINITE(fpsr) ((fpsr) & (1 << 25))
#define IS_ZERO(fpsr)	  ((fpsr) & (1 << 26))
#define IS_MINUS(fpsr)	  ((fpsr) & (1 << 27))
#define IS_ERROR(fpsr)	  ((fpsr) & 0x0300))
#define IS_ERANGE(fpsr)	  ((fpsr) & (_INFI | _OVFL | _UNFL | _INEX2))

#define FPU_ERRCHK()					\
    {							\
	unsigned int_ fpsr = 0;				\
	asm volatile ("fmove.l fpsr,%0" : "=g" (fpsr) : "g" (fpsr)); \
	if (IS_NAN (fpsr))				\
	    errno = EDOM;				\
	else if (IS_ERANGE (fpsr))			\
	    errno = ERANGE;				\
    }

typedef struct {
    unsigned s:1;
    unsigned exp:11;
    unsigned sft_h:20;
    unsigned sft_l:32;
} xieee_double_t;

typedef struct {
    unsigned s:1;
    unsigned exp:8;
    unsigned sft:23;
} xieee_float_t;

typedef union {
    double d;
    unsigned char b[8];
    unsigned short w[4];
    unsigned long l[2];
    unsigned long long int ll;
    xieee_double_t ieee;
} xdouble_t;

#define _NAN				\
    ({					\
	xdouble_t nan;			\
	nan.ll = 0x7fffffffffffffffULL;	\
	nan.d;				\
    })

#define _FLG_IOFPU	0x01 /* 1 means machine has 68881 */
#define _FLG_ILCPU	0x02 /* 1 means cpu is something else 68000 */
#define _FLG_FPU	0x04 /* 1 means we are running on 68030 */
#define _FPU_ID		(0)
#define _FPU_IO		(0xe9e000 + _FPU_ID * 0x80)
#define _PRIV_VECTORNO	(8)

extern char _havefpu;
extern char _ohavefpu;

#define _fpu_on()  (_havefpu = _ohavefpu)
#define _fpu_off() (_havefpu = _ohavefpu & ~(_FLG_FPU | _FLG_IOFPU))

_EXTERN (char _iscopro (void_));
_EXTERN (double __const _f_acos (double));
_EXTERN (double __const _f_acosh (double));
_EXTERN (double __const _f_asin (double));
_EXTERN (double __const _f_asinh (double));
_EXTERN (double __const _f_atan (double));
_EXTERN (double __const _f_atan2 (double, double));
_EXTERN (double __const _f_atanh (double));
_EXTERN (double __const _f_cos (double));
_EXTERN (double __const _f_cosh (double));
_EXTERN (double __const _f_exp (double));
_EXTERN (double __const _f_fabs (double));
_EXTERN (double __const _f_fmod (double, double));
_EXTERN (double __const _f_ldexp (double, int_));
_EXTERN (double __const _f_log (double));
_EXTERN (double __const _f_log10 (double));
_EXTERN (double __const _f_sin (double));
_EXTERN (double __const _f_sinh (double));
_EXTERN (double __const _f_sqrt (double));
_EXTERN (double __const _f_tan (double));
_EXTERN (double __const _f_tanh (double));
_EXTERN (double __const _fe_acos (double));
_EXTERN (double __const _fe_acosh (double));
_EXTERN (double __const _fe_asin (double));
_EXTERN (double __const _fe_asinh (double));
_EXTERN (double __const _fe_atan (double));
_EXTERN (double __const _fe_atan2 (double, double));
_EXTERN (double __const _fe_atanh (double));
_EXTERN (double __const _fe_cos (double));
_EXTERN (double __const _fe_cosh (double));
_EXTERN (double __const _fe_exp (double));
_EXTERN (double __const _fe_fabs (double));
_EXTERN (double __const _fe_fmod (double, double));
_EXTERN (double __const _fe_ldexp (double, int_));
_EXTERN (double __const _fe_log (double));
_EXTERN (double __const _fe_log10 (double));
_EXTERN (double __const _fe_sin (double));
_EXTERN (double __const _fe_sinh (double));
_EXTERN (double __const _fe_sqrt (double));
_EXTERN (double __const _fe_tan (double));
_EXTERN (double __const _fe_tanh (double));
_EXTERN (double __const _fpu_acos (double));
_EXTERN (double __const _fpu_acosh (double));
_EXTERN (double __const _fpu_asin (double));
_EXTERN (double __const _fpu_asinh (double));
_EXTERN (double __const _fpu_atan (double));
_EXTERN (double __const _fpu_atan2 (double, double));
_EXTERN (double __const _fpu_atanh (double));
_EXTERN (double __const _fpu_cos (double));
_EXTERN (double __const _fpu_cosh (double));
_EXTERN (double __const _fpu_exp (double));
_EXTERN (double __const _fpu_fabs (double));
_EXTERN (double __const _fpu_fmod (double, double));
_EXTERN (double __const _fpu_ldexp (double, int_));
_EXTERN (double __const _fpu_log (double));
_EXTERN (double __const _fpu_log10 (double));
_EXTERN (double __const _fpu_sin (double));
_EXTERN (double __const _fpu_sinh (double));
_EXTERN (double __const _fpu_sqrt (double));
_EXTERN (double __const _fpu_tan (double));
_EXTERN (double __const _fpu_tanh (double));
_EXTERN (double _f_modf (double, double *));
_EXTERN (double _fe_modf (double, double *));
_EXTERN (double _fpu_modf (double, double *));
_EXTERN (double _f_frexp (double, int_ *));
_EXTERN (double _fe_frexp (double, int_ *));
_EXTERN (double _fpu_frexp (double, int_ *));
_EXTERN (int_ __const _f_cmpdf2 (double, double));
_EXTERN (int_ __const _fe_cmpdf2 (double, double));
_EXTERN (int_ __const _fpu_cmpdf2 (double, double));
_EXTERN (int_ _is68881 (void_));
_EXTERN (void _fpuinit (void_));

#endif
