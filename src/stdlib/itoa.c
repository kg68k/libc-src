/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: itoa.c,v 1.1 1993/05/06 13:04:40 mura Exp $
 */

/* System headers */
#include <stdlib.h>

/* Functions */
char *itoa (int value, char *string, int radix)
{
    int sign;
    char *p, *q;
    char buffer[32];
    static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";

    /* 基数範囲チェック */
    if (radix < 2 || radix > 36) {
	*string = '\0';
	return string;
    }

    /* p を buffer の最後 + 1 に */
    p = buffer + sizeof (buffer);

    /* 符号調整 */
    if (value >= 0)
	sign = 0;
    else {
	sign = 1;
	value = -value;
    }

    /* value が 0 になるまで変換 */
    do {
	*--p = digits[value % radix];
	value /= radix;
    } while (value > 0);

    /* 符号を設定 */
    if (sign)
	*--p = '-';

    /* buffer から string へコピー */
    q = string;
    do {
	*q++ = *p++;
    } while (p < buffer + sizeof buffer);

    /* null でターミネートする */
    *q = '\0';

    /* string を返す */
    return string;
}
