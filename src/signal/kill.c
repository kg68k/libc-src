/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: kill.c,v 1.1.1.1 1993/04/18 16:20:59 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/xsignal.h>

/* Functions */
int kill (pid_t pid, int sig)
{
    /* pid が自分の pid と等しくない場合はエラー */
    if (pid != getpid ()) {
	errno = ESRCH;
	return -1;
    }

    /* sig が 0 ならば無条件に成功 */
    if (sig == 0)
	return 0;

    /* sig をチェックする */
    if (sig < 1 || sig >= SIG_MAX) {
	errno = EINVAL;
	return -1;
    }

    /* sig を raise する */
    return _raise (sig);
}
