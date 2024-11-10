/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: opendir.c,v 1.9 1994/11/26 14:51:53 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/dos.h>
#include <sys/xstat.h>
#include <sys/xstdlib.h>
#include <sys/xglob.h>
#include <sys/xtime.h>
#include <sys/xunistd.h>

/* Macros */
#define SEARCH_ATTRIB	 (0xff)
#define ROOTDIRECTORY(p) (p[0] != '\0' && p[1] == ':' && p[2] == '/' && p[3] == '\0')
#define DOTDOT(p)	 (p[0] == '.' && p[1] == '.' && p[2] == '\0')
#define DOT(p)		 (p[0] == '.' && p[1] == '\0')
#define MAXDIR		 (128)
#define DIRSIZE(x)	 (sizeof (struct dirent) * MAXDIR * (((x) == 0) ? 1 : (x) >> 6))
#define PASSCURDRV(x)	 ((x) + 1)

/* File scope variables */
static int _days_in_month[12] = {
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};

/* File scope variables */
static char *exec_suffix[] = {
    "x", "r", 0
};

/* File scope functions */
static int _executable (const char *name)
{
    int i;
    char *ext;

    /* ピリオドの位置を探す */
    if ((ext = strrchr (name, '.')) == 0)
	return 0;

    /* ポインタの補正 */
    ext++;

    /* 拡張子リストから検索 */
    for (i = 0; exec_suffix[i]; i++)
	if (stricmp (ext, exec_suffix[i]) == 0)
	    return 1;

    /* 正常終了 */
    return 0;
}

/* Functions */
DIR *opendir (const char *name)
{
    int days;
    int cdromflg;
    DIR *dirp;
    struct dirent *dp;
    char nbuf[PATH_MAX + 1];
    char exppath[PATH_MAX + 1];
    union {
	int dostime;
	tstamp_t tm;
    } ts;

    /* フルパスに展開してエントリーは潰す */
    _fullpath (exppath, name, sizeof exppath);

    /* CDROM ドライブかどうか判定する */
    cdromflg = _iscdromdrive (PASSCURDRV (exppath[0] - 'A'));

    /* ルートディレクトリのスラッシュを外す */
    if (ROOTDIRECTORY (exppath))
	exppath[2] = '\0';

    /* パスにワイルドカードをつける */
    strcat (strcpy (nbuf, exppath), "/*.*");

    /* *dirp に DIR の領域を確保する */
    if ((dirp = (DIR *) malloc (sizeof (DIR))) == 0)
	goto error;

    /* 初期化 */
    dirp->loc = dirp->filemax = 0;

    /* *dirp->dp に dirent の領域を確保する */
    if ((dirp->dp = (struct dirent *) malloc (DIRSIZE (0))) == 0)
	goto free_2;

    /* とりあえず FILES して確かめる */
    if (_dos_files (&dirp->filesbuf, nbuf, SEARCH_ATTRIB) < 0)
	goto free_1;

    /* 読み込み */
    do {

	/* dirent[dirp->filemax] を構成する */
	dp = &dirp->dp[dirp->filemax];

        /* i-node を求める (CDROM はダミーを設定) */
	if (cdromflg)
	    dp->d_ino = 0;
	else if ((dp->d_ino = _getinode (&dirp->filesbuf, WILD_TRUE)) < 0)
	    goto free_1;

	/* ファイル名と、その長さを求める */
	dp->d_namlen = dp->d_reclen =
	    strlen (strcpy (dp->d_name, dirp->filesbuf.name));

	/* ファイルモードを算出 */
	dp->d_mode = _mode2unix (dirp->filesbuf.atr);

	/* ファイルモードの修正 */
	if (_DOS_ISVOL (dirp->filesbuf.atr))
	    dp->d_mode &= ~(S_IREAD | S_IWRITE);

	/* CDROM は S_IWRITE を削除 */
	if (cdromflg)
	    dp->d_mode &= ~S_IWRITE;

	if (_executable (dirp->filesbuf.name))
	    dp->d_mode |= S_IEXEC;

	/* タイムスタンプの取得 */
	ts.dostime = (dirp->filesbuf.date << 16) | dirp->filesbuf.time;

	/* トータル日数の計算 */
	days = ((ts.tm.year + 10) * 365
		+ (_days_in_month[ts.tm.month - 1])
		+ (ts.tm.day)
		+ ((ts.tm.year >> 2) + 2)
		- (((ts.tm.year & 3) == 0 && ts.tm.month < 3) ? 1 : 0));

	/* 時間の設定/トータル秒数の計算 (最初から JST なので補正) */
	dp->d_time = (((days * 24 + ts.tm.hour) * 60
		       + ts.tm.minute) * 60
		      + (ts.tm.sec2 << 1) + _TZADJUST);

	/* ファイルサイズを設定 */
	dp->d_size = dirp->filesbuf.filelen;

	/* ファイル数カウント */
	dirp->filemax++;

	/* dirent 領域が足りなければ拡張する */
	if ((dirp->filemax % MAXDIR) == 0)
	    if ((dirp->dp = realloc (dirp->dp, DIRSIZE (dirp->filemax))) == 0)
		return 0;

	/* ファイルが見つからなくなるまで続ける */

    }
#ifdef __LIBSXC__
    while (TSNFiles (&dirp->filesbuf, nbuf, SEARCH_ATTRIB) == 0);
#else
    while (_dos_nfiles (&dirp->filesbuf) == 0);
#endif

    /* dirp を返す */
    return dirp;

  free_1:
    /* メモリを解放する */
    free (dirp->dp);

  free_2:
    /* メモリを解放する */
    free (dirp);

  error:
    /* エラーで終了 */
    errno = ENOENT;
    return 0;
}
