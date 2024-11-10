/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: chmod.c,v 1.4 1994/05/02 17:21:23 mura Exp $
 */

/* System headers */
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Macros */
#define OLDMASK (S_IEXEC | S_IREAD | S_IWRITE | S_IRDONLY | S_IEXBIT)
#define NEWMASK (S_IEXEC | S_IREAD | S_IWRITE)

/* Functions */
int chmod (const char *name, mode_t mode)
{
    int rc;
    mode_t newmode;
    char xname[PATH_MAX + 1];

    /* 最後の / を取り除く */
    _dellastsep (strcpy (xname, name));

    /* 現在のファイルモードを調べる */
    if ((rc = _dos_chmod (xname, -1)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    /* 新しいモードを計算する */
    newmode = _mode2unix (rc);
    newmode &= ~OLDMASK;
    newmode |= mode & NEWMASK;
    newmode = _mode2dos (newmode);

    /* 新しいモードに変更する */
    if ((rc = _dos_chmod (xname, newmode)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    /* 正常終了 */
    return 0;
}
