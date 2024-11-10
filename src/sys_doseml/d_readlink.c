/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: d_readlink.c,v 1.8 1994/11/26 15:03:02 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xdoseml.h>

/* Typedefs */
typedef int (*func_1) (char *, const char *);
typedef int (*func_2) (const char *, unsigned short);

/* File scope functions */
static int realpathcopy (char *dst, const char *src)
{
#ifndef LNDRV_C_FUNCTION
    int ssp;
#endif
    int ret;
    int *lnenv;
    func_1 xpathcpy;

    /* lndrv が常駐していなければエラー */
    if ((lnenv = _dos_importlnenv ()) == 0)
	return -1;

#ifdef LNDRV_C_FUNCTION
    /* C_REALPATHCPY のベクターアドレスを取得する */
    xpathcpy = (func_1) lnenv[C_REALPATHCPY];
    ret = xpathcpy (dst, src);
#else
    /* REALPATHCOPY のベクターアドレスを取得する */
    xpathcpy = (func_1) lnenv[REALPATHCPY_VECTOR];

    /* スーパーバイザーモードで lndrv 内部を直接呼び出す */
    ssp = _dos_super (0);

    /* 呼び出し */
    ret = CALL_XPATHCPY (xpathcpy, dst, src);

    /* 戻る */
    if (ssp > 0)
	_dos_super (ssp);
#endif

     /* 戻り値を返す */
     return ret;
}

/* File scope functions */
static int orignal_dos_open (const char *file, unsigned short mode)
{
#ifndef LNDRV_C_FUNCTION
    int ssp;
#endif
    int ret;
    int *lnenv;
    func_2 xopen;

    /* lndrv が常駐していなければエラー */
    if ((lnenv = _dos_importlnenv ()) == 0)
	return -1;

#ifdef LNDRV_C_FUNCTION
    /* C_OLD_OPEN のベクターアドレスを取得する */
    xopen = (func_2) lnenv[C_OLD_OPEN];
    ret = xopen (file, mode);
#else
    /* OLD_OPEN のベクターアドレスを取得する */
    xopen = (func_2) lnenv[OLD_OPEN_VECTOR];

    /* スーパーバイザーモードで lndrv 内部を直接呼び出す */
    ssp = _dos_super (0);

    /* 呼び出し */
    ret = CALL_XOPEN (xopen, file, mode);

    /* 戻る */
    if (ssp > 0)
	_dos_super (ssp);
#endif

    /* 戻り値を返す */
    return ret;
}

/* Functions */
int _dos_readlink (const char *linkpath, char *namebuf, int buflen)
{
    char buf[PATH_MAX + 1];
    int len, fd, mode;

    /* linkpath のファイル属性を調べる */
    mode = _dos_chmod (linkpath, -1);

    /* ファイルが見つからない */
    if (mode < 0)
	return _DOSE_NOENT;

    /* symbolic link でなければ 不正なパラメータ */
    if (!_DOS_ISLNK (mode))
	return _DOSE_ILGPARM;

    /* 実際のパス名を取得する エラーなら無効なファンクションコール */
    if (realpathcopy (buf, linkpath) < 0)
	return _DOSE_ILGFNC;

    /* symbloic link ファイルをオープンする */
    if ((fd = orignal_dos_open (buf, 0)) < 0)
	return fd;

    /* 中身を読み出す */
    len = _dos_read (fd, buf, PATH_MAX);

    /* ファイルをクローズする */
    _dos_close (fd);

    /* エラーか、バッファ長を越えたらバッファオーバー */
    if (len <= 0 || len > buflen)
	return _DOSE_BUFOVER;

    /* EOS を打つ */
    buf[len] = '\0';

    /* バッファをコピーする */
    strncpy (namebuf, _toslash (buf), buflen);

    /* 長さを返す */
    return len;
}
