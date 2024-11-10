/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setmode.c,v 1.3 1994/11/26 15:11:43 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/xunistd.h>

/* Functions */
int setmode (int fd, int mode)
{
    int old;

#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* 元の mode を取得 */
    old = _fddb[fd].oflag & (O_TEXT | O_BINARY);

    /* mode を設定 */
    _fddb[fd].oflag &= ~(O_TEXT | O_BINARY);
    _fddb[fd].oflag |= mode & (O_TEXT | O_BINARY);

    /* 成功 */
    return old;
}
