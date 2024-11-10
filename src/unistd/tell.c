/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: tell.c,v 1.2 1994/11/26 15:12:32 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
long tell (int fileno)
{
    long pos;

#ifdef EBADF_CHECKER
    /* 不正なファイルハンドルチェック */
    if (_usedfd (fileno) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* キャラクタデバイスでは不可能 */
    if (_fddb[fileno].cdev) {
	errno = ESPIPE;
	return -1L;
    }

    /* 位置を求める */
    if ((pos = _dos_seek (fileno, 0, 1)) < 0) {
	errno = _errcnv (pos);
	return -1;
    }

    /* 位置を返す */
    return pos;
}
