/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _fullpath.c,v 1.1.1.1 1993/04/18 16:23:39 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <sys/xstdlib.h>

/* Functions */
char *_fullpath (char *dst, const char *src, size_t maxlen)
{
    return _pathexpand (dst, src, maxlen, 0);
}
