/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: rmdir.c,v 1.1.1.1 1993/04/18 16:40:14 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int rmdir (const char *path)
{
    int rc;
    char dir[PATH_MAX + 1];

    /* path の最後の / を取り除く */
    _dellastsep (strcpy (dir, path));

    /* 実際に削除する */
    if ((rc = _dos_rmdir (dir)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    return 0;
}
