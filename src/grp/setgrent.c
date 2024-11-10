/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setgrent.c,v 1.1.1.1 1993/04/18 16:17:33 mura Exp $
 */

/* System headers */
#include <grp.h>
#include <stdio.h>
#include <sys/xglob.h>
#include <sys/xgrp.h>

/* Functions */
void setgrent (void)
{
    char path[PATH_MAX + 1];

    /* group ファイルがオープンされていなければ... */
    if (_grp_fp == 0) {

	/* group ファイルのパス名を得る */
	if (_sysroot (path, _PATH_GROUP, PATH_MAX) == 0)
	    return;

	/* group ファイルをオープンする */
	_grp_fp = fopen (path, "rt");

    }
    else {

	/* オープンされていれば rewind する */
	rewind (_grp_fp);

    }
}
