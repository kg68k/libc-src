/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbchira.c,v 1.1.1.1 1993/04/18 16:19:02 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbchira

/* Functions */
int ismbchira (int c)
{
    /* 全角平仮名か */
    return (c >= 0x829f && c <= 0x82f1);
}
