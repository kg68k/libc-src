/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsnccnt.c,v 1.1.1.1 1993/04/18 16:19:49 mura Exp $
 */

/* System headers */
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
size_t mbsnccnt (const unsigned char *string, size_t n)
{
    int bytes;
    int count = 0;

    /* 文字数をカウントする */
    while (n > 0) {

	/* 次の 1 マルチバイトのバイト数を調べる */
	if ((bytes = _mblen (string)) <= 0)
	    return count;

	/* ポインタを進め、文字数を加算 */
	string += bytes;
	n -= bytes;
	count++;

    }

    /* 文字数を返す */
    return count;
}
