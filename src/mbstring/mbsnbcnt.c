/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsnbcnt.c,v 1.1.1.1 1993/04/18 16:19:46 mura Exp $
 */

/* System headers */
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
size_t mbsnbcnt (const unsigned char *string, size_t n)
{
    int bytes;
    int count = 0;

    /* バイト数をカウントする */
    while (n-- > 0) {

	/* 次の 1 マルチバイトのバイト数を調べる */
	if ((bytes = _mblen (string)) <= 0)
	    return count;

	/* ポインタを進め、バイト数を加算 */
	string += bytes;
	count += bytes;

    }

    /* バイト数を返す */
    return count;
}
