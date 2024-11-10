/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: unlink.c,v 1.8 1994/11/26 15:13:01 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int unlink (const char *path)
{
    int i, ssp, check;
    int devattr, fd;
    unsigned char entryidx;
    unsigned long dirsec;
    unsigned short fatno;
    void *deventry;
    union _fcb fblock, *np;

    /* テンポラリにオープンする */
    if ((fd = _dos_open (path, 0)) < 0) {

	/* ディレクトリか? */
	if (fd == _DOSE_ISDIR) {

	    /* ディレクトリを削除してみる */
	    if (_dos_rmdir (path) >= 0)
		return 0;

	}

	/* リンク先の見つからないかディレクトリへのシンボリックリンク */
	if (_dos_delete (path) >= 0)
	    return 0;

	/* やはりエラー */
	errno = _errcnv (fd);
	return -1;

    }

    /* デバイス属性を求める */
    devattr = _dos_ioctrlgt (fd);

    /* FCB を求めて、クローズ */
    ssp = _dos_super (0);
    memcpy (&fblock, _dos_getfcb (fd), sizeof (union _fcb));
    if (ssp > 0) _dos_super (ssp);

    /* クローズする */
    _dos_close (fd);

    /* キャラクタデバイスは削除できない */
    if (devattr & _DEV_CDEV) {
	errno = EDEVFS;
	return -1;
    }

    /* READONLY ファイルは削除できない */
    if (fblock.blk.attr & (_DOS_IRDONLY | _DOS_ISYS)) {
	errno = EPERM;
	return -1;
    }

    /* ファイルの物理ドライブと先頭 FAT を求める */
    deventry = fblock.blk.deventry;
    entryidx = fblock.blk.entryidx;
    dirsec   = fblock.blk.dirsec;
    fatno    = fblock.blk.fatno;

    /* 現在オープンされているファイル群の中にあるか? */
    for (check = i = 0; i < OPEN_MAX; i++) {

	/* 登録されているファイルの FCB */
	np = &_fddb[i].fcb;

	/* 登録されているデータと照合する */
	if (np->blk.deventry == deventry &&
	    np->blk.entryidx == entryidx &&
	    np->blk.dirsec   == dirsec &&
	    np->blk.fatno    == fatno) {

	    /* unlink フラグを設定 */
	    _fddb[i].unlink = 1;

	    /* 予約チェックフラグを加算 */
	    check++;

	}

    }

    /* 見つからないなら、そのまま削除しても良い */
    if (check == 0 && (fd = _dos_delete (path)) < 0) {
	errno = _errcnv (fd);
	return -1;
    }

    /* 正常終了 */
    return 0;
}
