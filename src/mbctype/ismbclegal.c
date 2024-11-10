/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbclegal.c,v 1.1.1.1 1993/04/18 16:19:09 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbclegal

/* Functions */
int ismbclegal (int c)
{
    /* 正しい漢字コードか */
    return (ismbblead (_MBGETH (c)) && ismbbtrail (_MBGETL (c)));
}
