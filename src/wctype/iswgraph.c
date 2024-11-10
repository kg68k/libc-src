/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and rediswtribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iswgraph.c,v 1.2 1993/06/06 06:24:50 mura Exp $
 */

/* System headers */
#include <wctype.h>
#undef iswgraph

/* Functions */
int iswgraph (wint_t c)
{
    /* 表示可能文字（空白以外）*/
    return _ISASCII (c) ? (_ctype[c & 0xff] & _ISALNUM) : 0;
}
