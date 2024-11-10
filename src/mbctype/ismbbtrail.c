/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbbtrail.c,v 1.2 1993/06/06 06:07:58 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbbtrail

/* Functions */
int ismbbtrail (int c)
{
    /* SJIS 2 バイト目 */
    return (_mbctype[c & 0xff] & _MTRAIL);
}
