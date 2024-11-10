/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: puts.c,v 1.1.1.1 1993/04/18 16:23:03 mura Exp $
 */

/* System headers */
#include <stdio.h>

/* Functions */
int puts (const char *string)
{
    /* 標準出力に出す */
    return (fputs (string, stdout) < 0 || fputc ('\n', stdout) < 0)
	? EOF : 0;
}
