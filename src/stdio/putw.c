/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: putw.c,v 1.3 1994/07/27 13:49:26 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <sys/xstdio.h>

/* Functions */
int putw (int w, FILE *fp)
{
    /* ロングワードを fwrite する */
    if (fwrite (&w, sizeof (int), 1, fp) < 1)
	return -1;

    /* 成功 */
    return 0;
}
