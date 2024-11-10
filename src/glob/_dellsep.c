/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from sa2c (Mr. Niimi).
 * --------------------------------------------------------------------
 * $Id: _dellsep.c,v 1.4 1994/05/02 16:36:22 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <string.h>
#include <sys/xglob.h>

/* Functions */
char *_dellastsep (char *path)
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

    /* 最後が / や \ でかつ先頭やドライブ名の後でなければ削除 */
    if ((*q == '/' || *q == '\\') && q > path && q[-1] != ':')
	*q = '\0';

    /* path を返す */
    return path;
}
