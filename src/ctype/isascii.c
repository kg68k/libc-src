/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: isascii.c,v 1.1.1.1 1993/04/18 16:16:26 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef isascii

/* Functions */
int isascii (int c)
{
    /* 7bit ASCII 文字 */
    return (c & ~127) == 0;
}
