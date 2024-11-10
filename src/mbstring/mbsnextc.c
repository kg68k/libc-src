/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsnextc.c,v 1.1.1.1 1993/04/18 16:19:54 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
int mbsnextc (const unsigned char *p)
{
    int bytes;

    /*
    ** 漢字コードのチェックは厳密に行ない、不正な漢字コードは全て null 文字
    ** とする
    */
    if ((bytes = _mblen (p)) <= 0)
	return 0;

    /* 2 バイト文字は 16bit 幅に拡張する */
    return (bytes > 1) ? ((p[0] << 8) | p[1]) : p[0];
}
