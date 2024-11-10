/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sigsetmask.c,v 1.1 1993/06/06 06:08:26 mura Exp $
 */

/* System headers */
#include <signal.h>

/* Functions */
int sigsetmask (int mask)
{
    sigset_t set, oset;

    /* 新しい set を計算する (sigset_t は int なので) */
    set = (sigset_t) mask;

    /* sigprocmask する */
    if (sigprocmask (SIG_SETMASK, &set, &oset) < 0)
	return -1;

    /* 元の mask を返す */
    return (int) oset;
}
