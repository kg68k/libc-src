/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: utsname.h,v 1.2 1993/10/06 16:46:59 mura Exp $
 */

#ifndef __sys_utsname_h__
#define __sys_utsname_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

struct utsname {
    char *sysname;
    char *nodename;
    char *release;
    char *version;
    char *machine;
};

_EXTERN (int_ uname (struct utsname *));

#endif
