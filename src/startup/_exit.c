/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _exit.c,v 1.4 1994/05/02 16:48:20 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <stdio.h>
#include <sys/dos.h>
#include <sys/xstart.h>
#include <sys/xsignal.h>
#include <sys/xprof.h>

/* External variables */
int _onexnums;
void (*_onexprcs[ONEXIT_MAX]) (void);

/* Functions */
void _exit (int ecode)
{
    int i;

    /* 高水準ファイルハンドルは exit すれば解放される */
    fcloseall ();

    /* 低水準ファイルハンドルをすべて解放する */
    closeall ();

    /* シグナルを停止する */
    _sigend ();

    /* 登録された関数を、逆の順番に呼び出す */
    for (i = _onexnums - 1; i >= 0; i--)
	(*_onexprcs[i]) ();

    /* ブロックプロファイル使用中か? */
    if (_bluse)
	__display_block_profile ();

    /* 関数プロファイル使用中か? */
    if (_fpuse)
	__display_function_profile ();

    /* 終わり */
    _dos_exit2 (ecode);
}
