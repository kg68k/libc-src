/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mkdir.c,v 1.2 1993/08/16 13:40:59 mura Exp $
 */

/* System headers */
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <sys/dos.h>
#include <sys/stat.h>
#include <sys/xglob.h>

/* Functions */
int mkdir (const char *path, mode_t mode)
{
    int rc;
    mode_t newmode;
    char dir[PATH_MAX + 1];

    /* path の最後の / を取り除く */
    _dellastsep (strcpy (dir, path));

    /* 実際に mkdir する */
    if ((rc = _dos_mkdir (dir)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    /* umask を適用する */
    newmode = mode & ~_umask;
    newmode &= ~S_IFMT;
    newmode |= S_IFDIR;

    /* モード変更を行う */
    if (chmod (dir, newmode) < 0)
	return -1;

    /* 正常終了 */
    return 0;
}
