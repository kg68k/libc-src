/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strsignal.c,v 1.3 1994/07/31 17:23:13 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <errno.h>

/* Functions */
char *strsignal (int sig)
{
    /* 範囲チェック */
    if (sig < 0 || sig >= sys_nsig)
	errno = -1;

    /* 該当するメッセージを返す */
    return (char *) sys_siglist[sig + 1];
}
