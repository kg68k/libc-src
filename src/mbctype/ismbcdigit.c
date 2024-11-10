/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbcdigit.c,v 1.2 1993/05/06 13:01:21 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <mbctype.h>
#undef ismbcdigit

/* Functions */
int ismbcdigit (int c)
{
    /* 数字 */
    return ((c) >= 0x824f && (c) <= 0x8258);
}
