/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: write.c,v 1.3 1993/08/16 13:42:10 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Macros */
#define TXWRITEBUFSIZ 2048

/* Functions */
int write (int fileno, const char *buffer, unsigned int bytes)
{
    int cpos, rc, count;
    int eof, decr, flag;
    char *wp, *rp;
    char wbuf[TXWRITEBUFSIZ + 1];

    /* 不正なファイルハンドルチェック */
    if (_writable (fileno) < 0) {
	errno = EBADF;
	return -1;
    }

    /* 0 バイトなら何も行わない */
    if (bytes <= 0)
	return 0;

    /* APPEND ならばファイルの最後にシーク */
    if ((flag = _fddb[fileno].oflag) & O_APPEND) {
	if (_seekeof (fileno, flag) < 0)
	    return -1;
    }

    /* バイナリモード時の処理 */
    if (flag & O_BINARY) {

	/* バイナリモードではただ書くだけ */
	if ((count = _dos_write (fileno, buffer, bytes)) < 0) {
	    errno = _errcnv (count);
	    return -1;
	}

	/* エラーか? */
	else if (count != bytes) {
	    errno = ENOSPC;
	    return -1;
	}

    }
    else {

	/* 変数初期化 */
	decr = bytes;
	rp = (char *) buffer;
	wp = wbuf;
	eof = cpos = count = 0;

	/* 終わりになるまで書き込む */
	while (!eof) {

	    /* LF->CR/LF 変換 */
	    if (*rp == '\n') {
		*wp++ = '\r';
		cpos++;
	    }

	    /* バッファに転送 */
	    *wp++ = *rp++;
	    cpos++;
	    count++;

	    /* 全部変換し終わったら EOF */
	    if (--decr <= 0)
		eof = 1;

	    /* バッファリング処理 */
	    if (eof || cpos >= TXWRITEBUFSIZ) {

		/* バッファの内容を書き出す */
		if ((rc = _dos_write (fileno, wbuf, cpos)) < cpos) {

		    /* 完全にエラーなら... */
		    if (rc < 0) {
			errno = _errcnv (rc);
			return -1;
		    }

		    /* そうでなければ... */
		    else {

			/* 実際に書き込んだバイト数を返す */
			return count - cpos + rc;

		    }

		}

		/* カウンタ初期化 */
		cpos = 0;
		wp = wbuf;

	    }

	}

    }

    /* 戻る */
    return count;
}
