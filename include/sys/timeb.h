/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: timeb.h,v 1.3 1994/11/26 14:49:13 mura Exp $
 */

#ifndef __sys_timeb_h__
#define __sys_timeb_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __time_t_defined__
#define __time_t_defined__
typedef int_ time_t;
#endif

struct timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
};

_EXTERN (void ftime (struct timeb *));

#endif
