/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fputc.c,v 1.1.1.1 1993/04/18 16:22:39 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <sys/xstdio.h>

/* Functions */
int fputc (int character, FILE *fp)
{
    /* 書き込み側バッファ処理 */
    if (_swrite (fp) < 0)
	return EOF;

    /* カウンタを減算する */
    fp->_cnt--;

    /* バッファに一文字転送 */
    *fp->_ptr++ = (unsigned char) character;

    /* ノンバッファリング、ラインバッファリングの処理 */
    if (((fp->_flag & _IONBF)) ||
	((fp->_flag & _IOLBF) && (character == '\n'))) {
	if (fflush (fp) < 0)
	    return EOF;
    }

    /* 元の character を返す */
    return character;
}
