/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xstdio.h,v 1.3 1993/10/06 16:47:48 mura Exp $
 */

#ifndef __sys_xglob_h__
#define __sys_xglob_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __stdio_h__
#include <stdio.h>
#endif

typedef enum {
    inactive = 0,			/* not opened yet */
    read_mode,				/* read pipe mode */
    write_mode,				/* write pipe mode */
} epmode_t;

typedef struct {
    epmode_t mode;			/* current pipe mode */
    const char *command;		/* command line to execute */
    const char *temporary;		/* temporary file name */
} epipe_t;

extern epipe_t _pipes[];

_EXTERN (FILE *_getemptyiob (void_));
_EXTERN (int_ _doprnt (const char *, va_list, FILE *));
_EXTERN (int_ _doscan (const char *, va_list, FILE *));
_EXTERN (int_ _sclose (FILE *));
_EXTERN (int_ _sopen (FILE *, const char *, int_));
_EXTERN (int_ _sread (FILE *));
_EXTERN (int_ _swrite (FILE *));
_EXTERN (void _sinit (void_));

#endif
