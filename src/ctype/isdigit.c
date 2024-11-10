/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: isdigit.c,v 1.2 1993/06/06 06:05:45 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef isdigit

/* Functions */
int isdigit (int c)
{
    /* 数字 */
    return (_ctype[c & 0xff] & _ISDIGIT);
}
