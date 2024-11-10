/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xprof.h,v 1.2 1993/10/06 16:47:21 mura Exp $
 */

#ifndef __sys_xprof_h__
#define __sys_xprof_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __stdio_h__
#include <stdio.h>
#endif

#define FNC_INITIAL_ALLOC_SIZE  192
#define FNC_ENLARGE_BUFFER_STEP  64
#define BLK_INITIAL_ALLOC_SIZE   30
#define BLK_ENLARGE_BUFFER_STEP  10

struct _fncprof {
    int_ call_c;
    int_ count;
    int_ atime;
    int_ wtime;
    int_ dummy;
    char name[_ZEROARRAY];
};

struct _blkprof {
    int_ init;
    char *file_name;
    int_ *count;
    int_ size;
    int_ zero;
    int_ *addr;
};

extern int_ _fpcnt;
extern int_ _fpmax;
extern int_ _fpuse;
extern int_ _blcnt;
extern int_ _blmax;
extern int_ _bluse;
extern struct _blkprof **_blbuf;
extern struct _fncprof **_fpbuf;

_EXTERN (void __ftime_end (void_));
_EXTERN (void __ftime_start (void_));
_EXTERN (void __display_block_profile (void_));
_EXTERN (void __display_function_profile (void_));

#endif
