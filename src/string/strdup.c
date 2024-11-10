/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strdup.c,v 1.1.1.1 1993/04/18 16:25:30 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/* Functions */
char *strdup (const char *string)
{
    size_t len;
    char *mptr;

    /* 新しいメモリを確保する */
    len = strlen (string) + 1;
    if ((mptr = (char *) malloc (len)) == 0)
	return 0;

    /* 元の文字列をコピーする */
    return strcpy (mptr, string);
}
