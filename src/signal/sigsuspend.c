/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sigsuspend.c,v 1.1.1.1 1993/04/18 16:21:18 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <unistd.h>

/* Functions */
int sigsuspend (sigset_t *sigmask)
{
    sigset_t omask;

    /* 新しい signal mask を設定する */
    if (sigprocmask (SIG_SETMASK, sigmask, &omask) < 0)
	return -1;

    /* signal が到着するまで pause する */
    pause ();

    /* 元の signal mask に戻す */
    sigprocmask (SIG_SETMASK, &omask, 0);

    /* 成功 */
    return -1;
}
