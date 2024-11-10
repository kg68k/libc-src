/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: dup.c,v 1.2 1993/08/16 13:41:40 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int dup (int fd)
{
    int newfd;

#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* 実際に dup する */
    if ((newfd = _dos_dup (fd)) < 0) {
	errno = _errcnv (newfd);
	return -1;
    }

    /* newfd に対する _handles 構造体を作成する */
    if (_open (_fddb[fd].abspath, newfd, _fddb[fd].oflag) < 0)
	return -1;

    /* newfd を返す */
    return newfd;
}
