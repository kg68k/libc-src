/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: project.h,v 1.2 1993/10/06 16:46:26 mura Exp $
 */

#ifndef __sys_project_h__
#define __sys_project_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

extern char _libc_release[];
extern char _libc_version[];

_EXTERN (void _libc_print_version (void_));

#endif
