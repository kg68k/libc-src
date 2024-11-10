/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: tcsetpgrp.c,v 1.2 1994/11/26 15:12:16 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <sys/xunistd.h>

/* Functions */
int tcsetpgrp (int fd, pid_t pgid)
{
#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* 端末じゃない */
    if (!isatty (fd)) {
	errno = ENOTTY;
	return -1;
    }

    /* 常に成功するが、変化は起こさない */
    return 0;
}
