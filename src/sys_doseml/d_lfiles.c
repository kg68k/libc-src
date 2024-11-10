/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: d_lfiles.c,v 1.5 1993/08/16 13:38:05 mura Exp $
 */

/* System headers */
#include <sys/dos.h>
#include <sys/xdoseml.h>

/* Typedefs */
typedef int (*func) (struct _filbuf *, const char *, unsigned short);

/* Functions */
int _dos_lfiles (struct _filbuf *buf, const char *name, int atr)
{
#ifndef LNDRV_C_FUNCTION
    int ssp;
#endif
    int ret;
    int *lnenv;
    func xlfiles;

    /* lndrv が常駐していなければ通常の FILES 処理 */
    if ((lnenv = _dos_importlnenv ()) == 0)
	return _dos_files (buf, name, atr);

#ifdef LNDRV_C_FUNCTION
    /* C_LFILES ベクターのアドレスを取得する */
    xlfiles = (func) lnenv[C_LFILES];
    ret = xlfiles (buf, name, (unsigned short) atr);
#else
    /* LFILES ベクターのアドレスを取得する */
    xlfiles = (func) lnenv[LFILES_VECTOR];

    /* スーパーバイザーで、lndrv 内部を直接呼び出す */
    ssp = _dos_super (0);

    /* 呼び出し */
    ret = CALL_XLFILES (xlfiles, buf, name, (unsigned short) atr);

    /* ユーザーモードに戻る */
    if (ssp > 0)
	_dos_super (ssp);
#endif

    return ret;
}
