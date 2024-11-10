/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from μ-Project header & libraries.
 * --------------------------------------------------------------------
 * $Id: _makepath.c,v 1.3 1993/11/13 06:35:04 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <string.h>
#include <sys/xglob.h>

/* Functions */
void _makepath (char *path, const char *drive,
	        const char *dir, const char *name, const char *extension)
{
    int last;

    /* ドライブ名を処理する */
    if (drive && *drive) {
	path[0] = *drive;
	path[1] = ':';
	path[2] = '\0';
    }
    else {
	path[0] = '\0';
    }

    /* ディレクトリを処理する */
    if (dir && *dir) {
	strcat (path, dir);
	_addlastsep (path);
    }

    /* ファイル名を処理する */
    if (name && *name)
	strcat (path, name);

    /* 拡張子を処理する */
    if (extension && *extension) {
	last = strlen (path);
	path[last++] = '.';
	strcpy (&path[last], &extension[*extension == '.' ? 1 : 0]);
    }

    /* 全てスラッシュに変換する */
    _toslash (path);
}
