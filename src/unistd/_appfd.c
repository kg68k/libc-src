/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _appfd.c,v 1.1 1993/05/06 13:43:21 mura Exp $
 */

/* System headers */
#include <limits.h>
#include <sys/xunistd.h>

/* Functions */
int _appfd (int fd)
{
    /* fd の妥当性をチェックする */
    if (fd < 0 || fd >= OPEN_MAX)
	return -1;

    /* アプリケーションが使用しているファイルハンドルかどうか調べる */
    if (_fddb[fd].inuse != _FD_APPLICATION)
	return -1;

    return 0;
}
