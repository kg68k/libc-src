/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbcl1.c,v 1.1.1.1 1993/04/18 16:19:06 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbcl1

/* Functions */
int ismbcl1 (int c)
{
    /* 第 1 水準漢字か */
    return (c >= 0x889f && c <= 0x9872);
}
