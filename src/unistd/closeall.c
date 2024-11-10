/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: closeall.c,v 1.3 1994/11/26 15:10:14 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <sys/xunistd.h>

/* Functions */
int closeall (void)
{
    int i;
    int errsav = 0;
    int rc = 0;

    /* アプリケーションでオープンされたものだけクローズする */
    for (i = 0; i < OPEN_MAX; i++) {
	if (_appfd (i) >= 0 && close (i) < 0) {
	    errsav = errno;
	    rc = -1;
	}
    }

    /* エラーだった場合は errno を復活させてからリターン */
    if (rc < 0)
	errno = errsav;

    /* 戻る */
    return rc;
}
