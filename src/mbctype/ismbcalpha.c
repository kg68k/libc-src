/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbcalpha.c,v 1.3 1993/05/15 15:36:36 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <mbctype.h>
#undef ismbcalpha

/* Functions */
int ismbcalpha (int c)
{
    /* アルファベット */
    return (ismbcupper (c) || ismbclower (c));
}
