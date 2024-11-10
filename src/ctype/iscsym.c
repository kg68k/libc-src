/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iscsym.c,v 1.2 1993/06/06 06:05:36 mura Exp $
 */

/* System headers */
#include <ctype.h>
#undef iscsym

/* Functions */
int iscsym (int c)
{
    /* C のシンボル文字 */
    return (_ctype[c & 0xff] & _ISALNUM) || (c == '_');
}
