/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fflush.c,v 1.3 1993/08/16 13:35:42 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>

/* Functions */
int fflush (FILE *fp)
{
    int offset;

    /* fp が null ならば flushall と同じ */
    if (fp == 0)
	return flushall ();

    /* 現在のモードを調べる */
    if ((fp->_flag & _IOW) && (fp->_ptr > fp->_base)) {

	/* 書き込みモードならばバッファを全てフラッシュする */
	if (write (fp->_file, (const char *) fp->_base, fp->_bufsiz - fp->_cnt) <= 0) {
	    fp->_flag |= _IOERR;
	    return EOF;
	}

    }
    else if (fp->_flag & _IOR) {

	/* 補正オフセットを計算する */
	offset = -(fp->_cnt + fp->_nback);

	/* 読み込み中ならばファイルポインタの位置を調整する */
	if (lseek (fp->_file, offset, SEEK_CUR) < 0) {
	    fp->_flag |= _IOERR;
	    return EOF;
	}

    }

    /* FILE 構造体を初期化 */
    fp->_flag &= ~(_IOW | _IOR);
    fp->_ptr = fp->_base;
    fp->_cnt = 0;
    fp->_nback = 0;

    /* 成功 */
    return 0;
}
