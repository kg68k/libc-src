/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _toslash.c,v 1.2 1994/05/02 16:36:51 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <sys/xglob.h>

/* Functions */
char *_toslash (char *path)
{
    char *p;

    /* path を一文字づつ調べる */
    for (p = path; *p; p++) {

	/* 漢字はスキップ */
	if (ismbblead (*p))
	    p++;

	/* バックスラッシュを変換 */
	else if (*p == '\\')
	    *p = '/';
    }

    /* path を返す */
    return path;
}
