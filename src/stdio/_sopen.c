/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sopen.c,v 1.2 1993/05/06 13:03:30 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/xstdio.h>

/* Functions */
int _sopen (FILE *fp, const char *mode, int type)
{
    int c, unimd;
    int bufsiz;
    short flag;
    unsigned char *ptr;

    {
	/* mode 文字列の先頭の r,w,a を判別する */
	switch (*mode++) {
	case 'r':
	    flag = _IOREAD;
	    break;
	case 'w':
	    flag = _IOWRITE | _IOCREAT | _IOTRUNC;
	    break;
	case 'a':
	    flag = _IOWRITE | _IOREAD | _IOCREAT | _IOAPPEND;
	    break;
	default:
	    errno = EINVAL;
	    return -1;
	}

	/* 後続の +,b,t 修飾子を判別する */
	while (c = *mode++) {
	    switch (c) {
	    case '+':
		flag |= _IOREAD | _IOWRITE;
		break;
	    case 'b':
		flag |= _IOBIN;
		break;
	    case 't':
		flag &= ~_IOBIN;
		break;
	    default:
		errno = EINVAL;
		return -1;
	    }
	}
    }

    {
	/* _IONBF の時は自前のバッファを利用する */
	if (type == _IONBF) {
	    bufsiz = 1;
	    ptr = fp->_nbuff;
	}

	/* バッファのメモリを確保する */
	else {
	    bufsiz = BUFSIZ;
	    flag |= _IOFREE;
	    if ((ptr = (unsigned char *) malloc (bufsiz)) == 0)
		return -1;
	}
    }

    {
	/* FILE 構造体を設定 */
	fp->_bufsiz   = bufsiz;
	fp->_cnt      = 0;
	fp->_base     = ptr;
	fp->_ptr      = ptr;
	fp->_flag     = flag | type | _IOAPPLS;
	fp->_file     = -1;
	fp->_nback    = 0;
    }

    {
	/* 標準入出力フラグを UNIX オープンモードに変換する */
	if ((flag & _IOUPD) == _IOUPD)
	    unimd = O_RDWR;
	else if (flag & _IOWRITE)
	    unimd = O_WRONLY;
	else
	    unimd = O_RDONLY;

	/* CREAT フラグを処理する */
	if (flag & _IOCREAT)
	    unimd |= O_CREAT;

	/* TRUNC フラグを処理する */
	if (flag & _IOTRUNC)
	    unimd |= O_TRUNC;

	/* APPEND フラグを処理する */
	if (flag & _IOAPPEND)
	    unimd |= O_APPEND;

	/* BINARY フラグを処理する */
	if (flag & _IOBIN)
	    unimd |= O_BINARY;
    }

    return unimd;
}
