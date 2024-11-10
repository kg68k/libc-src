/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: seekdir.c,v 1.2 1993/08/16 13:34:04 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

/* Functions */
int seekdir (DIR *dirp, long off)
{
    /* *dirp が NULL か offset が負か offset か filemax を越えたらエラー */
    if (dirp->dp == 0 || off < 0 || off >= dirp->filemax) {
	errno = ENOENT;
	return -1;
    }

    /* シーク */
    dirp->loc = off;

    /* 正常終了 */
    return 0;
}
