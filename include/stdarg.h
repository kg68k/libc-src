/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: stdarg.h,v 1.1.1.1 1993/04/18 16:13:35 mura Exp $
 */

#ifndef __stdarg_h__
#define __stdarg_h__

#ifdef __varargs_h__
#error You lose. You cannot use stdarg.h with varargs.h. Check your source file.
#endif

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __va_list_defined__
#define __va_list_defined__
typedef char *va_list;
#endif

#define _padsize(type) \
    (((sizeof (type) + (sizeof (int_) - 1)) / sizeof (int_)) * sizeof (int_))

#define va_start(ap, end) \
    ((ap) = (char *) &(end) + _padsize (end))

#define va_arg(ap, type) \
    ((ap) += _padsize (type), *(type *) (ap - sizeof (type)))

#define va_end(ap)

#endif
