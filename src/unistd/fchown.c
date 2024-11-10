/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fchown.c,v 1.1.1.1 1993/04/18 16:39:34 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <sys/xunistd.h>

/* Functions */
int fchown (int fd, uid_t owner, gid_t group)
{
#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /*
    ** Human68k ではファイルに所有者を設定することができない。そこで、ここでは
    ** すべてのユーザーは root であるとみなし、すべての chown 要求は成功するこ
    ** ととする。
    */
    return 0;
}
