/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xstart_sx.h,v 1.2 1994/05/02 16:10:35 mura Exp $
 */

#ifndef __sys_xstart_sx_h__
#define __sys_xstart_sx_h__

#ifndef __stdio_h__
#include <stdio.h>
#endif

#ifndef __sxlib_h__
#include <sxlib.h>
#endif

#define PAD(x) ((void *) (((int_) (x) + 15) & ~15))

#define _SUPER_GO    0x01 /* execute entire program in supervisor mode */
#define _SUPER_FLOAT 0x02 /* use FLOAT package forcefully */

struct _sx_reg {
    long my_task_id;
    long parent_task_id;
    void *work_top;
    void *cmdline;
    void *envptr;
    void *common_top;
};

typedef struct {
    size_t text;
    size_t data;
    size_t bss;
    size_t comm;
    size_t stack;
    size_t rdata;
    size_t rbss;
    size_t rcomm;
    size_t rstack;
    size_t rldata;
    size_t rlbss;
    size_t rlcomm;
    size_t rlstack;
    size_t roffset;
    size_t reserved[2];
} sizeinfo_t;

extern char **_argv;
extern char **_envp;
extern char *_comline;
extern int_ _argc;
extern int_ _cplusplus;
extern int_ _exitnums;
extern int_ _heapsize;
extern int_ _hupair;
extern int_ _onexnums;
extern __remote int_ _stacksize;
extern __remote int_ _superman;

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

extern long _pid;
extern long _ppid;
extern task *_tdb;
extern void *_common;
extern void *_rdsta;
extern void *_rbsta;
extern void *_rssta;
extern void *_rldsta;
extern void *_rlbsta;
extern void *_rlssta;
extern handle _data_hdl1;
extern handle _data_hdl2;

extern __common sizeinfo_t __size_info;
extern __common char _sxkernelcomm[];

_EXTERN (int_ _dehupair (const char *, char *));
_EXTERN (int_ _enhupair (const char *, char *const *, char *, int_));
_EXTERN (int_ _enargv (int_, char **, const char *));
_EXTERN (void __volatile _exit (int_));
_EXTERN (void __volatile _main (void_));
_EXTERN (void __volatile _stack_over (void_));
_EXTERN (void __volatile _start (struct _sx_reg *));
_EXTERN (void _ctors (void_));
_EXTERN (void _dtors (void_));
_EXTERN (void _sx_killheap (void_));
_EXTERN (void _vectormove (void_));
_EXTERN (void **_sx_rinit (void_));

#endif
