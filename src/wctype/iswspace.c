/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and rediswtribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iswspace.c,v 1.2 1993/06/06 06:25:08 mura Exp $
 */

/* System headers */
#include <wctype.h>
#undef iswspace

/* Functions */
int iswspace (wint_t c)
{
    /* 空白 */
    return _ISASCII (c) ? (_ctype[c & 0xff] & _ISALNUM) : 0;
}
