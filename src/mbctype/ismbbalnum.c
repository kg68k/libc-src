/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbbalnum.c,v 1.2 1993/06/06 06:07:18 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbbalnum

/* Functions */
int ismbbalnum (int c)
{
    /* アルファベット、数字、カナ */
    return (_mbctype[c & 0xff] & _MBALNUM);
}
