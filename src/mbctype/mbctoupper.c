/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbctoupper.c,v 1.1.1.1 1993/04/18 16:19:23 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef mbctoupper

/* Functions */
int mbctoupper (int c)
{
    /* 全角小文字->大文字変換 */
    return ismbclower (c) ? c - 0x21 : c;
}
