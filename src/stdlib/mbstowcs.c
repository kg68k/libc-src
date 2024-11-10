/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbstowcs.c,v 1.2 1994/11/26 14:59:01 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <limits.h>
#include <mbctype.h>
#include <sys/types.h>

/* Functions */
size_t mbstowcs (wchar_t *widechar, const char *multibyte, size_t number)
{
    int bytes;
    int n = 0;

    /* 全ての文字を変換するまでループ */
    while (n < number) {

	/* 変換中に無効な文字にであったら... */
	if ((bytes = mbtowc (widechar, multibyte, MB_LEN_MAX)) < 0)
	    return -1;

	/* null 文字にであったら... */
	if (bytes == 0) {
	    *widechar = (wchar_t) '\0';
	    return n;
	}

	/* カウンタ、ポインタを進める */
	widechar++;
	multibyte += bytes;
	n++;
    }

    /* n を返す */
    return n;
}
