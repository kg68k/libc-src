/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: wctomb.c,v 1.1.1.1 1993/04/18 16:24:59 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <mbctype.h>
#include <sys/types.h>

/* Functions */
int wctomb (char *string, wchar_t widechar)
{
    int c1, c2;

    /* ja_JP.SJIS は状態依存ではない */
    if (string == 0)
	return 0;

    /* widechar は 16bit コードであるか */
    if (widechar & 0xff00) {

	/* c1, c2 に上位、下位 8 bit をそれぞれ取り出す */
	c1 = (widechar >> 8) & 0xff;
	c2 = (widechar & 0xff);

	/* c1, c2 が妥当な SJIS 1st,2nd バイトかどうか */
	if (ismbblead (c1) == 0 || ismbbtrail (c2) == 0)
	    return -1;

	/* 妥当な値として変換する */
	*string++ = (char) c1;
	*string   = (char) c2;

	/* 2byte 文字 */
	return 2;

    }
    else {

	/* 下位 8 bit だけを変換する */
	*string = (char) widechar & 0xff;

	/* 1byte 文字 */
	return 1;

    }
}
