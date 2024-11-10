/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fchmod.c,v 1.1.1.1 1993/04/18 16:37:51 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <sys/stat.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int fchmod (int fd, mode_t mode)
{
#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* ハンドルが指すファイルをモード変更 */
    return chmod (_fddb[fd].abspath, mode);
}
