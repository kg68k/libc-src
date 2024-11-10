/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: d_link.c,v 1.6 1994/07/27 13:51:51 mura Exp $
 */

/* System headers */
#include <alloca.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/xstat.h>

/* Macros */
#define DPBTABLEHDL 0x1c3c

/* Structures and unions */
struct _rqhd_bio {
    char num;
    char unit;
    char command;
    char errorl;
    char errorh;
    char notused[8];
    char fatid;
    void *buffptr;
    int seclen;
    int secnum;
};

/* Structures and unions */
struct fileinfo {
    struct _namestbuf namests;
    dpbsrc_t dpbdat;
    struct _filbuf filbuf;
    int dent;
    direntry_t *dirbufp;
};

/* File scope functions */
static void phydiskrw (void *addr, int pdrive, int sector, int seclen, int command)
{
    int ssp;
    devheader_t *dvhp;
    struct _rqhd_bio rqhd;
    dpbsrc_t *dpbp;
    dpbsrc_t **dpbtblh = (dpbsrc_t **) DPBTABLEHDL;
#ifndef __LIBSXC__
    register struct _rqhd_bio *rqhdp asm ("a5");
#endif

    /* スーパーバイザーモード */
    ssp = _dos_super (0);

    /* DPB とデバイスヘッダのポインタの計算 */
    dpbp = *dpbtblh;
    while (pdrive-- > 0)
	dpbp = dpbp->nexttblptr;
    dvhp = dpbp->devheadptr;

    /* リクエストヘッダの設定 */
    rqhd.num = 0x1a;
    rqhd.unit = dpbp->unit;
    rqhd.command = command;
    rqhd.fatid = dpbp->ide;
    rqhd.buffptr = addr;
    rqhd.seclen = seclen;
    rqhd.secnum = sector;

    /* デバイスドライバのコール */
#ifdef __LIBSXC__
    asm volatile ("move.l a5,-(sp)\n\t"
		  "move.l %1,a5\n\t"
		  "bsr @f\n\t"
		  "bra @@f\n"
		  "@@:\n\t"
		  "jsr (%0)\n\t"
		  "addq.w #4,sp\n"
		  "@@:\n\t"
		  "move.l (sp)+,a5"
		  :/* no outputs */
		  :"a" (dvhp->strategy_entry), "g" (&rqhd));
#else
    rqhdp = &rqhd;
    asm volatile ("bsr @f\n\t"
		  "bra @@f\n"
		  "@@:\n\t"
		  "jsr (%0)\n\t"
		  "addq.w #4,sp\n"
		  "@@:"
		  :/* no outputs */
		  :"a" (dvhp->strategy_entry), "a" (rqhdp));
#endif

    /* 割り込みエントリを呼び出す */
    ((int (*)(void)) (dvhp->int_entry)) ();

    /* ユーザーモードへ戻る */
    if (ssp > 0)
	_dos_super (ssp);
}

/* File scope functions */
static void _dos_phydiskred2 (void *addr, int pdrive, int sector, int seclen)
{
    /* デバイスドライバ直接呼び出し */
    phydiskrw (addr, pdrive, sector, seclen, 4);
}

/* File scope functions */
static void _dos_phydiskwrt2 (void *addr, int pdrive, int sector, int seclen)
{
    /* デバイスドライバ直接呼び出し */
    phydiskrw (addr, pdrive, sector, seclen, 8 + _dos_verifyg ());
}

/* File scope functions */
static int _dos_phygetidpb (int pdrive, dpbsrc_t *idpbptr)
{
    int ssp;
    dpbsrc_t *dpbp;
    dpbsrc_t **dpbtblh = (dpbsrc_t **) DPBTABLEHDL;

    /* スーパーバイザーモードへ */
    ssp = _dos_super (0);

    /* DPB のポインタの計算 */
    dpbp = *dpbtblh;
    while (pdrive-- > 0)
	dpbp = dpbp->nexttblptr;

    /* DPB をコピー */
    *idpbptr = *dpbp;

    /* ユーザーモードへ戻る */
    if (ssp > 0)
	_dos_super (ssp);

    /* 正常終了 */
    return 0;
}

/* File scope functios */
static void write_directory (struct fileinfo *ip)
{
    /* ディレクトリへ直接書き込み */
    _dos_curdrv ();
    _dos_fflush ();
    _dos_phydiskwrt2 (ip->dirbufp, ip->filbuf.driveno, ip->filbuf.dirsec, 1);
}

/* File scope functios */
static int read_directory (struct fileinfo *ip)
{
    int ent, maxe;
    direntry_t *dp;
    char sname1[8 + 3];

    /* ファイル名の先頭が E5 なら 05 に変換 */
    memcpy (sname1, ip->namests.name1, 8 + 3);
    if (*sname1 == '\xe5')
	*sname1 = '\x05';

    /* ディレクトリから直接読み込み */
    _dos_curdrv ();
    _dos_fflush ();
    _dos_phydiskred2 (ip->dirbufp, ip->filbuf.driveno, ip->filbuf.dirsec, 1);

    /* 最大エントリ番号を計算 */
    maxe = (ip->dpbdat.byte << ip->dpbdat.shift) / sizeof (direntry_t);

    /* ディレクトリからエントリーを探す */
    for (ent = 0, dp = ip->dirbufp; ent < maxe; ent++, dp++) {

	/* これ以上ない */
	if (dp->name1[0] == '\x00')
	    return _DOSE_NOENT;

	/* 同じかどうか調べる */
	if ((dp->attr == ip->filbuf.atr)
	    && (!memcmp (dp->name1, sname1, 8 + 3))
	    && (!memcmp (dp->name2, ip->namests.name2, 10))) {
	    ip->dent = ent;
	    return 0;
	}

    }

    /* 見つからない */
    return _DOSE_NOENT;
}

