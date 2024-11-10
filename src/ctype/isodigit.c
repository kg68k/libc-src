/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: isodigit.c,v 1.1.1.1 1993/04/18 16:16:38 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef isodigit

/* Functions */
int isodigit (int c)
{
    /* 8 進数字 */
    return (c >= '0' && c <= '7');
}
