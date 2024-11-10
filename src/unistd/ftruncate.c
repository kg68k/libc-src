/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ftruncate.c,v 1.2 1994/11/26 15:10:45 mura Exp $
 */

/* System headers */
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int ftruncate (int fd, off_t newlen)
{
    int rc;
    char buf;

    /* ファイルハンドルチェック */
    if (_writable (fd) < 0) {
	errno = EBADF;
	return -1;
    }

    /* キャラクタデバイスはシークできない */
    if (_fddb[fd].cdev) {
	errno = EBADF;
	return -1;
    }

    /* newlen の位置へシークする (lseek ならば拡張もできる) */
    if (lseek (fd, newlen, 0) < 0)
	return -1;

    /* そこへ 0 バイトのデータを書き込む */
    if ((rc = _dos_write (fd, &buf, 0)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    return 0;
}
