/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: unsetenv.c,v 1.1 1993/06/06 06:09:58 mura Exp $
 */

/* System headers */
#include <alloca.h>
#include <stdlib.h>
#include <string.h>

/* Functions */
void unsetenv (const char *name)
{
    char *ptr;

    /* 見つかれば... 削除する */
    if (getenv (name)) {

	/* テンポラリ文字列の領域を確保する */
	ptr = (char *) alloca (strlen (name) + 2);

	/* テンポラリ文字列を作成する */
	strcpy (ptr, name);
	strcat (ptr, "=");

	/* putenv する */
	putenv (ptr);

    }
}
