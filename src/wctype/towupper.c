/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and rediswtribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: towupper.c,v 1.2 1993/06/06 06:25:27 mura Exp $
 */

/* System headers */
#include <wctype.h>
#undef towupper

/* Functions */
wint_t towupper (wint_t c)
{
    /* 大文字に変換 */
    return _ISASCII (c) ? _ctype_upper[c & 0xff] : c;
}
