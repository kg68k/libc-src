/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getchar.c,v 1.1.1.1 1993/04/18 16:22:53 mura Exp $
 */

/* System headers */
#include <stdio.h>

/* Functions */
int getchar (void)
{
    /* 標準入力から取得する */
    return fgetc (stdin);
}
