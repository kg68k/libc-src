/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: d_import.c,v 1.3 1993/10/06 17:05:55 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/xdoseml.h>
#include <sys/xstart.h>

/* Structures and unions */
struct _memimg {
    struct _mep mep;
    struct _psp psp;
    char prog[0];
};

/* Macros */
#define _GETMP(psp)   ((char *) (psp) - sizeof (struct _mep))
#define _ISKEEPMEM(x) (((int) (x) & 0xff000000) == 0xff000000)

/* File scope functions */
void *_keeppr_search (const struct _psp *psp, const char *str, char offset)
{
    void *addr;
    struct _memimg *ps;

    /* addr を初期化 */
    addr = 0;

    /* 自分のメモリ管理ポインタを求める */
    ps = (struct _memimg *) _GETMP (psp);

    /* メモリ管理ポインタをたどる */
    while (ps = ps->mep.prev_mp) {

	/* 常駐プログラムの TEXT 部分の offset 位置の文字列を調べる */
	if (_ISKEEPMEM (ps->mep.parent_mp)) {
	    if (strncmp (ps->prog + offset, str, strlen (str)) == 0) {
		addr = ps->prog;
		break;
	    }
	}

    }

    /* addr を返す */
    return addr;
}

/* Functions */
int *_dos_importlnenv (void)
{
    int ssp;
    static int _chkflg = 0;
    static int *_lnenv;

    /* 常駐チェック済みか調べる */
    if (_chkflg == 0) {

	/* チェック済み */
	_chkflg = 1;

	/* スーパーバイザーモードへ移行する */
	ssp = _dos_super (0);

	/* lndrv を検索 */
	_lnenv = _keeppr_search (_procp, "LNDR", 0);

	/* チェック */
	if (_lnenv == 0 || _lnenv[LNDRV_VERSION] == 'V   ' ||
	    _lnenv[LNDRV_VERSION] == 'V030' || _lnenv[LNDRV_VERSION] == 'V100')
	    _lnenv = 0;

	/* ユーザーモードへ移行する */
	if (ssp > 0)
	    _dos_super (ssp);

    }

    /* その環境を返す */
    return _lnenv;
}
