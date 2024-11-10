/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xstart.h,v 1.5 1994/07/27 13:45:40 mura Exp $
 */

#ifndef __sys_xstart_h__
#define __sys_xstart_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifdef __LIBSXC__
#include <sys/xstart_sx.h>
#else
#include <sys/xstart_hu.h>
#endif

#endif
