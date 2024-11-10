/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xglob.h,v 1.2 1993/10/06 16:47:07 mura Exp $
 */

#ifndef __sys_xglob_h__
#define __sys_xglob_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_types_h__
#include <sys/types.h>
#endif

#ifndef __sys_dos_h__
#include <sys/dos.h>
#endif

_EXTERN (char *_addlastsep (char *));
_EXTERN (char *_dellastsep (char *));
_EXTERN (char *_sysroot (char *, const char *, size_t));
_EXTERN (char *_tobslash (char *));
_EXTERN (char *_toslash (char *));
_EXTERN (int_ __const _errcnv (int_));
_EXTERN (void *_keeppr_search (const struct _psp *, const char *, char));
_EXTERN (void _print (const char * dotdot_));

#endif
