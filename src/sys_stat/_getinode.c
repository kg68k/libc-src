/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _getinode.c,v 1.7 1994/11/26 15:06:12 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <alloca.h>
#include <sys/dos.h>
#include <sys/stat.h>
#include <sys/xstat.h>
#include <sys/xglob.h>
#include <stdio.h>

/* Macros */
#define MAXDIRENTRY     (1024 / sizeof (direntry_t))
#define PASSCURDRV(x)   ((x) + 1)
#define HUMAN_CURDIRTBL ((drvtbl_t *) *(int *) 0x1c38)
#define VIRDIR          (0x60)

/* Functions */
void _getdpbsrc (int phydrv, dpbsrc_t *buf)
{
    int ssp;
    drvtbl_t *drvtbl;

    /* スーパーバイザモードへ */
    ssp = _dos_super (0);

    /* Human 内部ワークのドライブの情報を探る */
    drvtbl = HUMAN_CURDIRTBL;
    memcpy (buf, (drvtbl + phydrv)->dpbsrcptr, sizeof (dpbsrc_t));

    /* 元に戻る */
    if (ssp > 0)
	_dos_super (ssp);
}

/* Functions */
char _phydrv2drvno (char drv)
{
    /* ドライブ配置テーブル */
    unsigned char *drvtbl = (unsigned char *) 0x1c7e;
    unsigned char i;
    int ssp;

    /* スーパーバイザーへ */
    ssp = _dos_super (0);

    /* ドライブの配置を決定 */
    for (i = 0; i < _MAX_DRVNO; i++) {
	if (drv == drvtbl[i])
	    break;
    }

    /* 元に戻る */
    if (ssp > 0)
	_dos_super (ssp);

    /* i を返す */
    return i;
}

/* Functions */
int _iscdromdrive (int drive)
{
    int rc;
    struct _dpbptr dpb;
    unsigned char buffer[100];

    /* DPB をバッファに読み込む */
    if ((rc = _dos_getdpb (drive, &dpb)) < 0) {
	if (rc == _DOSE_ILGPARM) {
	    rc = _dos_ioctrlfdctl (drive, 0, buffer);
	    if (buffer[1] == 0xf5)
		return 1;
	}
    }

    /* CD-ROM ではない */
    return 0;
}

/* Functions */
int _getinode (struct _filbuf *fb, int wild)
{
    int pos, topsec, drv;
    direntry_t *direntry;
    dpbsrc_t dpbsrc;
    struct _namestbuf file;
    union {
	unsigned short no;
	unsigned char nob[2];
    } fat;

    /* DPB のタネををバッファに読み込む */
    _getdpbsrc (fb->driveno, &dpbsrc);

    /* direntry の領域を確保する */
    direntry = alloca (sizeof (direntry_t) * MAXDIRENTRY * (dpbsrc.sec + 1));

    /*
    ** ディレクトリエントリを読み込む。
    ** ちょっと、なんで mount されたらアクセスでけんねんな
    */

    {
	int asign, result;
	char drvbuf[3], pathbuf[PATH_MAX +1];

	/* ドライブ番号を求める */
	drv = _phydrv2drvno (fb->driveno);
	drvbuf[0] = drv + 'A';
	drvbuf[1] = ':';
	drvbuf[2] = '\0';

	/* アサイン情報を得る */
	if ((asign = _dos_getassign (drvbuf, pathbuf)) <= 0) {
	    errno = _errcnv (asign);
	    return -1;
	}

	/* 仮想ディレクトリか? */
	if (asign == VIRDIR)
	    if ((result = _dos_rassign (drvbuf)) < 0) {
		errno = _errcnv (result);
		return -1;
	    }

	/* 物理読み込み */
	_dos_diskred2 (direntry, PASSCURDRV (drv), fb->dirsec, 1);

	/* 仮想ディレクトリか? */
	if (asign == VIRDIR) {

	    /* makeassign 先が mount されているかもしれないので展開する */
	    _fullpath (pathbuf, pathbuf, sizeof (pathbuf));

	    /* assign を元に戻す */
	    if ((result = _dos_makeassign (drvbuf, pathbuf, VIRDIR)) < 0) {
		errno = _errcnv (result);
		return -1;
	    }

	}
    }

    /* 0xFFFF ならば... */
    if (fb->dirpos == 0xffff) {

	/* fb->name の情報を取得する */
	_dos_namests (fb->name, &file);

	/* pos 指定がないから自分でエントリ内を探す */
	for (pos = 0; pos < (MAXDIRENTRY << dpbsrc.shift); pos++) {

	    /* 削除ファイルはスキップ */
	    if ((unsigned char) direntry[pos].name1[0] == 0xe5)
		continue;

	    /* 見つかったか? */
	    if (strncmp (direntry[pos].name1, file.name1, 8) == 0 &&
		strncmp (direntry[pos].ext, file.ext, 3) == 0 &&
		strncmp (direntry[pos].name2, file.name2, 10) == 0)
		break;

	}
    }
    else {

	/* ワイルドカードが無効の場合はエラー */
	if(wild != WILD_TRUE) {
	    errno = ENOENT;
	    return -1;
	}

	/* ポジション計算 */
	pos = fb->dirpos / sizeof (direntry_t);

    }

    /* FAT番号作成 */
    fat.no = direntry[pos].fatno;
    fat.no = fat.nob[1] << 8 | fat.nob[0];

    /* FATNO = 0 かな？ */
    if (fat.no == 0) {

	/* ボリュームラベルはエントリのみ */
	if (_DOS_ISVOL (fb->atr))
	    topsec = 0;

	/* ルートディレクトリ */
	else
	    topsec = dpbsrc.dirsec;

    }

    /* FAT番号をセクタ(クラスタ)番号に変換する */
    else
	topsec = dpbsrc.datasec + ((int) (fat.no - 2) << dpbsrc.shift);

    /* inode を返す */
    return MAKEINODE (drv, topsec);
}
