/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: gets.c,v 1.2 1993/05/15 15:38:09 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* Functions */
char *gets (char *buffer)
{
    int n, hope;
    char *ptr;
    unsigned char *mark;

    /* n は 0x01000000 (無制限) だが、CHAR デバイスなら MAX_CANON である */
    n = isatty (stdin->_file) ? MAX_CANON : 0x10000000;
    ptr = buffer;

    /* n - 1 文字取り出す */
    while (n > 0) {

	/* 読み込み側バッファ処理 */
	if (_sread (stdin) < 0) {
	    *ptr = '\0';
	    return 0;
	}

	/* 読み出す文字数を求める */
	hope = (n > stdin->_cnt) ? stdin->_cnt : n;

	/* バッファ中に NEWLINE はあるか */
	if (mark = memchr (stdin->_ptr, '\n', hope)) {
	    hope = mark - stdin->_ptr + 1;
	    memcpy (ptr, stdin->_ptr, hope - 1);
	    stdin->_cnt -= hope;
	    ptr         += hope - 1;
	    stdin->_ptr += hope;
	    break;
	}

	/* データを転送して次回を待つ */
	memcpy (ptr, stdin->_ptr, hope);
	n           -= hope;
	stdin->_cnt -= hope;
	ptr         += hope;
	stdin->_ptr += hope;

    }

    /* null で打ち止める */
    *ptr = '\0';

    /* buffer を返す */
    return buffer;
}
