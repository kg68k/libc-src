/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _addlsep.c,v 1.3 1994/05/02 16:36:10 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <string.h>
#include <sys/xglob.h>

/* Functions */
char *_addlastsep (char *path)
{
    char *p, *q;

    /* path を parse する */
    for (p = q = path; *p; p++) {

	/* 現在位置をマーク */
	q = p;

	/* 有効な漢字ならば 2byte スキップ */
	if (ismbblead (*p) && p[1])
	    p++;

    }

    /* 最後が / や \ でなければ / を追加 */
    if (*q != '/' && *q != '\\') {
	p[0] = '/';
	p[1] = '\0';
    }

    /* path を返す */
    return path;
}
