/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sigaction.c,v 1.1.1.1 1993/04/18 16:21:02 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <signal.h>
#include <sys/dos.h>
#include <sys/xsignal.h>

/* Functions */
int sigaction (int sig, const struct sigaction *act, struct sigaction *oact)
{
    volatile struct sigaction *sgp;

    /* sig の範囲チェック */
    if (sig < 1 || sig >= SIG_MAX || (act && sig == SIGKILL)) {
	errno = EINVAL;
	return -1;
    }

    /* sigaction のアドレスを得る */
    sgp = &_sigactions[sig];

    /* 元の sigaction を保存する */
    if (oact)
	*oact = *sgp;

    /* 新しい sigaction をコピーする */
    if (act) {

	/* 構造体をコピー */
	*sgp = *act;

	/* もし SIGINT ならば breakck を操作する */
	if (sig == SIGINT)
	    _dos_breakck (act->sa_handler == SIG_IGN ? 2 : 1);

    }

    /* 成功 */
    return 0;
}
