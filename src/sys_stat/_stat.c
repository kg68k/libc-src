/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _stat.c,v 1.15 1994/11/26 15:06:24 mura Exp $
 */

/* System headers */
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/dos.h>
#include <sys/xdoseml.h>
#include <sys/xglob.h>
#include <sys/xstat.h>
#include <sys/xstdlib.h>
#include <sys/xtime.h>
#include <sys/xunistd.h>

/* Macros */
#define SEARCH_ATTRIB    (0xff)
#define CHAIN_END_MARK   (0)
#define ROOTDIRECTORY(p) (p[0] != '\0' && p[1] == ':' && p[2] == '/' && p[3] == '\0')
#define PASSCURDRV(x)    ((x) + 1)

/* File scope functions */
static int _executable (const char *);
static int _fakecdev (struct stat *, char *);
static int _fakeroot (const char *, struct stat *, int);
static int _build_st (const char *, struct stat *, struct _filbuf *, const char *, int);
static int _setinodedirsize (const char *, struct stat *, struct _filbuf *);

/* File scope variables */
static int _days_in_month[12] = {
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};

/* File scope variables */
static char *exec_suffix[] = {
    "x", "r", 0
};

/* File scope functions */
static int _build_st (const char *name, struct stat *st,
		      struct _filbuf *fb, const char *node, int cdromflg)
{
    int days;
    time_t times;
    union {
	int dostime;
	tstamp_t tm;
    } ts;

    /* ファイルモードを算出 */
    st->st_mode = _mode2unix (fb->atr);

    /* ファイルモードの修正 */
    if (_DOS_ISVOL (fb->atr))
	st->st_mode &= ~(S_IREAD | S_IWRITE);
    if (_executable (name))
	st->st_mode |= S_IEXEC;

    /* タイムスタンプの取得 */
    ts.dostime = (fb->date << 16) | fb->time;

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

    /* ファイルサイズを設定(ディレクトリサイズの場合は後で上書き) */
    st->st_size = fb->filelen;

    /* UID, GID, NLINK を設定 */
    st->st_uid = st->st_gid = 0;
    st->st_nlink = 1;

    /* ブロックサイズ設定 */
    st->st_blksize = 8192;

    /* 論理ドライブ設定 */
    st->st_rdev = _getdriveno (node);

    /* 物理ドライブ設定 */
    st->st_dev = _phydrv2drvno (fb->driveno);

    /* CDROM 以外なら inode, dirsize を求めて終わり */
    if(!cdromflg)
	return _setinodedirsize (name, st, fb);

    /* CDROM は S_IWRITE を削除 */
    st->st_mode &= ~S_IWRITE;

    /* CDROM は i-node にダミーを設定 */
    st->st_ino = 0;

    /* 終了 */
    return 0;
}

/* File scope functions */
static int _fakecdev (struct stat *st, char *path)
{
    int ssp, fno;
    char xpath[PATH_MAX + 1];
    char *node;
    union _fcb fcb;

    /* もしかしたらシンボリックリンクされてるかも？ */
    node = _dos_readlink (path, xpath, sizeof xpath) > 0 ? xpath : path;

    /* 実はルートだった場合 */
    if (ROOTDIRECTORY (node))
	return _fakeroot (node, st, 0);

    /* デバイスをオープンする */
    if ((fno = _dos_open (node, O_RDONLY)) < 0) {
	errno = ENOENT;
	return -1;
    }

    /* FCB をローカルにコピーしてくる */
    ssp = _dos_super (0);
    memcpy (&fcb, _dos_getfcb (fno), sizeof (union _fcb));
    if (ssp > 0) _dos_super (ssp);

    /* デバイスドライバのエントリアドレスを st_dev, st_rdev に設定する */
    st->st_rdev = st->st_dev = (int) fcb.chr.deventry;

    /* デバイスをクローズ */
    _dos_close (fno);

    /* ダミーの st を構成する */
    st->st_ino = st->st_gid = st->st_size = 0;
    st->st_atime = st->st_mtime = st->st_ctime = 0;
    st->st_nlink = 1;
    st->st_mode = S_IFCHR | S_IWRITE | S_IREAD;

    /* キャラクタ型デバイスでなければエラー */
    if (!fcb.blk.mode) {
	errno = ENOENT;
	return -1;
    }

    /* 正常終了 */
    return 0;
}

/* File scope functions */
static int _fakeroot (const char *name, struct stat *st, int cdromflg)
{
    int err;
    struct _dpbptr dpb;

    /* CDROM の場合 */
    if(cdromflg) {

	/* CDROM ならダミー */
	st->st_dev = st->st_rdev = _getdriveno (name);
	st->st_ino = 0;
	st->st_size = 0;
	st->st_mode = S_IFDIR | S_IREAD | S_IEXEC;
	st->st_uid = st->st_gid = 0;
	st->st_atime = st->st_mtime = st->st_ctime = 0;
	st->st_nlink = 1;

    }

    /* それ以外 */
    else {

        /* DPB をバッファに読み込む */
        if ((err = _dos_getdpb (PASSCURDRV (_getdriveno (name)), &dpb)) < 0) {
	    errno = _errcnv (err);
	    return -1;
	}

	/* st を構成する */
	st->st_dev = st->st_rdev = dpb.drive;

	st->st_ino = MAKEINODE (dpb.drive, dpb.dirsec);
	st->st_size = dpb.dircount * sizeof (direntry_t);
	st->st_mode = S_IFDIR | S_IWRITE | S_IREAD | S_IEXEC;
	st->st_uid = st->st_gid = 0;
	st->st_atime = st->st_mtime = st->st_ctime = 0;
	st->st_nlink = 1;

    }

    /* 正常終了 */
    return 0;
}

