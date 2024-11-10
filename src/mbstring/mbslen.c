/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbslen.c,v 1.1.1.1 1993/04/18 16:19:43 mura Exp $
 */

/* System headers */
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
size_t mbslen (const unsigned char *string)
{
    int bytes;
    int count = 0;

    /* 文字数をカウントする */
    while (*string && (bytes = _mblen (string)) > 0) {
	string += bytes;
	count++;
    }

    /* 文字数を返す */
    return count;
}