/* File scope functions */
static int make_temporary (const char *path)
{
    int fh;

    /* 仮のエントリーをつくる */
    if ((fh = _dos_newfile (path, 0x28)) < 0)
	return fh;

    /* クローズする */
    return _dos_close (fh);
}

/* File scope functions */
static void killtmp (const char *path)
{
    /* 仮のエントリーを削除する */
    _dos_chmod (path, 0x20);
    _dos_delete (path);
}

/* Functions */
int _dos_link (const char *src, const char *dst)
{
    int r;
    struct fileinfo sinfo, dinfo;
    direntry_t *sdp, *ddp;

    /* 元ファイル名のチェックとファイル情報の取得 */
    if ((r = _dos_namests (src, &sinfo.namests)) < 0)
	return r;

    if (sinfo.namests.flg)
	return _DOSE_ILGFNAME;

    if ((r = _dos_files (&sinfo.filbuf, src, 0xff)) < 0)
	return r;

    /* リンクファイル名のチェックと存在チェック */
    if ((r = _dos_namests (dst, &dinfo.namests)) < 0)
	return r;

    if (dinfo.namests.flg)
	return _DOSE_ILGFNAME;

    if ((r = _dos_files (&dinfo.filbuf, dst, 0xff)) != _DOSE_NOENT)
	return r < 0 ? r : _DOSE_ALRDYEX;

    /* 同一ファイルシステムかどうか */
    if (sinfo.filbuf.driveno != dinfo.filbuf.driveno)
	return _DOSE_ILGDRV;

    /* 元ファイルのディレクトリ情報の読み込み */
    if ((r = _dos_phygetidpb (sinfo.filbuf.driveno, &sinfo.dpbdat)) < 0)
	return r;

    sinfo.dirbufp = (direntry_t *) alloca (sinfo.dpbdat.byte << sinfo.dpbdat.shift);

    if (sinfo.dirbufp == NULL)
	return _DOSE_NOMEM;

    if ((r = read_directory (&sinfo)) < 0)
	return r;

    /* 仮エントリーの作成とファイル情報の取得 */
    if ((r = make_temporary (dst)) < 0)
	return r;

    if ((r = _dos_files (&dinfo.filbuf, dst, 0xff)) < 0) {
	/* 仮エントリーを削除してエラー終了 */
	killtmp (dst);
	return r;
    }

    /* 再度ファイルシステムチェック */
    if (sinfo.filbuf.driveno != dinfo.filbuf.driveno)
	return _DOSE_ILGDRV;

    /* 仮エントリーのディレクトリ情報の読み込み */
    if ((r = _dos_phygetidpb (dinfo.filbuf.driveno, &dinfo.dpbdat)) < 0) {
	/* 仮エントリーを削除してエラー終了 */
	killtmp (dst);
	return r;
    }

    dinfo.dirbufp = (direntry_t *) alloca (dinfo.dpbdat.byte << dinfo.dpbdat.shift);

    if (dinfo.dirbufp == NULL) {
	/* 仮エントリーを削除してエラー終了 */
	killtmp (dst);
	return _DOSE_NOMEM;
    }

    if ((r = read_directory (&dinfo)) < 0) {
	/* 仮エントリーを削除してエラー終了 */
	killtmp (dst);
	return r;
    }

    /* ディレクトリ情報のコピー */
    sdp = sinfo.dirbufp + sinfo.dent;
    ddp = dinfo.dirbufp + dinfo.dent;
    ddp->attr = sdp->attr;
    ddp->fatno = sdp->fatno;
    ddp->size = sdp->size;

    /* リンクファイルのディレクトリ情報の書き込み */
    write_directory (&dinfo);

    /* 正常終了 */
    return 0;
}

/* Functions */
int _dos_unlink (const char *name)
{
    int r;
    struct fileinfo dinfo;

    /* リンクファイル名のチェックとファイル情報の取得 */
    if ((r = _dos_namests (name, &dinfo.namests)) < 0)
	return r;

    if (dinfo.namests.flg)
	return _DOSE_ILGFNAME;

    if ((r = _dos_files (&dinfo.filbuf, name, 0xff)) < 0)
	return r;

    /* リンクファイルのディレクトリ情報の読み込み */
    if ((r = _dos_phygetidpb (dinfo.filbuf.driveno, &dinfo.dpbdat)) < 0)
	return r;

    dinfo.dirbufp = (direntry_t *) alloca (dinfo.dpbdat.byte << dinfo.dpbdat.shift);

    if (dinfo.dirbufp == NULL)
	return _DOSE_NOMEM;

    if ((r = read_directory (&dinfo)) < 0)
	return r;

    /* エントリーの削除 */
    dinfo.dirbufp[dinfo.dent].name1[0] = '\xe5';

    /* ディレクトリ情報の書き込み */
    write_directory (&dinfo);

    /* 正常終了 */
    return 0;
}
