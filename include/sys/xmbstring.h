/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xmbstring.h,v 1.3 1994/11/27 13:01:43 mura Exp $
 */

#ifndef __sys_xmbstring_h__
#define __sys_xmbstring_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __mbstring_h__
#include <mbstring.h>
#endif

_EXTERN (int_ _mblen (const unsigned char *));
_EXTERN (unsigned char *_mbset (unsigned char *, int_));

#endif
