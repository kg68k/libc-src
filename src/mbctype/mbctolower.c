/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbctolower.c,v 1.1.1.1 1993/04/18 16:19:21 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef mbctolower

/* Functions */
int mbctolower (int c)
{
    /* 全角大文字->小文字変換 */
    return ismbcupper (c) ? c + 0x21 : c;
}
