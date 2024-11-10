/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: rename.c,v 1.3 1994/07/27 13:49:32 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xstdlib.h>

/* File scope functions */
static int pathchk (char *old, char *new)
{
    int len;

    /* OLDパスの長さを調べる */
    len = strlen (old);

    /* OLDパスが NEWパスに含まれるか調べる */
    if (new[len] == '/' && memcmp (old, new, len) == 0)
	return -1;

    /* 含まれない */
    return 0;
}

/* File scope functions */
static int dirmove (const char *old, const char *new)
{
    int rc;

    /* old と new をリンクする */
    if ((rc = _dos_link (old, new)) < 0)
	return rc;

    /* old を unlink する */
    if ((rc = _dos_unlink (old)) < 0)
	return rc;

    /* 成功 */
    return 0;
}

/* File scope functions */
int rename (const char *old, const char *new)
{
    int rc;
    int old_mode, new_mode;
    char old_path[PATH_MAX + 1];
    char new_path[PATH_MAX + 1];

    /* 絶対パスに変換する */
    _fullentry (old_path, old, sizeof old_path);
    _fullentry (new_path, new, sizeof new_path);

    /* NEW に OLD が含まれたりしないか? */
    if (pathchk (old_path, new_path) < 0) {
	errno = EINVAL;
	return -1;
    }

    /* OLD ファイルのモードを調べる */
    if ((old_mode = _dos_chmod (old_path, -1)) < 0) {
	errno = ENOENT;
	return -1;
    }

    /* 同一ファイルの変更以外で NEW ファイルが存在するか？ */
    if ((new_mode = _dos_chmod (new_path, -1)) >= 0 && strcmpi (old_path, new_path)) {

	/* ファイルモードが異なればエラー */
	if ((old_mode ^ new_mode) & (_DOS_IFDIR | _DOS_IFREG)) {
	    errno = _DOS_ISDIR (old_mode) ? ENOTDIR : EISDIR;
	    return -1;
	}

	/* 先ディレクトリがすでに存在する場合は削除する */
	if (_DOS_ISDIR (old_mode) && _DOS_ISDIR (new_mode)) {
	    if (_dos_rmdir (new_path) < 0) {
		errno = ENOTEMPTY;
		return -1;
	    }
	}

	/* ファイルが存在する場合は削除する */
	else if ((rc = _dos_delete (new_path)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

    }

    /* 元ファイルはディレクトリか? */
    if (_DOS_ISDIR (old_mode)) {

	/* リネーム／ディレクトリの移動 */
	if ((rc = dirmove (old_path, new_path)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

    }
    else {

	/* リネーム／通常ファイルの移動 */
	if ((rc = _dos_rename (old_path, new_path)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

    }

    /* 成功 */
    return 0;
}
