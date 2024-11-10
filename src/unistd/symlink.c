/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: symlink.c,v 1.1.1.1 1993/04/18 16:40:38 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int symlink (const char *old, const char *new)
{
    int rc;

    /* 実際に symblic link を作成する */
    if ((rc = _dos_symlink (old, new)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    return 0;
}
