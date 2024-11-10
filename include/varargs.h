/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: varargs.h,v 1.1.1.1 1993/04/18 16:13:53 mura Exp $
 */

#ifndef __varargs_h__
#define __varargs_h__

#ifdef __stdarg_h__
#error You lose. You cannot use varargs.h with stdarg.h. Check your source file.
#endif

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __va_list_defined__
#define __va_list_defined__
typedef char *va_list;
#endif

#define va_dcl int_ va_alist;
#define va_start(ap) (ap) = (char *) &va_alist
#define va_end(ap)

#define va_arg(ap, type) \
  ((type *) (((char *) (ap)) += sizeof (type)))[-1]

#endif
