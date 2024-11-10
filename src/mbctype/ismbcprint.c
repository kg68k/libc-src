/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ismbcprint.c,v 1.1.1.1 1993/04/18 16:19:12 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#undef ismbcprint

/* Functions */
int ismbcprint (int c)
{
    /* 表示可能か */
    return (_MBHMASK (c) ? ismbclegal (c) : (isprint (c) || ismbbkana (c)));
}
