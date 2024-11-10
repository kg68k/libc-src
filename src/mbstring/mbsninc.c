/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsninc.c,v 1.1.1.1 1993/04/18 16:19:57 mura Exp $
 */

/* System headers */
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
unsigned char *mbsninc (const unsigned char *string, size_t n)
{
    int bytes;
    int count = 0;

    /* 文字数をカウントする */
    while ((bytes = _mblen (string)) > 0) {

	/* n 文字目に達したら抜ける */
	if (++count >= n)
	    break;

	/* ポインタを進める */
	string += bytes;

    }

    /* null の位置を返す */
    return (unsigned char *) string;
}
