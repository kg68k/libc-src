/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: readdir.c,v 1.2 1993/06/06 06:06:30 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

/* Functions */
struct dirent *readdir (DIR *dirp)
{
    /* *dirp が NULLならエラー */
    if (dirp->dp == 0) {
	errno = ENOENT;
	return 0;
    }

    /* ファイルが見つからなければ NULL を返す (errno は変化しない) */
    if (dirp->loc >= dirp->filemax)
	return 0;

    /* dirent のポインタを返す */
    return &dirp->dp[dirp->loc++];
}
