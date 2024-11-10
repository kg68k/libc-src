/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: lseek.c,v 1.4 1994/11/26 15:11:13 mura Exp $
 */

/* System headers */
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Macros */
#define EXPSTEPSIZ 1024

/* Functions */
off_t lseek (int fileno, long offset, int whence)
{
    long curpos, eofpos;
    long target;
    long rc, step;
    char zero[EXPSTEPSIZ];

#ifdef EBADF_CHECKER
    /* 不正なファイルハンドルチェック */
    if (_usedfd (fileno) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* キャラクタデバイスではシークできない */
    if (_fddb[fileno].cdev) {

	/* テキスト EOF マーカーを消す */
	_fddb[fileno].oflag &= ~O_TXTEOF;

	/* シークできなくてもエラーではない */
	return 0;

    }

    /* 現在位置と、最後の位置を求める */
    curpos = _dos_seek (fileno, 0, 1);
    eofpos = _dos_seek (fileno, 0, 2);

    /* 目標位置を求める */
    if (whence == 1)
	target = curpos + offset;
    else if (whence == 2)
	target = eofpos + offset;
    else if (whence == 0)
	target = offset;
    else {
	errno = EINVAL;
	return -1;
    }

    /* オフセットチェック */
    if (target < 0) {
	errno = EINVAL;
	return -1;
    }

    /* EOF を越えての拡張 */
    if (target > eofpos) {

	/* 書き込みできるのか */
	if (_writable (fileno) < 0) {
	    errno = EBADF;
	    return -1;
	}

	/* 書き込み用のヌルデータを作成 */
	memset (zero, '\0', EXPSTEPSIZ);

	/* target までヌルデータを書き込む */
	while (eofpos < target) {
	    step = target - eofpos;
	    step = (step > EXPSTEPSIZ) ? EXPSTEPSIZ : step;
	    eofpos += step;
	    if ((rc = _dos_write (fileno, zero, step)) < 0) {
		errno = _errcnv (rc);
		return -1;
	    }
	}

    }
    else {

	/* 現実にシークする */
	if ((rc = _dos_seek (fileno, target, 0)) < 0) {
	    errno = _errcnv (rc);
	    return rc;
	}

	/* テキスト EOF マーカーを消す */
	_fddb[fileno].oflag &= ~O_TXTEOF;

    }

    return target;
}
