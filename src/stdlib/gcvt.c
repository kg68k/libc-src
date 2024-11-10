/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: gcvt.c,v 1.1.1.1 1993/04/18 16:24:17 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <string.h>
#include <sys/xmath.h>
#include <sys/xstdlib.h>

/* Functions */
char *gcvt (double value, int precision, char *buff)
{
    int last;

    /* 浮動小数点を G Format で変換する */
    (void) FPACK3 (__GCVT, value, buff, precision);

    /* 最後が小数点で終わるならば取り除く */
    last = strlen (buff) - 1;
    if (buff[last] == '.')
	buff[last] = '\0';

    /* buff を返す */
    return buff;
}
