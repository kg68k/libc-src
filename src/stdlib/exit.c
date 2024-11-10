/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: exit.c,v 1.3 1994/05/02 16:52:38 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <sys/xstart.h>
#include <sys/xprof.h>

/* External variables */
int _exitnums;
void (*_exitprcs[ATEXIT_MAX]) (void);

/* Functions */
void exit (int ecode)
{
    int i;

    /* 登録された関数を、逆の順番に呼び出す */
    for (i = _exitnums - 1; i >= 0; i--)
	(*_exitprcs[i]) ();

    /* グルーバルデストラクタの呼び出し */
    if (_cplusplus)
	_dtors ();

    /* 最後の終了を行う */
    _exit (ecode);
}
