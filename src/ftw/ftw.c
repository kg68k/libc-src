/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from TomY.
 * --------------------------------------------------------------------
 * $Id: ftw.c,v 1.1 1993/06/06 06:06:40 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <ftw.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/xglob.h>

/* File scope functions */
static int _ftwsub (const char *path,
		    int (*fn) (const char *, const struct stat *, int),
		    int depmax, int depth)
{
    int r, inf;
    struct dirent *entp;
    struct stat st;
    char ename[PATH_MAX + 1];
    DIR *dirp;

    /* 指定したディレクトリをオープンする */
    if ((dirp = opendir (path)) == 0)
	return -1;

    /* 含まれるオブジェクトを調べる */
    while (entp = readdir (dirp)) {

	/* オブジェクトのフルパスを得る */
	strcpy (ename, path);
	_addlastsep (ename);
	strcat (ename, entp->d_name);

	/* lstat にて対象を調査 */
	if (lstat (ename, &st) < 0)
	    inf = FTW_NS;

	/* シンボリックリンクなら... */
	else if (S_ISLNK (st.st_mode))
	    inf = FTW_SL;

	/* ボリュームファイルなら... */
	else if (st.st_mode & S_IFVOL)
	    inf = FTW_VL;

	/* ディレクトリなら... */
	else if (S_ISDIR (st.st_mode))
	    inf = FTW_D;

	/* 普通のファイルなら... */
	else
	    inf = FTW_F;

	/* 関数を呼び出す */
	if (r = fn (ename, &st, inf)) {

	    /* ディレクトリを閉じて */
	    closedir (dirp);

	    /* r を返す */
	    return r;

	}

	/* ドットファイルじゃなく、深さも余裕があればディレクトリをたどる */
	if (inf == FTW_D && depth < depmax &&
	    strcmp (entp->d_name, ".") != 0 && strcmp (entp->d_name, "..") != 0) {

		/* 下のディレクトリにトラバース */
		r = _ftwsub (ename, fn, depmax, depth + 1);

	}

    }

    /* ディレクトリを閉じて */
    closedir (dirp);

    /* 0 を返す */
    return 0;
}

/* Functions */
int ftw (const char *path,
	 int (*fn) (const char *, const struct stat *, int), int ndirs)
{
    char ename[PATH_MAX + 1];

    /* ndir チェック */
    if (ndirs <= 0) {
	errno = EINVAL;
	return -1;
    }

    /* フルパスに展開する */
    _fullpath (ename, path, sizeof ename);

    /* サブルーチン呼び出し */
    return _ftwsub (ename, fn, ndirs, 1);
}
