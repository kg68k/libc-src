/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fgetc.c,v 1.1.1.1 1993/04/18 16:22:26 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <sys/xstdio.h>

/* Functions */
int fgetc (FILE *fp)
{
    /* 読み込み側バッファ処理 */
    if (_sread (fp) < 0)
	return EOF;

    /* push back バッファにデータがあれば、それを優先する */
    if (fp->_nback > 0)
	return fp->_pback[--fp->_nback];

    /* カウンタを減算 */
    fp->_cnt--;

    /* 読み込んだデータから一文字取り出す */
    return (int) *fp->_ptr++;
}
