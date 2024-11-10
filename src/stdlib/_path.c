/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _path.c,v 1.4 1994/07/27 13:50:00 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xstdlib.h>

/* Macros */
#define ROOTDIRECTORY(p) (memcmp (((p) + 1), ":/\0", 3) == 0)
#define DOTDOT(p)	 (p[0] == '.' && p[1] == '.' && p[2] == '\0')
#define DOT(p)		 (p[0] == '.' && p[1] == '\0')
#define NOMAL		 (0x40)
#define VIRDRV		 (0x50)
#define VIRDIR		 (0x60)

/* File scope functions */
static void entrypress (char *path, int mode)
{
    char *p, *e, *t;
    char cat[PATH_MAX + 1];
    char tmp[PATH_MAX + 1];

    /* コピー */
    strcpy (tmp, path);

    /* 最後の / の位置を記憶 */
    e = strrchr (tmp, '/') + 1;

    /* ルートディレクトリかどうか */
    if (ROOTDIRECTORY (path) || (p = strtok (tmp, "/")) == 0) {
	strupr (path);
	return;
    }

    /* パス部分を取り出す */
    strcpy (path, p);
    strupr (path);

    /* 部分パス構成要素を取り出す */
    while (p = strtok (0, "/")) {

	/* .. だったら一つ前に戻る */
	if (DOTDOT (p)) {
	    if (mode && p == e) {
		cat[0] = '/';
		strcpy (cat + 1, p);
		strcat (path, cat);
	    }
	    else if ((t = strrchr (path, '/')) > tmp + 2)
		*t = '\0';
	}

	/* . だったらその部分を潰す */
	else if (!DOT (p) || (mode && p == e)) {
	    cat[0] = '/';
	    strcpy (cat + 1, p);
	    strcat (path, cat);
	}

    }

    /* 最後の調整 */
    if (path[2] == '\0')
	strcat (path, "/");
}

/* File scope functions */
static void _physpath (char *dst, const char *src, int mode)
{
    int drvno;
    char cat[PATH_MAX + 1];
    char tmp[PATH_MAX + 1];

    /* ドライブ番号を求め、tmp 文字列に定義する */
    drvno = _getdriveno (src);
    tmp[0] = drvno + 'A';
    tmp[1] = ':';
    tmp[2] = '/';
    tmp[3] = '\0';

    /* 指定ドライブのカレントパスを求め、tmp 文字列に連結する */
    _dos_curdir (drvno + 1, tmp + 3);

    /* ルートディレクトリなら */
    if (*src == '/' || *src == '\\')
	strcpy (tmp + 3, src);

    /* ドライブ名があれば... */
    else if (src[1] == ':') {

	/* ドライブ付きルートディレクトリ */
	if (src[2] == '/' || src[2] == '\\')
	    strcpy (tmp, src);

	/* ドライブ付きファイル */
	else {
	    cat[0] = '/';
	    strcpy (cat + 1, src + 2);
	    strcat (tmp, cat);
	}

    }

    /* ファイル名のみ */
    else {
	cat[0] = '/';
	strcpy (cat + 1, src);
	strcat (tmp, cat);
    }

    /* パスをスラッシュにする */
    _toslash (tmp);

    /* ディレクトリエントリ潰し */
    entrypress (tmp, mode);

    /* コピーして終わり */
    strcpy (dst, tmp);
}

/* File scope functions */
static void __inline ptrswap (char **p1, char **p2)
{
    char *tmp;

    /* 交換 */
    tmp = *p2;
    *p2 = *p1;
    *p1 = tmp;
}

/* Functions */
char *_pathexpand (char *dst, const char *src, size_t maxlen, int mode)
{
    int normalpath;
    int status, drv;
    char drive[4];
    char tmpbuf1[PATH_MAX + 1];
    char tmpbuf2[PATH_MAX + 1];
    char virpath[PATH_MAX + 1];
    char *srcptr, *dstptr;
    const char *envptr;

    /* 文字列をコピー */
    srcptr = strcpy (tmpbuf1, src);
    dstptr = tmpbuf2;

    /* 仮想ドライブ/ディレクトリをノーマルパスになるまで展開する */
    for (normalpath = 0; normalpath == 0;) {

	/* ドライブ番号を取り出す */
	if ((drv = _getdriveno (srcptr)) < 0) {
	    errno = _errcnv (drv);
	    return 0;
	}

	/* ドライブ名を求める */
	drive[0] = drv + 'A';
	drive[1] = ':';
	drive[2] = '\0';

	/* アサイン情報を取り出す */
	if ((status = _dos_getassign (drive, dstptr)) < 0) {
	    errno = _errcnv (status);
	    return 0;
	}

	/* アサインを解決する */
	switch (status) {

	case NOMAL:				/* 通常のファイル */
	    _physpath (dstptr, srcptr, mode);
	    normalpath = 1;
	    break;

	case VIRDIR:				/* 仮想ドライブ/ディレクトリ */
	case VIRDRV:
	    _physpath (virpath, srcptr, mode);
	    strcat (dstptr, virpath + 2);
	    ptrswap (&dstptr, &srcptr);
	    break;

	default:				/* エラー */
	    errno = EFAULT;
	    return 0;
	}

    }

    /* 最後のスラッシュを取り除く */
    _dellastsep (dstptr);

    /* バッファに入りきるか */
    if (strlen (dstptr) >= maxlen) {
	errno = ERANGE;
	return 0;
    }

    /* コピーし、パスをスラッシュにして終わり */
    _toslash (strcpy (dst, dstptr));

    /* dst を返す */
    return dst;
}
