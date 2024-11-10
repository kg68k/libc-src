/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbctohira.c,v 1.3 1993/06/24 18:17:41 mura Exp $
 */

/* System headers */
#include <mbctype.h>

/* Functions */
int mbctohira (int c)
{
    /* 全角カタカナ->ひらがな変換 */
    if (c >= 0x8340 && c <= 0x837e)
	return c - 0xa1;
    else if (c >= 0x8380 && c <= 0x8396)
	return c - 0xa2;
    else
	return c;
}
