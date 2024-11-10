/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _seekeof.c,v 1.2 1993/05/06 13:43:51 mura Exp $
 */

/* System headers */
#include <fcntl.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int _seekeof (int fd, int mode)
{
    int rc;
    char buf;

    /* バイナリーモード */
    if (mode & O_BINARY) {

	/* ファイルの最後に移動する */
	if ((rc = _dos_seek (fd, 0, 2)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

    } else {

	/* まずファイルの最後 -1 に移動する */
	if ((rc = _dos_seek (fd, -1, 2)) < 0)
	    return 0;

	/* 1バイト読んでみる */
	if ((rc = _dos_read (fd, &buf, 1)) <= 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

	/* EOF(1A) だったら 1 バイト戻る */
	if (buf == 0x1a && (rc = _dos_seek (fd, -1, 1)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}
    }

    /* 戻る */
    return 0;
}
