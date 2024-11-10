/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: commit.c,v 1.1.1.1 1993/04/18 16:39:17 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/dos.h>
#include <errno.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int commit (int fd)
{
    /* ファイルハンドルチェック */
    if (_writable (fd) < 0) {
	errno = EBADF;
	return -1;
    }

    /*
    ** Human68k ではファイルハンドルごとにデータをフラッシュできない
    ** ので、全部フラッシュする。
    */
    _dos_fflush ();

    return 0;
}
