/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: close.c,v 1.5 1994/11/26 15:10:00 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <unistd.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int close (int fd)
{
    int mode, rc;
    char *fname;

#ifdef EBADF_CHECKER
    /* 不正なファイルハンドルかどうか調べる */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* キャラクタデバイスか? */
    if (_fddb[fd].cdev) {

	/* アプリケーションのファイルハンドルだけ実際にクローズする */
	if ((rc = _dos_close (fd)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

    }

    /* ブロックデバイス... */
    else {

	/* ファイル名を取り出す */
	fname = _fddb[fd].abspath;

	/* 最後のファイルモードを取得する (Human のいけず) */
	mode = _dos_chmod (fname, -1);

	/* アプリケーションのファイルハンドルだけ実際にクローズする */
	if ((rc = _dos_close (fd)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

	/* 正常に取得できた場合、それが close 後に変化したかどうか */
	if (mode >= 0 && _dos_chmod (fname, -1) != mode)
	    _dos_chmod (fname, mode);

    }

    /* _handles 構造体を削除する */
    return _close (fd);
}
