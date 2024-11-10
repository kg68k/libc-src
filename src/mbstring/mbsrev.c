/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from WILLs (Mr. Okabe)
 * --------------------------------------------------------------------
 * $Id: mbsrev.c,v 1.1 1993/08/16 13:52:00 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <mbstring.h>
#include <string.h>

/* Functions */
unsigned char *mbsrev (unsigned char *string)
{
    int n, ch;
    unsigned char *rval;

    /* string を保存する */
    rval = string;

    /* 文字列の長さを計算 */
    n = strlen ((char *) string);

    /* ながさ 1 以上なら処理する */
    if (n > 0) {

	/* まず漢字を無視して反転 */
	strrev ((char *) string);

	/* ポインタを文字列の終端へ */
	string += n - 1;

	/* 文字列のながさ分、逆向きに走査する */
	while (n--) {

	    /* SJIS の第 1 バイトか? */
	    if (ismbblead (*string) && n > 0) {

		/* 隣り合う 2 バイトを入れ換える */
		ch = string[0];
		string[0] = string[-1];
		string[-1] = ch;

		/* string と n を調整 */
		string--;
		n--;

	    }

	    /* ポインタを逆向きに進める */
	    string--;

	}

    }

    /* rval を返す */
    return rval;
}
