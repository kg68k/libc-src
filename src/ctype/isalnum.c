/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: isalnum.c,v 1.2 1993/06/06 06:05:19 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef isalnum

/* Functions */
int isalnum (int c)
{
    /* アルファベット及び数字 */
    return (_ctype[c & 0xff] & _ISALNUM);
}