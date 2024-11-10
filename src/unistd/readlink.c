/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: readlink.c,v 1.1.1.1 1993/04/18 16:40:12 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int readlink (const char *path, char *buff, int bufsiz)
{
    int rc;

    /* 実際に symblic link を読み込む */
    if ((rc = _dos_readlink (path, buff, bufsiz)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    return rc;
}
