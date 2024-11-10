/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsicmp.c,v 1.1.1.1 1993/04/18 16:19:40 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <mbstring.h>

/* Functions */
int mbsicmp (const unsigned char *str1, const unsigned char *str2)
{
    int c1, c2;

    /* 文字列を比較する */
    while (1) {

	/* 両方の文字列から 1 文字を取り出す */
	c1 = mbsnextc (str1);
	c2 = mbsnextc (str2);

	/* どちらかが null 文字に達すると終り */
	if (c1 == '\0' || c2 == '\0')
	    return c1 - c2;

	/* 両者が異なるなら半角大文字->半角小文字変換してもう一度試す */
	if (c1 != c2) {
	    c1 = _MBIS16 (c1) ? c1 : tolower (c1);
	    c2 = _MBIS16 (c2) ? c2 : tolower (c2);
	    if (c1 != c2)
		return c1 - c2;
	}

	/* ポインタを進める */
	str1 = mbsinc ((unsigned char *) str1);
	str2 = mbsinc ((unsigned char *) str2);

    }
}
