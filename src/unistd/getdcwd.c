/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getdcwd.c,v 1.2 1993/05/21 14:11:24 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* File scope functions */
char *getdcwd (int drive, char *buff, int size)
{
    int rc, len;
    char cwd[PATH_MAX + 1];

    /* EINVAL チェック */
    if (size < 1) {
	errno = EINVAL;
	return 0;
    }

    /* 先頭の / を入れる */
    cwd[0] = '/';

    /* カレントディレクトリを調べる */
    if ((rc = _dos_curdir (drive, cwd + 1)) < 0) {
	errno = _errcnv (rc);
	return 0;
    }

    /* 全体の長さを調べる */
    len = strlen (cwd) + 1;

    /* buff が NULL なら malloc する */
    if (buff == 0) {

	/* 最低限 size バイトのサイズを求める */
	size = max (len, size);

	if ((buff = (char *) malloc (size)) == 0)
	    return 0;

    }

    /* ERANGE チェック */
    if (size < len) {
	errno = ERANGE;
	return 0;
    }

    /* データをコピーする */
    return strcpy (buff, _toslash (cwd));
}
