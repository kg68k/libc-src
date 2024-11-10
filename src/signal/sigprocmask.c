/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sigprocmask.c,v 1.2 1994/05/02 16:47:46 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <errno.h>
#include <sys/xsignal.h>

/* Functions */
int sigprocmask (int how, sigset_t *set, sigset_t *oset)
{
    sigset_t newmask;

    /* 元のマスクを保存する */
    if (oset)
	*oset = _sigmask;

    /* set が null pointer ならば _sigmask は変更しない */
    if (set) {

	/* how に応じて新しい mask を計算する */
	switch (how) {
	case SIG_BLOCK:
	    newmask = _sigmask | *set;
	    break;
	case SIG_UNBLOCK:
	    newmask = _sigmask & ~(*set);
	    break;
	case SIG_SETMASK:
	    newmask = *set;
	    break;
	default:
	    errno = EINVAL;
	    return -1;
	}

	/* 新しいマスクを設定する */
	_sigmask = newmask;
    }

    /* 新しいマスクで signal dispatching を試す */
    while (_sigdispatch () >= 0);

    /* 成功 */
    return 0;
}
