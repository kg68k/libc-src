/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbslwr.c,v 1.2 1994/11/27 13:03:17 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
unsigned char *mbslwr (unsigned char *string)
{
    int c;
    unsigned char *save = string;

    /* 文字列を変換する */
    while (c = mbsnextc (string)) {

	/* 半角文字だけ処理する */
	if (_MBIS16 (c) == 0)
	    c = tolower (c);

	/* コピー先に複写 */
	_mbset (string, c);

	/* ポインタを進める */
	string = mbsinc (string);

    }

    /* 元の dst を返す */
    return save;
}
