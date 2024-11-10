/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbschr.c,v 1.1.1.1 1993/04/18 16:19:33 mura Exp $
 */

/* System headers */
#include <mbstring.h>

/* Functions */
unsigned char *mbschr (const unsigned char *string, int chr)
{
    int c;

    /* 文字列を解析する */
    for (c = mbsnextc (string); c != chr; c = mbsnextc (string)) {

	/* 文字列は終わりか? */
	if (c == '\0')
	    return 0;

	/* ポインタを進める */
	string = mbsinc ((unsigned char *) string);

    };

    /* アドレスを返す */
    return (unsigned char *) string;
}
