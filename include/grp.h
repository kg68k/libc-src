/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: grp.h,v 1.2 1993/10/06 16:44:02 mura Exp $
 */

#ifndef __grp_h__
#define __grp_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_types_h__
#include <sys/types.h>
#endif

#define _PATH_GROUP "/etc/group"

struct group {
    char *gr_name;
    char *gr_passwd;
    gid_t gr_gid;
    char **gr_mem;
};

_EXTERN (struct group *getgrent (void_));
_EXTERN (struct group *getgrgid (gid_t));
_EXTERN (struct group *getgrnam (const char *));
_EXTERN (void endgrent (void_));
_EXTERN (void setgrent (void_));

#endif
