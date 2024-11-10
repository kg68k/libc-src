/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: isblank.c,v 1.4 1994/05/02 16:34:49 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef isblank

/* Functions */
int isblank (int c)
{
    /* ブランク文字 */
    return (c == ' ' || c == '\t');
}
