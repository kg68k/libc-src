/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: assert.h,v 1.2 1993/10/06 16:43:19 mura Exp $
 */

#ifndef __assert_h__
#define __assert_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifdef assert
#undef assert
#endif

#ifdef NDEBUG
#define assert(exp) ((void) 0)
#else
#define assert(exp) ((exp) ? (void) 0 : _assert (#exp, __LINE__, __FILE__))
#endif

_EXTERN (void _assert (const char *, int_, const char *));

#endif
