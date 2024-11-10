/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _usedfd.c,v 1.3 1994/07/27 13:53:11 mura Exp $
 */

/* System headers */
#include <limits.h>
#include <sys/xunistd.h>

/* Functions */
int _usedfd (int fd)
{
    /* fd の妥当性をチェックする */
    if (fd < 0 || fd >= OPEN_MAX)
	return -1;

    /* 使用中かどうか調べる */
    if (_fddb[fd].inuse == _FD_NOTUSED)
	return -1;

    /* 使用中 */
    return 0;
}
