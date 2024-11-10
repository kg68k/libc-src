/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xstdlib.h,v 1.6 1994/11/27 13:01:51 mura Exp $
 */

#ifndef __sys_xstdlib_h__
#define __sys_xstdlib_h__

#if !defined (__GNUC__) && !defined (__GNUG__)
#error You lose. This file can be compiled only by GNU-C compiler.
#endif

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __stdlib_h__
#include <stdlib.h>
#endif

#define MIN_BLOCKSIZ	     32

#define MA_CH_FREE	     0x00
#define MA_CH_USED	     0x77
#define MA_CH_EXIT	     0x7f

#define MA_FREE		     (MA_CH_FREE << 24)
#define MA_USED		     (MA_CH_USED << 24)
#define MA_EXIT		     (MA_CH_EXIT << 24)

#define MA_MASK(p)	     ((p) & 0x00ffffff)
#define MA_RMASK(p)	     ((p) & 0xff000000)
#define MA_FASTMASK(p)	     ((p))
#define MA_MPTR(p)	     ((void *) ((char *) (p) + 4))
#define MA_TOPADR(p)	     ((char *) ((char *) (p) - 4))
#define MA_BACKADR(p)	     ((char *) ((char *) (p) - 4))
#define MA_VALUE(flag, size) ((flag) | (size))
#define MA_ADJUST(x)	     (((x) < MIN_BLOCKSIZ) ? MIN_BLOCKSIZ : (((x) + 15) & ~15))
#define MA_STRSIZ	     (sizeof (int_) * 2)

#define MA_ISUSED(p)	     ((*(unsigned char *) (p)) == MA_CH_USED)
#define MA_ISFREE(p)	     ((*(unsigned char *) (p)) == MA_CH_FREE)
#define MA_ISEXIT(p)	     ((*(unsigned char *) (p)) == MA_CH_EXIT)

#define MA_BFLAG(p)	     (((int_ *)  (p))[-1])
#define MA_FFLAG(p)	     (((int_ *)  (p))[ 0])
#define MA_PREV(p)	     (((char **) (p))[ 1])
#define MA_NEXT(p)	     (((char **) (p))[ 2])

#define FPACKA(func, x, exp)					\
    ({								\
	register double _x asm ("d0") = (x);			\
	register int_ _exp asm ("d2");				\
	asm volatile ("dc.w %c2"				\
		      : "=d" (_x), "=d" (_exp)			\
		      : "i" (func), "0" (_x)			\
		      : "d0", "d1", "d2");			\
	exp = _exp;						\
	_x;							\
    })

#define FPACK1(func, p)						\
    ({								\
	register double _x asm ("d0");				\
	register const char *_p asm ("a0") = (p);		\
	asm volatile ("dc.w %c2"				\
		      : "=d" (_x), "=a" (_p)			\
		      : "i" (func), "1" (_p)			\
		      : "d0", "d1", "d3", "a0");		\
	(p) = _p;						\
	_x;							\
    })

#define FPACK3(func, x, addr, prec)				\
    ({								\
	register double _x asm ("d0") = (x);			\
	register char _prec asm ("d2") = (prec);		\
	register char *_addr asm ("a0") = (addr);		\
	asm volatile ("dc.w %c0"				\
		      : /* no outputs */			\
		      : "i" (func), "d" (_x),			\
		        "d" (_prec), "a" (_addr)		\
		      : "d0", "d1", "a0");			\
    })

extern char *_ma_flist;
extern char *_ma_lptr;
extern int_ _ma_fnum;

_EXTERN (char *_ma_new (size_t));
_EXTERN (char *_ma_recycle (char *, size_t *));
_EXTERN (char *_ma_search (size_t));
_EXTERN (char *_pathexpand (char *, const char *, size_t, int_));
_EXTERN (int_ _getdriveno (const char *));
_EXTERN (int_ _round (char *, char *, int_));
_EXTERN (void _dtos18 (double, int_ *, int_ *, char *));
_EXTERN (void _ma_add (char *));
_EXTERN (void _ma_remove (char *));
_EXTERN (void _ulltoa (unsigned long long, char *));

#endif
