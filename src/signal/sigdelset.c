/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sigdelset.c,v 1.1.1.1 1993/04/18 16:21:07 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <errno.h>
#undef sigdelset

/* Functions */
int sigdelset (sigset_t *setp, int sig)
{
    /* シグナル番号チェック */
    if (sig < 1 || sig >= SIG_MAX) {
	errno = EINVAL;
	return -1;
    }

    /* sigset から sig のビットを除く */
    *setp &= ~(1 << sig);
    return 0;
}