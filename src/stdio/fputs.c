/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fputs.c,v 1.1.1.1 1993/04/18 16:22:40 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <sys/xstdio.h>

/* Functions */
int fputs (const char *string, FILE *fp)
{
    int hope;
    const char *mark;

    /* 文字列を最後まで出力する */
    while (*string) {

	/* 書き込み側バッファ処理 */
	if (_swrite (fp) < 0)
	    return EOF;

	/* バッファリング方法別に出力する長さを決める */
	if ((fp->_flag & _IOLBF) && (mark = strchr (string, '\n')))
	    hope = mark - string + 1;
	else
	    hope = strlen (string);

	/* 出力可能な長さで切り詰める */
	if (hope > fp->_cnt)
	    hope = fp->_cnt;

	/* バッファにデータを転送する */
	memcpy (fp->_ptr, string, hope);
	string   += hope;
	fp->_ptr += hope;
	fp->_cnt -= hope;

	/* バッファをフラッシュするか */
	if (fp->_flag & (_IOLBF | _IONBF))
	    fflush (fp);
    }

    /* 戻る */
    return 0;
}
