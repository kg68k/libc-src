/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: d_symlink.c,v 1.1 1993/04/25 12:22:58 mura Exp $
 */

/* System headers */
#include <string.h>
#include <sys/dos.h>
#include <sys/xdoseml.h>

/* Functions */
int _dos_symlink (const char *src, const char *dst)
{
    int fd, rc;

    /* ファイルを作成する */
    if ((fd = _dos_newfile (dst, _DOS_IFREG)) < 0)
	return fd;

    /* リンク先を書き込む */
    if ((rc = _dos_write (fd, src, strlen (src))) < 0)
	return rc;

    /* ファイルをクローズ */
    _dos_close (fd);

    /* symbolic link bit を立てる */
    _dos_chmod (dst, _DOS_IFLNK);

    return 0;
}
