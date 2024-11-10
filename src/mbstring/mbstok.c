/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbstok.c,v 1.1.1.1 1993/04/18 16:20:07 mura Exp $
 */

/* System headers */
#include <stddef.h>
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
unsigned char *mbstok (unsigned char *str, const unsigned char *delim)
{
    int ch, bytes;
    unsigned char *token;
    static unsigned char *last;

    /* str == 0 かつ last == 0 はエラー */
    if (str == 0 && (str = last) == 0)
	return 0;

    /* 頭のデリミタをスキップ */
    while (ch = mbsnextc (str)) {

	/* デリミタか? */
	if (mbschr (delim, ch) == 0)
	    break;

	/* ポインタを進める */
	str = mbsinc (str);

    }

    /* 検索文字列の終了か */
    if (ch == '\0') {
	last = 0;
	return 0;
    }

    /* トークン開始位置を記憶 */
    token = str;

    /* デリミタの検索 */
    while (ch = mbsnextc (str)) {

	/* デリミタか? */
	if (mbschr (delim, ch))
	    break;

	/* ポインタを進める */
	str = mbsinc (str);

    }

    /* 文字列の終わりか? */
    if (ch == '\0') {
	last = 0;
	return token;
    }

    /* デリミタのバイト数をチェック */
    bytes = _mblen (str);

    /* 不正なバイトはエラー */
    if (bytes <= 0)
	return 0;

    /* デリミタ部分を null で埋める */
    str[0] = '\0';
    if (bytes > 1)
	str[1] = '\0';

    /* 最後の位置を記憶して戻る */
    last = str + bytes;

    return token;
}
