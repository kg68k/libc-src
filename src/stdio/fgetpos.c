/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fgetpos.c,v 1.1.1.1 1993/04/18 16:22:28 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>

/* Functions */
int fgetpos (FILE *fp, fpos_t *pos)
{
    fpos_t offset;

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

    /* pos にデータを書き込む */
    *pos = offset;

    /* 正常終了 */
    return 0;
}
