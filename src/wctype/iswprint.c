/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and rediswtribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iswprint.c,v 1.2 1993/06/06 06:24:59 mura Exp $
 */

/* System headers */
#include <wctype.h>
#undef iswprint

/* Functions */
int iswprint (wint_t c)
{
    /* 表示可能文字 */
    return _ISASCII (c) ? (_ctype[c & 0xff] & _ISALNUM) : 0;
}