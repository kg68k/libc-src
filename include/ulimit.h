/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ulimit.h,v 1.2 1993/10/06 16:45:22 mura Exp $
 */

/*
** PLEASE DO NOT USE THIS HEADER FILE !!!
** ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
** The following features will be supported in the long long
** future,  but not supprted now.   If you want to use these
** features, please make the following interfaces, and contribute
** them to us.
*/

#ifndef __ulimit_h__
#define __ulimit_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define UL_GETFSIZE 0
#define UL_SETFSIZE 1

_EXTERN (long ulimit (int_ dotdot_));

#endif
