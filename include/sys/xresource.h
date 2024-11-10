/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xresource.h,v 1.2 1993/10/06 16:47:25 mura Exp $
 */

#ifndef __sys_xresource_h__
#define __sys_xresource_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_resource_h__
#include <sys/resource.h>
#endif

extern struct rlimit _limits[];

_EXTERN (void _loadrlimits (void_));

#endif
