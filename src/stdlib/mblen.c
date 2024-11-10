/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mblen.c,v 1.1.1.1 1993/04/18 16:24:25 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <mbctype.h>
#include <sys/types.h>

/* Functions */
int mblen (const char *address, size_t number)
{
    /* ja_JP.SJIS は状態依存ではない */
    if (address == 0)
	return 0;

    /* address が null 文字を指すか、number が 0 以下である */
    if (address[0] == '\0' || number <= 0)
	return 0;

    /* 1 バイト目をチェック */
    if (ismbblead (address[0]) == 0)
	return 1;

    /* 2 バイト目をチェック */
    if (ismbbtrail (address[1]) == 0)
	return -1;

    /* 正常な 2 バイト文字 */
    return 2;
}
