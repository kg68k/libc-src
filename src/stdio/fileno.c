/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fileno.c,v 1.1.1.1 1993/04/18 16:22:31 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <sys/xunistd.h>

/* Functions */
int fileno (FILE *fp)
{
#ifdef EBADF_CHECKER
    /* 有効なファイルハンドルか */
    if (_usedfd (fp->_file) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* ファイルハンドルを返す */
    return (int) fp->_file;
}
