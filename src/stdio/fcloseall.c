/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fcloseall.c,v 1.3 1993/05/15 15:38:01 mura Exp $
 */

/* System headers */
#include <stdio.h>

/* Functions */
int fcloseall (void)
{
    int i;
    int rc = 0;

    /* 全てのストリームを閉じる */
    for (i = 0; i < FOPEN_MAX; i++) {

	/* 最低限ストリームを flush する */
	if (_iob[i]._flag != 0)
	    if (fflush (&_iob[i]) < 0)
		rc = -1;

	/* アプリケーションでオープンされた場合に限ってクローズ */
	if (_iob[i]._flag & _IOAPPLS)
	    if (fclose (&_iob[i]) < 0)
		rc = -1;

    }

    /* 戻る */
    return rc;
}
