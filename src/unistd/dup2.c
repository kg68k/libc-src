/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: dup2.c,v 1.3 1994/07/27 13:53:17 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int dup2 (int fd1, int fd2)
{
    int rc;

#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd1) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* fd1 と fd2 が同じ場合は... */
    if (fd1 == fd2)
	return fd2;

    /* まず fd2 をクローズする */
    if (_usedfd (fd2) >= 0)
	close (fd2);

    /* 実際に dup2 する */
    if ((rc = _dos_dup2 (fd1, fd2)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    /* fd2 に対する _handles 構造体を作成する */
    if (_open (_fddb[fd1].abspath, fd2, _fddb[fd1].oflag) < 0)
	return -1;

    /* fd2 を返す */
    return fd2;
}
