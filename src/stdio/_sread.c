/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sread.c,v 1.5 1994/07/27 13:48:52 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* Functions */
int _sread (FILE *fp)
{
    int i, n;
    FILE *p;

    /* EOF フラグが立っていたら、終り */
    if (fp->_flag & _IOEOF) {
	fp->_cnt = 0;
	return EOF;
    }

    /* 制限チェック */
    if ((fp->_flag & (_IOREAD | _IOW)) != _IOREAD) {
	fp->_flag |= _IOERR;
	return EOF;
    }

    /* 読み込みモードにする */
    fp->_flag |= _IOR;

    /*
    ** non-buffering, line-buffering なら、他のストリームの中で書き込み中
    ** かつ行バッファリング、バッファリング中のものをフラッシュする
    */
    if (fp->_flag & (_IONBF | _IOLBF)) {
	for (i = 0; i < FOPEN_MAX; i++) {
	    p = &_iob[i];
	    if ((p->_flag & (_IOW | _IOLBF)) == (_IOW | _IOLBF) && (p->_cnt > 0))
		fflush (p);
	}
    }

    /* バッファリングされたデータがあるなら、戻る */
    if (fp->_cnt > 0)
	return 0;

    /* 疑似ストリームの場合は新規読み出しはできない */
    if (fp->_flag & _IOEMU) {
	fp->_flag |= _IOEOF;
	return EOF;
    }

    /* データを読み込む */
    else if ((n = read (fp->_file, (char *) fp->_base, fp->_bufsiz)) < 0) {
	fp->_flag |= _IOERR;
	return EOF;
    }

    /* EOF に到達したら... */
    else if (n == 0) {
	fp->_flag |= _IOEOF;
	fp->_cnt = 0;
	return EOF;
    }

    /* 正常に読み出せたなら... */
    else {
	fp->_flag &= ~(_IOEOF | _IOERR);
	fp->_ptr = fp->_base;
	fp->_cnt = n;
	return 0;
    }
}
