/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getw.c,v 1.3 1994/07/27 13:49:20 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <sys/xstdio.h>

/* Functions */
int getw (FILE *fp)
{
    int w;

    /* ロングワードを fread する */
    if (fread (&w, sizeof (int), 1, fp) < 1)
	return EOF;

    /* w を返す */
    return w;
}
