/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: stddef.h,v 1.2 1993/04/30 19:09:34 mura Exp $
 */

#ifndef __stddef_h__
#define __stddef_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __ptrdiff_t_defined__
#define __ptrdiff_t_defined__
typedef int_ ptrdiff_t;
#endif

#ifndef __size_t_defined__
#define __size_t_defined__
typedef unsigned int_ size_t;
#endif

#ifndef __wchar_t_defined__
#define __wchar_t_defined__
typedef int_ wchar_t;
#endif

#ifndef NULL
#define NULL ((void *) 0)
#endif

#define offsetof(type, member) ((size_t) &(((type *) 0)->member))

#endif
