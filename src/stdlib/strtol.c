/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strtol.c,v 1.2 1993/09/07 16:21:05 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>

/* Functions */
long strtol (const char *str, char **end, int base)
{
    int c;
    int sign, over;
    long val;
    const char *top, *save;

    /* base チェック */
    if ((base != 0 && base < 2) || base > 36) {
	errno = EINVAL;
	return 0;
    }

    /* top を保存 */
    top = str;

    /* 先頭の空白を飛ばす */
    while (isspace (*str))
	str++;

    /* 通常は正 */
    sign = 0;

    /* 符号を処理する */
    switch (*str) {
    case '-':
	sign = 1;
    case '+':
	str++;
	break;
    }

    /* base が未決定 */
    if (base == 0) {

	/* 先頭が 0 か? */
	if (*str == '0') {

	    /* 次の文字が x,X ならば 16 進数 */
	    if (str[1] == 'x' || str[1] == 'X') {
		base = 16;
		str += 2;
	    }

	    /* 違うなら 8 進数 */
	    else
		base = 8;

	}

	/* 違うなら 10 進数 */
	else
	    base = 10;

    }

    /* 決定ずみで 16 進数ならば 0x を飛ばす */
    else if (base == 16) {
	if (*str == '0' && (str[1] == 'X' || str[1] == 'x'))
	    str += 2;
    }

    /* 数値変換開始の前にちょっと初期化 */
    val = 0;
    over = 0;
    save = str;

    /* 数値変換 */
    while (c = *str) {

	/* 0-9,a-z,A-Z を処理 */
	if (isdigit (c))
	    c -= '0';
	else if (islower (c))
	    c -= 'a' - 10;
	else if (isupper (c))
	    c -= 'A' - 10;
	else
	    break;

	/* base チェック */
	if (c >= base)
	    break;

	/* オーバーフローチェック */
	if (over == 0) {

	    /* 符号により */
	    if (sign == 0) {

		/* 値チェック */
		if (val > (LONG_MAX - c) / base) {
		    val = LONG_MAX;
		    errno = ERANGE;
		    over = 1;
		}

		/* 更新 */
		else {
		    val *= base;
		    val += c;
		}

	    }
	    else {

		/* 値チェック */
		if (val < (LONG_MIN + c) / base) {
		    val = LONG_MIN;
		    errno = ERANGE;
		    over = 1;
		}

		/* 更新 */
		else {
		    val *= base;
		    val -= c;
		}

	    }
	}

	/* 文字進行 */
	str++;

    }

    /* ポインタ設定 (整定数がない場合は先頭のアドレスを返す) */
    if (end)
	*end = (char *) ((str == save) ? top : str);

    /* 終わり */
    return val;
}
