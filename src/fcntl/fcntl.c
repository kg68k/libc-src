/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fcntl.c,v 1.1.1.1 1993/04/18 16:17:10 mura Exp $
 */

/* System headers */
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <sys/dos.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/xunistd.h>

/* Functions */
int fcntl (int fd, int cmd, ...)
{
    int tofd;
    va_list ap;

#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* cmd を解析する */
    switch (cmd) {

    case F_DUPFD:
	/* dup先ファイルハンドルを求める */
	va_start (ap, cmd);
	for (tofd = va_arg (ap, int); tofd < OPEN_MAX; tofd++)
	    if (_fddb[tofd].inuse == 0)
		break;
	va_end (ap);

	/* 見付からない? */
	if (tofd >= OPEN_MAX) {
	    errno = EMFILE;
	    return -1;
	}

	/* dup2 をコールする */
	return dup2 (fd, tofd);

    case F_GETFL:
	/* ファイルステータス＋アクセスフラグを取り出す */
	return _fddb[fd].oflag & (O_ACCMODE | O_STSMODE);

    case F_SETFL:
	/* ファイルステータスフラグを設定する */
	va_start (ap, cmd);
	_fddb[fd].oflag &= ~O_STSMODE;
	_fddb[fd].oflag |= va_arg (ap, int) & O_STSMODE;
	va_end (ap);
	return 0;

    }

    /* cmd が不正 */
    errno = EINVAL;
    return -1;
}
