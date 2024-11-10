/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbctokata.c,v 1.4 1993/06/24 18:18:34 mura Exp $
 */

/* System headers */
#include <mbctype.h>

/* Functions */
int mbctokata (int c)
{
    /* 全角ひらがな->カタカナ変換 */
    if (c >= 0x829f && c <= 0x82dd)
	return c + 0xa1;
    else if (c >= 0x82de && c <= 0x82f1)
	return c + 0xa2;
    else
	return c;
}
