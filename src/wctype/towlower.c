/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and rediswtribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: towlower.c,v 1.2 1993/06/06 06:25:22 mura Exp $
 */

/* System headers */
#include <wctype.h>
#undef towlower

/* Functions */
wint_t towlower (wint_t c)
{
    /* 小文字に変換 */
    return _ISASCII (c) ? _ctype_lower[c & 0xff] : c;
}
