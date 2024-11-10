/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fconvert.c,v 1.2 1994/11/27 13:06:19 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <sys/xstdlib.h>

/* Functions */
char *fconvert (double x, int ndigit, int *decpt, int *sign, char *buffer)
{
    int pos, n;
    char *src, *dst;
    char string[24];

    /* 18桁の文字列に変換 */
    _dtos18 (x, decpt, sign, string);

    /* コピー元アドレスを設定 */
    src = string;

    /* コピー先アドレスを設定 */
    dst = buffer;

    /* 小数点位置を得る */
    pos = *decpt;

    /* 小数点位置が負なら */
    if (pos < 0) {

	/* 埋める桁数を計算 */
	n = min (-pos, ndigit);

	/* 先頭を0で埋める */
	while (n-- > 0)
	    *dst++ = '0';

	/* 小数点位置は0になる */
	*decpt = 0;

    }

    /* 残りのコピー桁数 */
    n = ndigit + pos;

    /* 格納先にコピー */
    while (n-- > 0) {

	/* 足りない部分は0で埋める */
	if (*src == '\0') {
	    while (n-- >= 0)
		*dst++ = '0';
	    break;
	}

	/* 変換文字列からコピー */
	*dst++ = *src++;

    }

    /* 終端に NUL を打つ */
    *dst = '\0';

    /* 丸める */
    *decpt += _round (buffer, dst, *src);

    /* アドレスを返す */
    return buffer;
}
