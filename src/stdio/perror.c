/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: perror.c,v 1.1.1.1 1993/04/18 16:22:57 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <string.h>

/* Functions */
void perror (const char *string)
{
    /* string があれば表示する */
    if (string && *string)
	fprintf (stderr, "%s: ", string);

    /* エラーメッセージを出す */
    fprintf (stderr, "%s\n", strerror (errno));
}
