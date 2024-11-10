/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and rediswtribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iswascii.c,v 1.1.1.1 1993/04/18 16:41:30 mura Exp $
 */

/* System headers */
#include <wctype.h>
#undef iswascii

/* Functions */
int iswascii (wint_t c)
{
    /* 7bit ASCII 文字 */
    return (c & ~127) == 0;
}
