/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: signal.c,v 1.1.1.1 1993/04/18 16:21:13 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <sys/xsignal.h>

/* Functions */
void (*signal (int sig, void (*func) (int))) (int)
{
    struct sigaction act, oact;

    /* act を作成する */
    act.sa_handler = func;
    act.sa_mask    = _sigactions[sig].sa_mask;
    act.sa_flags   = _sigactions[sig].sa_flags;

    /* シグナルハンドラを設定する */
    if (sigaction (sig, &act, &oact) < 0)
	return SIG_ERR;

    /* 元のアドレスを戻す */
    return oact.sa_handler;
}
