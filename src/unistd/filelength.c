/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: filelength.c,v 1.2 1993/05/15 15:41:25 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/dos.h>
#include <errno.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
long filelength (int fd)
{
    int rc;
    long curpos, length;

#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* ファイルの長さを調べる */
    curpos = _dos_seek (fd, 0, 1);
    length = _dos_seek (fd, 0, 2);

    /* 元に戻す */
    if ((rc = _dos_seek (fd, curpos, 0)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    return length;
}
