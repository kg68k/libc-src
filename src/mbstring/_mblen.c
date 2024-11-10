/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _mblen.c,v 1.1.1.1 1993/04/18 16:19:27 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
int _mblen (const unsigned char *ptr)
{
    /* 1 バイト目をチェック */
    if (ismbblead (ptr[0]) == 0)
	return 1;

    /* 2 バイト目をチェック */
    if (ismbbtrail (ptr[1]) == 0)
	return -1;

    /* 正常な 2 バイト文字 */
    return 2;
}