/* File scope functions */
static int _executable (const char *name)
{
    int i;
    char *top, *ext;

    /* ファイル名の位置を求める */
    if ((top = strrchr (name, '/')) == 0)
	return 0;

    /* ピリオドの位置を探す */
    if ((ext = strrchr (name, '.')) == 0)
	return 0;

    /* それはファイル名の中のピリオドか */
    if (++ext <= top)
	return 0;

    /* 拡張子リストから検索 */
    for (i = 0; exec_suffix[i]; i++)
	if (stricmp (ext, exec_suffix[i]) == 0)
	    return 1;

    /* 正常終了 */
    return 0;
}

/* Typedefs */
typedef int (*func) (const char *, unsigned short *, int);

/* File scope functions */
static int xlfatchk2 (const char *file, unsigned short *buf, int len)
{
#ifndef LNDRV_C_FUNCTION
    int ssp;
#endif
    int *lnenv;
    register int result;
    func lfatchk;

    /* lndrv の関数テーブルを求める */
    if ((lnenv = _dos_importlnenv ()) == 0)
	return _dos_fatchk2 (file, buf, len);

    /* FATCHK2 を行う */
#ifdef LNDRV_C_FUNCTION
    lfatchk = (func) lnenv[C_LFATCHK];
    /* buf の最上位ビットを立て lndrv 内部の lfatchk2 を呼び出す。 */
    buf = (unsigned short *) ((int) buf | (1 << 31));
    result = lfatchk (file, buf, len);
#else
    lfatchk = (func) lnenv[LFATCHK_VECTOR];
    ssp = _dos_super (0);
    result = CALL_XLFATCHK2 (lfatchk, file, buf, len);
    if (ssp > 0)
	_dos_super (ssp);
#endif

    /* 結果を返す */
    return result;
}

/* File scope functions */
int _setinodedirsize (const char *name, struct stat *st, struct _filbuf *fb)
{
    int length, i, err;
    fatchain_t fat;
    dpbsrc_t dpbsrc;
    struct _filbuf vdirfb;
    char xname[PATH_MAX + 1];

    /* ディレクトリ以外なら i-node を作成して終わり */
    if (!S_ISDIR (st->st_mode)) {

	/* i-node を計算 */
	if ((st->st_ino = _getinode (fb, WILD_FALSE)) < 0)
	    return -1;

	/* 正常終了 */
	return 0;

    }

    /* Human 内部の DPB のタネをバッファに読み込む */
    _getdpbsrc (fb->driveno, &dpbsrc);

    /* リンクされているかどうか? */
    if (S_ISLNK (st->st_mode))
	err = _dos_fatchk2 (name, (unsigned short *) &fat, sizeof (fatchain_t) - 10);
    else
	err = xlfatchk2 (name, (unsigned short *) &fat, sizeof (fatchain_t) - 10);

    /* エラーか? */
    if (err < 0) {
	errno = _errcnv (err);
	return -1;
    }

    /* ワイルドカードを作成して... */
    strcat (strcpy (xname, name), "/*.*");

    /* mount point の補正の為、ディレクトリ内部のファイルを検索する */
    if (_dos_lfiles (&vdirfb, xname, SEARCH_ATTRIB) < 0)
	vdirfb.driveno = fb->driveno;

    /* mount point の補正が必要か? */
    if (fb->driveno != vdirfb.driveno) {

	/* 物理ドライブ補正 */
	st->st_dev = _phydrv2drvno (vdirfb.driveno);

	/* ディレクトリサイズを求める */
	st->st_size = dpbsrc.dircount * sizeof (direntry_t);

	/* i-inode を作成する */
	st->st_ino = MAKEINODE (vdirfb.driveno, dpbsrc.dirsec);

    }
    else {

	/* ディレクトリサイズの元ねたを求める */
	for (i = 0, length = 0; fat.chain[i].secno != CHAIN_END_MARK; i++)
	    length += fat.chain[i].seclen;

	/* ディレクトリサイズを求める */
	st->st_size = length * (dpbsrc.byte << dpbsrc.shift);

	/* i-inode を作成する */
	st->st_ino = MAKEINODE (st->st_dev, fat.chain[0].secno);

    }

    /* 正常終了 */
    return 0;
}

/* Functions */
int _statsub (int lstat, const char *name, struct stat *st)
{
    struct _filbuf fb;
    int status;
    int cdromflg;
    char node[PATH_MAX + 1];
    char expname[PATH_MAX + 1];

    /* ファイル名を node にコピーする */
    strcpy (node, name);

    /* フルパスに展開し、ディレクトリエントリを潰す */
    if (_fullpath (expname, name, sizeof expname) == NULL)
	return -1;

    /* CD-ROM ドライブかどうか判定 */
    cdromflg = _iscdromdrive (PASSCURDRV (expname[0] - 'A'));

    /* ルートディレクトリ */
    if (ROOTDIRECTORY (expname))
	return _fakeroot (expname, st, cdromflg);

    /* とりあえず、LFILES してみる */
    if (lstat)
	status = _dos_lfiles (&fb, expname, SEARCH_ATTRIB);

    /* とりあえず FILES する */
    else
	status = _dos_files (&fb, expname, SEARCH_ATTRIB);

    /* ファイルが見つからないかデバイスである */
    if (status < 0)
	return _fakecdev (st, expname);

    /* ファイルまたはディレクトリ */
    else
	return _build_st (expname, st, &fb, node, cdromflg);
}
