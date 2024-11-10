/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbscat.c,v 1.1.1.1 1993/04/18 16:19:31 mura Exp $
 */

/* System headers */
#include <mbstring.h>

/* Functions */
unsigned char *mbscat (unsigned char *dst, const unsigned char *src)
{
    int c;
    unsigned char *save = dst;

    /* 文字列の最後を探す */
    while (c = mbsnextc (dst))
	dst = mbsinc (dst);

    /* 文字列を連結する */
    mbscpy (dst, src);

    /* 元の dst を返す */
    return save;
}
