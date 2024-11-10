/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xpwd.h,v 1.1.1.1 1993/04/18 16:15:12 mura Exp $
 */

#ifndef __sys_xpwd_h__
#define __sys_xpwd_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __pwd_h__
#include <pwd.h>
#endif

#ifndef __stdio_h__
#include <stdio.h>
#endif

extern FILE *_pwd_fp;

#endif
