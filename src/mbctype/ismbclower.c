/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbclower.c,v 1.2 1993/05/06 13:01:30 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <mbctype.h>
#undef ismbclower

/* Functions */
int ismbclower (int c)
{
    /* 小文字 */
    return ((c) >= 0x8281 && (c) <= 0x829a);
}
