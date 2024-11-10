/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbcl0.c,v 1.1.1.1 1993/04/18 16:19:05 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbcl0

/* Functions */
int ismbcl0 (int c)
{
    /* 非漢字か */
    return (c >= 0x8140 && c <= 0x889e);
}
