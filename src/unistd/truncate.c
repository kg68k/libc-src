/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: truncate.c,v 1.1.1.1 1993/04/18 16:40:47 mura Exp $
 */

/* System headers */
#include <fcntl.h>
#include <unistd.h>

/* Functions */
int truncate (const char *path, off_t newlen)
{
    int fd, rc;

    /* ファイルを書き込みモードでオープンする */
    if ((fd = open (path, O_RDWR)) < 0)
	return -1;

    /* 実際に trucate する */
    rc = ftruncate (fd, newlen);

    /* ファイルをクローズする */
    close (fd);

    return rc;
}
