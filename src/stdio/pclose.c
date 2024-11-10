/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: pclose.c,v 1.2 1994/05/02 16:50:13 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* Functions */
int pclose (FILE *stream)
{
    int rc;
    char comline[512];
    epipe_t *ep;

    /* パイプデータを取得 */
    ep = &_pipes[stream->_file];

    /* オープンされているか? */
    if (ep->mode == inactive) {
	errno = EINVAL;
	return -1;
    }

    /* 読み込みモードならば... */
    else if (ep->mode == read_mode) {

	/* ファイルをクローズ */
	rc = fclose (stream);

	/* テンポラリファイルを削除 */
	unlink (ep->temporary);

    }

    /* 書き込みモードならば... */
    else {

	/* ファイルをクローズ */
	fclose (stream);

	/* 実行コマンドラインを生成 */
	sprintf (comline, "%s < %s", ep->command, ep->temporary);

	/* コマンドを実行 */
	rc = system (comline);

	/* テンポラリファイルを削除 */
	unlink (ep->temporary);

    }

    /* パイプデータを消去 */
    ep->mode = inactive;

    /* 確保したメモリを解放 */
    free ((void *) ep->command);
    free ((void *) ep->temporary);

    /* rc を返す */
    return rc;
}
