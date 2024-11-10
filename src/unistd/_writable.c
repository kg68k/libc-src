/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _writable.c,v 1.2 1993/05/06 13:44:11 mura Exp $
 */

/* System headers */
#include <limits.h>
#include <fcntl.h>
#include <sys/xunistd.h>

/* Functions */
int _writable (int fd)
{
    /* fd の妥当性をチェックする */
    if (fd < 0 || fd >= OPEN_MAX)
	return -1;

    /* 使用中かどうか調べる */
    if (_fddb[fd].inuse == _FD_NOTUSED)
	return -1;

    /* 書き込み可能かどうか */
    if ((_fddb[fd].oflag & (O_RDWR | O_WRONLY)) == 0)
	return -1;

    return 0;
}
