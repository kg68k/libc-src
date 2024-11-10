/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: popen.c,v 1.2 1994/05/02 16:50:27 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/xstdio.h>

/* External variables */
epipe_t _pipes[OPEN_MAX];

/* Functions */
FILE *popen (const char *command, const char *mode)
{
    char *temp;
    char comline[512];
    epmode_t pmode;
    epipe_t *ep;
    FILE *fp;

    /* 読み込みモードか? */
    if (mode[0] == 'r' || mode[1] == 'r')
	pmode = read_mode;

    /* 書き込みモードか? */
    else if (mode[0] == 'w' || mode[1] == 'w')
	pmode = write_mode;

    /* 不正なモード */
    else {
	errno = EINVAL;
	return 0;
    }

    /* テンポラリファイルのファイル名を生成する */
    if ((temp = tmpnam (0)) == 0)
	return 0;

    /* 読み込みモードであれば... */
    if (pmode == read_mode) {

	/* コマンドラインを生成する */
	sprintf (comline, "%s > %s", command, temp);

	/* コマンドを実行 */
	system (comline);

	/* 入力ファイルをオープン */
	if ((fp = fopen (temp, mode)) == 0)
	    return 0;

    }

    /* 書き込みモードならば... */
    else {

	/* 出力ファイルをオープン */
	if ((fp = fopen (temp, mode)) == 0)
	    return 0;

    }

    /* パイプの実行データを記録する */
    ep = &_pipes[fp->_file];
    ep->mode = pmode;
    ep->temporary = strdup (temp);
    ep->command = strdup (command);

    /* fp を返す */
    return fp;
}
