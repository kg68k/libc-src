/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbbgraph.c,v 1.2 1993/06/06 06:07:27 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbbgraph

/* Functions */
int ismbbgraph (int c)
{
    /* 空白以外の表示可能文字 */
    return (_mbctype[c & 0xff] & _MBGRAPH);
}
