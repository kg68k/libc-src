/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: raise.c,v 1.1.1.1 1993/04/18 16:21:01 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/xsignal.h>

/* Functions */
int raise (int sig)
{
    /* sig をチェックする */
    if (sig < 1 || sig >= SIG_MAX) {
	errno = EINVAL;
	return -1;
    }

    /* sig を raise する */
    return _raise (sig);
}
