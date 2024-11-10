/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _swrite.c,v 1.1.1.1 1993/04/18 16:22:13 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* Functions */
int _swrite (FILE *fp)
{
    /* 制限チェック */
    if ((fp->_flag & (_IOWRITE | _IOR)) != _IOWRITE) {
	fp->_flag |= _IOERR;
	return EOF;
    }

    /* 書き込みでなければモードを初期化する */
    if ((fp->_flag & _IOW) == 0) {
	fp->_cnt = fp->_bufsiz;
	fp->_flag |= _IOW;
	return 0;
    }

    /* バッファリングする余地があるなら戻る */
    if (fp->_cnt > 0)
	return 0;

    /* データを書き込む */
    if (write (fp->_file, (const char *) fp->_base, fp->_bufsiz) <= 0) {
	fp->_flag |= _IOERR;
	return EOF;
    }

    /* 正常に書き込めたなら... */
    else {
	fp->_flag &= ~(_IOEOF | _IOERR);
	fp->_ptr = fp->_base;
	fp->_cnt = fp->_bufsiz;
	return 0;
    }
}
