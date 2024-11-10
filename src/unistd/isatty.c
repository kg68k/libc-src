/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: isatty.c,v 1.3 1994/11/26 15:10:59 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <sys/xunistd.h>

/* Functions */
int isatty (int fd)
{
#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return 0;
    }
#endif

    /* キャラクタデバイスであり */
    if (_fddb[fd].cdev) {

	/* 標準入出力と結び付いていることが条件 */
	if (_fddb[fd].iomd & (_DEV_STDIN | _DEV_STDOUT))
	    return 1;

    }

    /* エラーコード設定 */
    errno = ENOTTY;

    /* それ以外は全てNO */
    return 0;
}
