/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ultoa.c,v 1.1 1993/05/06 13:04:57 mura Exp $
 */

/* System headers */
#include <stdlib.h>

/* Functions */
char *ultoa (unsigned long value, char *string, int radix)
{
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

    /* value が 0 になるまで変換 */
    do {
	*--p = digits[value % radix];
	value /= radix;
    } while (value > 0);

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
