/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sysroot.c,v 1.2 1993/08/16 13:34:27 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/xglob.h>

/* Macros */
#define DEFAULT_DRIVE "A:"

/* Functions */
char *_sysroot (char *buffer, const char *path, size_t size)
{
    char *root, *src;
    char fname[PATH_MAX + 1];

    /* 環境変数 SYSROOT を見る */
    if (root = getenv ("SYSROOT")) {

	/* あらかじめ長さチェック */
	if (strlen (root) >= PATH_MAX) {
	    errno = ENAMETOOLONG;
	    return 0;
	}

	/* SYSROOT が設定されていれば結果は $SYSROOT$path */
	src = _dellastsep (strcpy (fname, root));

    }
    else {

	/* されていなければ結果は $DEFAULT_DRIVE$path となる */
	src = DEFAULT_DRIVE;

    }

    /* 長さをチェックする */
    if (strlen (src) + strlen (path) + 1 > size) {
	errno = ENAMETOOLONG;
	return 0;
    }

    /* ファイル名を生成 */
    return strcat (strcpy (buffer, src), path);
}
