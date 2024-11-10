/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strtok.c,v 1.1.1.1 1993/04/18 16:25:56 mura Exp $
 */

/* System headers */
#include <stddef.h>
#include <string.h>

/* Functions */
char *strtok (char *str, const char *delim)
{
    int ch;
    char *token;
    static char *last;

    /* str == 0 かつ last == 0 はエラー */
    if (str == 0 && (str = last) == 0)
	return 0;

    /* 頭のデリミタをスキップ */
    while (ch = *str++)
	if (strchr (delim, ch) == 0)
	    break;

    /* 検索文字列の終了か */
    if (ch == '\0') {
	last = 0;
	return 0;
    }

    /* トークン開始位置を記憶 */
    token = str - 1;

    /* デリミタの検索 */
    while (ch = *str++)
	if (strchr (delim, ch))
	    break;

    /* 文字列の終わりか? */
    if (ch == '\0') {
	last = 0;
	return token;
    }

    /* デリミタ位置を null で埋める */
    str[-1] = '\0';

    /* 最後の位置を記憶して戻る */
    last = str;

    return token;
}
