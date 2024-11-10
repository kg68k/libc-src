/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and rediswtribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iswcntrl.c,v 1.2 1993/06/06 06:24:40 mura Exp $
 */

/* System headers */
#include <wctype.h>
#undef iswcntrl

/* Functions */
int iswcntrl (wint_t c)
{
    /* コントロール文字 */
    return _ISASCII (c) ? (_ctype[c & 0xff] & _ISALNUM) : 0;
}
