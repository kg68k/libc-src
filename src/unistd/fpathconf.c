/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fpathconf.c,v 1.1.1.1 1993/04/18 16:39:38 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <sys/xunistd.h>

/* Functions */
long fpathconf (int fd, int name)
{
#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* config を調べる */
    return _pathconf (name);
}
