/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ftell.c,v 1.2 1993/05/21 14:06:07 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>

/* Functions */
long ftell (FILE *fp)
{
    long offset;

    /* オフセットを求める */
    if ((offset = tell (fp->_file)) < 0)
	return -1;

    /* 現在のモードを調べる */
    if (fp->_flag & _IOW) {

	/* 書き込みモードに対する補正オフセットを求める */
	offset += fp->_bufsiz - fp->_cnt;

    }
    else if (fp->_flag & _IOR) {

	/* 読み込みモードに対する補正オフセットを求める */
	offset -= fp->_cnt + fp->_nback;

    }

    /* 正常終了 */
    return offset;
}
