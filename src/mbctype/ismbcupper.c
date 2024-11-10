/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbcupper.c,v 1.2 1993/05/06 13:01:47 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <mbctype.h>
#undef ismbcupper

/* Functions */
int ismbcupper (int c)
{
    /* 大文字 */
    return ((c) >= 0x8260 && (c) <= 0x8279);
}
