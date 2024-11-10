/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: locking.c,v 1.1.1.1 1993/04/18 16:36:46 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <sys/locking.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int locking (int fd, int mode, long nbytes)
{
    int rc, i;
    long curpos;

#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* ファイルポインタを調べる */
    curpos = _dos_seek (fd, 0, 1);

    /* mode によって分岐 */
    switch (mode) {

    case LK_NBLCK:
    case LK_NBRLCK:
	/* 領域をロックする */
	if ((rc = _dos_lock (fd, curpos, nbytes)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}
	break;

    case LK_LOCK:
    case LK_RLCK:
	/* 回数をリセット */
	i = 0;

	/* 領域をロックする */
	do {

	    /* 10 回試してだめなら、DEADLOCK である */
	    if (++i > 10) {
		errno = EDEADLK;
		return -1;
	    }

	    /* 試行する */
	    rc = _dos_lock (fd, curpos, nbytes);

	} while (rc < 0);
	break;

    case LK_UNLCK:
	/* 領域をアンロックする */
	if ((rc = _dos_unlock (fd, curpos, nbytes)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}
	break;

    default:
	/* 引数がおかしい */
	errno = EINVAL;
	return -1;

    }

    return 0;
}
