/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbscmp.c,v 1.1.1.1 1993/04/18 16:19:34 mura Exp $
 */

/* System headers */
#include <mbstring.h>

/* Functions */
int mbscmp (const unsigned char *str1, const unsigned char *str2)
{
    int c1, c2;

    /* 文字列を比較する */
    while (1) {

	/* 両方の文字列から 1 文字を取り出す */
	c1 = mbsnextc (str1);
	c2 = mbsnextc (str2);

	/* どちらかが null 文字に達するか、両者が異なれば終り */
	if (c1 == '\0' || c2 == '\0' || c1 != c2)
	    return c1 - c2;

	/* ポインタを進める */
	str1 = mbsinc ((unsigned char *) str1);
	str2 = mbsinc ((unsigned char *) str2);

    }
}
