/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: isiso.c,v 1.1.1.1 1993/04/18 16:16:35 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef isiso

/* Functions */
int isiso (int c)
{
    /* 8bit ISO 文字 */
    return (c & ~255) == 0;
}
