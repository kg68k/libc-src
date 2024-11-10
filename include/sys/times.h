/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: times.h,v 1.2 1993/10/06 16:46:55 mura Exp $
 */

/*
** PLEASE DO NOT USE THIS HEADER FILE !!!
** ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
** The following features will be supported in the long long
** future,  but not supprted now.   If you want to use these
** features, please make the following interfaces, and contribute
** them to us.
*/

#ifndef __sys_times_h__
#define __sys_times_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_types_h__
#include <sys/types.h>
#endif

struct tms {
    clock_t tms_utime;
    clock_t tms_stime;
    clock_t tms_cutime;
    clock_t tms_cstime;
};

_EXTERN (clock_t times (struct tms *));

#endif
