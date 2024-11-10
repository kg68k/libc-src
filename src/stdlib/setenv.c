/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setenv.c,v 1.1 1993/06/06 06:09:55 mura Exp $
 */

/* System headers */
#include <alloca.h>
#include <stdlib.h>
#include <string.h>

/* Functions */
int setenv (const char *name, const char *value, int overwrite)
{
    char *ptr;

    /* 見つからないか、見つかって、かつ overwrite が true なら */
    if (getenv (name) == 0 || overwrite) {

	/* テンポラリ文字列の領域を確保する */
	ptr = (char *) alloca (strlen (name) + strlen (value) + 2);

	/* テンポラリ文字列を作成する */
	strcpy (ptr, name);
	strcat (ptr, "=");
	strcat (ptr, value);

	/* putenv する */
	return putenv (ptr);

    }

    /* 正常終了 */
    return 0;
}
