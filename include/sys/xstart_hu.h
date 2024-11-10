/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xstart_hu.h,v 1.2 1994/05/02 16:10:21 mura Exp $
 */

#ifndef __sys_xstart_hu_h__
#define __sys_xstart_hu_h__

#define PAD(x) ((void *) (((int_) (x) + 15) & ~15))

#define _SUPER_GO    0x01 /* execute entire program in supervisor mode */
#define _SUPER_FLOAT 0x02 /* use FLOAT package forcefully */

extern char **_argv;
extern char **_envp;
extern char *_comline;
extern int_ _argc;
extern int_ _cplusplus;
extern int_ _exitnums;
extern int_ _heapsize;
extern int_ _hupair;
extern int_ _onexnums;
extern int_ _stacksize;
extern int_ _superman;

extern int_ _SSP;   /* for compatibility with gcc -m68881 */
extern void *_PSTA; /* for compatibility with gcc -p */
extern void *_SSTA; /* for compatibility with gcc -fstack-check */

extern struct _mep *_memcp;
extern struct _psp *_procp;
extern void *_psta;
extern void *_dsta;
extern void *_bsta;
extern void *_csta;
extern void *_vsta;
extern void *_esta;
extern void *_fsta;
extern void *_ssta;
extern void *_hsta;
extern void *_last;
extern void *_mmax;

extern void (*_exitprcs[]) (void_);
extern void (*_onexprcs[]) (void_);

_EXTERN (int_ _dehupair (const char *, char *));
_EXTERN (int_ _enhupair (const char *, char *const *, char *, int_));
_EXTERN (int_ _enargv (const struct _psp *, int_, char **, const char *));
_EXTERN (void __volatile _exit (int_));
_EXTERN (void __volatile _main (void_));
_EXTERN (void __volatile _stack_over (void_));
_EXTERN (void __volatile _start (struct _mep *));
_EXTERN (void _ctors (void_));
_EXTERN (void _dtors (void_));
_EXTERN (void _vectormove (void_));

#endif
