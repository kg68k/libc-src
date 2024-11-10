/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mkstemp.c,v 1.1.1.1 1993/04/18 16:24:30 mura Exp $
 */

/* System headers */
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

/* Functions */
int mkstemp (char *template)
{
    char *tmp;

    /* テンプレート作成 */
    if ((tmp = mktemp (template)) == 0)
	return -1;

    /* オープンする */
    return open (tmp, O_WRONLY | O_RDONLY | O_CREAT | O_TRUNC, 0666);
}
