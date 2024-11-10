/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: resource.h,v 1.2 1993/10/06 16:46:30 mura Exp $
 */

#ifndef __sys_resource_h__
#define __sys_resource_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define RLIMIT_CPU    0
#define RLIMIT_FSIZE  1
#define RLIMIT_DATA   2
#define RLIMIT_STACK  3
#define RLIMIT_CORE   4
#define RLIMIT_RSS    5
#define RLIMIT_NOFILE 6

#define RLIM_NLIMITS  7
#define RLIM_INFINITY 0x7fffffff

struct rlimit {
    int_ rlim_cur;
    int_ rlim_max;
};

_EXTERN (int_ getrlimit (int_, struct rlimit *));
_EXTERN (int_ setrlimit (int_, struct rlimit *));

#endif
