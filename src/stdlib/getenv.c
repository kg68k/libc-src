/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getenv.c,v 1.1.1.1 1993/04/18 16:24:19 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Functions */
char *getenv (const char *name)
{
    int len;
    char **ptr;

    /* name の長さを調べる */
    len = strlen (name);

    /* environ 環境から該当する名前を探す */
    for (ptr = environ; *ptr; ptr++) {
	if (strncmp (*ptr, name, len) == 0 && (*ptr)[len] == '=') {
	    return *ptr + len + 1;
	}
    }

    return 0;
}
