/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbcl2.c,v 1.1.1.1 1993/04/18 16:19:08 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbcl2

/* Functions */
int ismbcl2 (int c)
{
    /* 第 2 水準漢字か */
    return (c >= 0x989f && c <= 0xea9e);
}
