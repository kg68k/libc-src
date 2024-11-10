/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: tolower.c,v 1.2 1993/06/06 06:06:19 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef tolower

/* Functions */
int tolower (int c)
{
    /* 小文字に変換 */
    return _ctype_lower[c & 0xff];
}
