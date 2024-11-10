/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _splitpath.c,v 1.4 1993/08/16 13:36:06 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/xglob.h>

/* Functions */
void _splitpath (const char *name, char *drv, char *path, char *node, char *ext)
{
    char *e, *t;
    char xname[PATH_MAX + 1];

    /* スラッシュに変換 */
    _toslash (strcpy (xname, name));

    /* 探索用ポインタを初期化する */
    t = xname;

    {
	/* ドライブ名があるか? */
	if (*t && t[1] != ':')
	    drv[0] = '\0';

	/* ドライブ名あり */
	else {
	    drv[0] = toupper (*t);
	    drv[1] = ':';
	    drv[2] = '\0';
	    t += 2;
	}
    }

    {
	/* パス区切り記号があるか? */
	if ((e = strrchr (t, '/')) == 0)
	    path[0] = '\0';

	/* パス名を取り出す */
	else {
	    *e = '\0';
	    strcat (strcpy (path, t), "/");
	    t = e + 1;
	}
    }

    {
	/* 名前が . あるいは .. だったら */
	if (t[0] == '.' && (t[1] == '\0' || (t[1] == '.' && t[2] == '\0'))) {
	    strcpy (node, t);
	    ext[0] = '\0';
	}

	/* 拡張子があるか? */
	else if ((e = strrchr (t, '.')) == 0) {
	    strcpy (node, t);
	    ext[0] = '\0';
	}

	/* ファイル名と拡張子を取り出す */
	else {
	    strcpy (ext, e);
	    *e = '\0';
	    strcpy (node, t);
	}
    }
}
