/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsrchr.c,v 1.1.1.1 1993/04/18 16:20:00 mura Exp $
 */

/* System headers */
#include <mbstring.h>

/* Functions */
unsigned char *mbsrchr (const unsigned char *string, int chr)
{
    int c;
    unsigned char *save = 0;

    /* 文字列を解析する */
    for (c = mbsnextc (string); c; c = mbsnextc (string)) {

	/* 文字が一致するか? */
	if (c == chr)
	    save = (unsigned char *) string;

	/* ポインタを進める */
	string = mbsinc ((unsigned char *) string);

    };

    /* 一致データがあればそれを返す */
    if (save)
	return save;

    /* null 文字が検索対象なら現在位置を返す */
    if (chr == '\0')
	return (unsigned char *) string;

    /* 見つからなかった */
    return 0;
}
