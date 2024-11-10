/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fstat.c,v 1.5 1994/11/26 15:06:37 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/stat.h>
#include <sys/xglob.h>
#include <sys/xstat.h>
#include <sys/xunistd.h>
#include <sys/xtime.h>

/* Macros */
#define PASSCURDRV(x) ((x) + 1)

/* File scope variables */
static int _days_in_month[12] = {
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};

/* File scope variables */
static char *exec_suffix[] = {
    "x", "r", 0
};

/* File scope functions */
static int _executable (const char *ext)
{
    int i;
    char xext[4];
    char *p;

    /* 保険 */
    xext[3] = '\0';

    /* 拡張子を取り出す */
    if ((p = strchr (strncpy (xext, ext, 3), ' ')) != 0)
	*p = '\0';

    /* 拡張子リストから検索 */
    for (i = 0; exec_suffix[i]; i++)
	if (stricmp (xext, exec_suffix[i]) == 0)
	    return 1;

    /* 見つからない */
    return 0;
}

/* File scope functions */
static int _fstatsub (int fd, struct stat *st)
{
    int days;
    int topsec;
    time_t times;
    dpbsrc_t dpbsrc;
    union _fcb *fcb;
    union {
	int dostime;
	tstamp_t tm;
    } ts;

    /* FCB を求める */
    fcb = _dos_getfcb (fd);

    /* デバイス(キャラクタ型)か？ */
    if (fcb->blk.mode) {

	/* ダミーの st を構成する */
	st->st_ino = st->st_gid = st->st_size = 0;
	st->st_atime = st->st_mtime = st->st_ctime = 0;
	st->st_nlink = 1;
	st->st_rdev = st->st_dev = (int) fcb->chr.deventry;
	st->st_mode = S_IFCHR | S_IWRITE | S_IREAD;
	return 0;

    }

    /* ファイルモードを算出 */
    st->st_mode = _mode2unix (fcb->blk.attr);

    /* ファイルモードの修正 */
    if (_executable (fcb->blk.ext))
	st->st_mode |= S_IEXEC;

    /* タイムスタンプの取得 */
    ts.dostime = (fcb->blk.date << 16) | fcb->blk.time;

    /* トータル日数の計算 */
    days = ((ts.tm.year + 10) * 365
	    + (_days_in_month[ts.tm.month - 1])
	    + (ts.tm.day)
	    + ((ts.tm.year >> 2) + 2)
	    - (((ts.tm.year & 3) == 0 && ts.tm.month < 3) ? 1 : 0));

    /* トータル秒数の計算 (最初から JST なので補正) */
    times = (((days * 24 + ts.tm.hour) * 60
	      + ts.tm.minute) * 60
	     + (ts.tm.sec2 << 1) + _TZADJUST);

    /* 時間の設定 */
    st->st_atime = st->st_mtime = st->st_ctime = times;

    /* ファイルサイズを設定 */
    st->st_size = fcb->blk.size;

    /* UID, GID, NLINK を設定 */
    st->st_uid = st->st_gid = 0;
    st->st_nlink = 1;
    st->st_dev = st->st_rdev = _phydrv2drvno (fcb->blk.physdrv);

    /* ブロックサイズ設定 */
    st->st_blksize = 8192;

    /* CD-ROM ドライブじゃない... */
    if (!_iscdromdrive (PASSCURDRV (st->st_dev))) {

	/* Human 内部の DPB のタネをバッファに読み込む */
	_getdpbsrc (fcb->blk.physdrv, &dpbsrc);

	/* FAT番号をセクタ(クラスタ)番号に変換する */
	topsec = dpbsrc.datasec + ((int) (fcb->blk.fatno - 2) << dpbsrc.shift);

	/* INODE を作成する */
	st->st_ino = MAKEINODE (st->st_dev, topsec);

    }

    /* CD-ROM ドライブだ */
    else {

	/* CDROM は S_IWRITE を削除 */
	st->st_mode &= S_IWRITE;

	/* CDROM は i-node にダミーを設定 */
	st->st_ino = 0;

    }

    /* 正常終了 */
    return 0;
}

/* Functions */
int fstat (int fd, struct stat *st)
{
    int ssp, result;

#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* スーパーバイザーモードへ */
    ssp = _dos_super (0);

    /* stat を実行する */
    result = _fstatsub (fd, st);

    /* 元に戻る */
    if (ssp > 0)
	_dos_super (ssp);

    /* 結果を返す */
    return result;
}
