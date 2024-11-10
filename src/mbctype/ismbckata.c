/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbckata.c,v 1.2 1993/06/22 07:13:12 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbckata

/* Functions */
int ismbckata (int c)
{
    /* 全角カタカナか */
    return (c >= 0x8340 && c <= 0x837e) || (c >= 0x8380 && c <= 0x8396);
}
