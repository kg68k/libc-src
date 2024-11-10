/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and rediswtribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iswalnum.c,v 1.2 1993/06/06 06:24:31 mura Exp $
 */

/* System headers */
#include <wctype.h>
#undef iswalnum

/* Functions */
int iswalnum (wint_t c)
{
    /* アルファベット及び数字 */
    return _ISASCII (c) ? (_ctype[c & 0xff] & _ISALNUM) : 0;
}