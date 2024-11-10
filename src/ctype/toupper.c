/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: toupper.c,v 1.2 1993/06/06 06:06:24 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef toupper

/* Functions */
int toupper (int c)
{
    /* 大文字に変換 */
    return _ctype_upper[c & 0xff];
}
