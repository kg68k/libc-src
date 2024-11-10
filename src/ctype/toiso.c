/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: toiso.c,v 1.1.1.1 1993/04/18 16:16:48 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef toiso

/* Functions */
int toiso (int c)
{
    /* 8bit ISO に変換 */
    return (c & 0xff);
}
