/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fgets.c,v 1.3 1994/07/31 17:23:52 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/xstdio.h>

/* Functions */
char *fgets (char *buffer, int n, FILE *fp)
{
    int hope;
    char *ptr;
    unsigned char *mark;

    /* 読み込みバッファのサイズは 1 以上 */
    if (--n < 0) {
	errno = EINVAL;
	return 0;
    }

    /* 読み込み側バッファ処理 */
    if (_sread (fp) < 0) {
	*buffer = '\0';
	return 0;
    }

    /* ポインタの初期化 */
    ptr = buffer;

    /* バッファサイズだけ取り出す */
    do {

	/* 読み出す文字数を求める */
	hope = (n > fp->_cnt) ? fp->_cnt : n;

	/* バッファ中に NEWLINE はあるか */
	if (mark = memchr (fp->_ptr, '\n', hope)) {
	    hope = mark - fp->_ptr + 1;
	    n = 0;
	}

	/* データを転送する */
	memcpy (ptr, fp->_ptr, hope);

	/* 各変数を転送した分だけ補正する */
	n -= hope;
	ptr += hope;
	fp->_cnt -= hope;
	fp->_ptr += hope;

    /* バッファサイズに満たないうちは何度でも */
    } while (n > 0 && _sread (fp) >= 0);

    /* null で打ち止める */
    *ptr = '\0';

    /* buffer を返す */
    return buffer;
}
