/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Passwd,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setpwent.c,v 1.1.1.1 1993/04/18 16:20:24 mura Exp $
 */

/* System headers */
#include <pwd.h>
#include <stdio.h>
#include <limits.h>
#include <sys/xglob.h>
#include <sys/xpwd.h>

/* Functions */
void setpwent (void)
{
    char path[PATH_MAX + 1];

    /* passwd ファイルがオープンされていなければ... */
    if (_pwd_fp == 0) {

	/* passwd ファイルのパス名を得る */
	if (_sysroot (path, _PATH_PASSWD, PATH_MAX) == 0)
	    return;

	/* passwd ファイルをオープンする */
	_pwd_fp = fopen (path, "rt");

    }
    else {

	/* オープンされていれば rewind する */
	rewind (_pwd_fp);

    }
}
