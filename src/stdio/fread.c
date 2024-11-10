/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fread.c,v 1.3 1994/07/27 13:49:06 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* Functions */
size_t fread (void *ptr, size_t size, size_t num, FILE *fp)
{
    size_t able;
    size_t bytes, total;

    /* バイト数を調べる */
    if ((bytes = (unsigned int) (size * num)) <= 0)
	return 0;

    /* 読み込みループ */
    for (total = 0; bytes > 0; total += able) {

	/* 読み込みバッファ処理 */
	if (_sread (fp) < 0)
	    break;

	/* バッファから読み出せる量を調べる */
	able = (bytes > fp->_cnt) ? fp->_cnt : bytes;

	/* バッファから転送 */
	memcpy (ptr, fp->_ptr, able);

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
