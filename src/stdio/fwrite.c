/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fwrite.c,v 1.3 1994/07/27 13:49:13 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* Functions */
size_t fwrite (const void *ptr, size_t size, size_t num, FILE *fp)
{
    size_t able;
    size_t total, bytes;

    /* バイト数を調べる */
    if ((bytes = (unsigned int) (size * num)) <= 0)
	return 0;

    /* 書き込みループ */
    for (total = 0; bytes > 0; total += able) {

	/* 書き込み側バッファ処理 */
	if (_swrite (fp) < 0)
	    break;

	/* バッファに書き込める量を調べる */
	able = (bytes > fp->_cnt) ? fp->_cnt : bytes;

	/* バッファへ転送 */
	memcpy (fp->_ptr, ptr, able);

	/* ポインタ調整 */
	ptr += able;
	fp->_ptr += able;

	/* カウンタ調整 */
	bytes -= able;
	fp->_cnt -= able;

    }

    /* 読み込んだ項目数を返す */
    return total / size;
}
