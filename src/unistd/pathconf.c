/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: pathconf.c,v 1.1.1.1 1993/04/18 16:40:07 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
long pathconf (const char *path, int name)
{
    int rc;
    char pathname[PATH_MAX + 1];

    /* path の最後の / を取り除く */
    _dellastsep (strcpy (pathname, path));

    /* ファイルが存在するか */
    if ((rc = _dos_chmod (path, -1)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    /* config を調べる */
    return _pathconf (name);
}
