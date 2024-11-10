/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from TomY.
 * --------------------------------------------------------------------
 * $Id: ftw.h,v 1.3 1993/10/06 16:43:57 mura Exp $
 */

#ifndef __ftw_h__
#define __ftw_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_stat_h__
#include <sys/stat.h>
#endif

#define FTW_F   0
#define FTW_D   1
#define FTW_DNR 2
#define FTW_SL  3
#define FTW_NS  4
#define FTW_VL  5

_EXTERN (int_ ftw (const char *, int_ (*) (const char *, const struct stat *, int_), int_));

#endif
