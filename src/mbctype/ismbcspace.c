/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbcspace.c,v 1.2 1993/05/06 13:01:39 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <mbctype.h>
#undef ismbcspace

/* Functions */
int ismbcspace (int c)
{
    /* 空白文字 */
    return ((c) == 0x8140);
}
