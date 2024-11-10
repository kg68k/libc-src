/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: toascii.c,v 1.1.1.1 1993/04/18 16:16:46 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef toascii

/* Functions */
int toascii (int c)
{
    /* 7bit ASCII に変換 */
    return (c & 0x7f);
}
