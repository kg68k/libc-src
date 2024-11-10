/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbbkana.c,v 1.2 1993/06/06 06:07:36 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbbkana

/* Functions */
int ismbbkana (int c)
{
    /* カナ文字、カナ記号 */
    return (_mbctype[c & 0xff] & _MBKANA);
}
