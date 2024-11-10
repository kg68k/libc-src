/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and rediswtribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iswupper.c,v 1.2 1993/06/06 06:25:13 mura Exp $
 */

/* System headers */
#include <wctype.h>
#undef iswupper

/* Functions */
int iswupper (wint_t c)
{
    /* 大文字 */
    return _ISASCII (c) ? (_ctype[c & 0xff] & _ISALNUM) : 0;
}
