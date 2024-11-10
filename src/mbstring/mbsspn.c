/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsspn.c,v 1.1.1.1 1993/04/18 16:20:03 mura Exp $
 */

/* System headers */
#include <mbstring.h>

/* Functions */
size_t mbsspn (const unsigned char *str1, const unsigned char *str2)
{
    int c;
    unsigned char *ptr;
    const unsigned char *save = str1;

    /* 文字列を 1 文字ずつチェックする */
    while (c = mbsnextc (str1)) {

	/* str2 の中に c があるか */
	if ((ptr = mbschr (str2, c)) == 0)
	    break;

	/* ポインタを進める */
	str1 = mbsinc ((unsigned char *) str1);

    }

    /* インデックスを返す */
    return str1 - save;
}
