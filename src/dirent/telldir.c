/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: telldir.c,v 1.1.1.1 1993/04/18 16:17:00 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

/* Functions */
long telldir (DIR *dirp)
{
    /* dp が NULL ならエラー */
    if (dirp->dp == 0) {
	errno = ENOENT;
	return -1;
    }

    /* 位置を返す */
    return dirp->loc;
}
