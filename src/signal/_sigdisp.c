/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sigdisp.c,v 1.1.1.1 1993/04/18 16:20:45 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <string.h>
#include <sys/xsignal.h>

/* External variables */
volatile einfo_t _sigpendinginfo[SIG_MAX];
volatile sigset_t _sigmask;
volatile sigset_t _sigpendingset;

/* Functions */
int _sigdispatch (void)
{
    int sig;
    einfo_t *errorinfo;
    sigset_t _maskedsig;
    sigset_t _oldmask;
    void (*function) (int);

    /* カレントプロセスマスクを摘要 */
    _maskedsig = _sigpendingset & ~_sigmask;

    /* pending されている? */
    if (_maskedsig == 0)
	return -1;

    /* カレントプロセスマスクを保存する */
    _oldmask = _sigmask;

    /* sig を 1 つ取り出す */
    sig = ffs (_maskedsig) - 1;

    /* シグナルをマスク */
    _sigmask |= (1 << SIGALRM) | (1 << sig) | _sigactions[sig].sa_mask;

    /* pending から外す */
    _sigpendingset &= ~(1 << sig);

    /* 処理関数と、エラー情報を取り出す */
    function  = _sigactions[sig].sa_handler;
    errorinfo = (einfo_t *) &_sigpendinginfo[sig];

    /* SA_RESETHAND ならばハンドラを元に戻す */
    if (_sigactions[sig].sa_flags & SA_RESETHAND)
	_sigactions[sig].sa_handler = SIG_DFL;

    /* SIG_DFL ならばデフォルトのハンドラを呼び出す */
    if (function == SIG_DFL)
	_sigdfl (sig, errorinfo);

    /* さもなくばユーザー定義ハンドラを呼び出す */
    else {
	_pause = 0;
	(*(void (*) (int, einfo_t *)) function) (sig, errorinfo);
    }

    /* マスクを元に戻す */
    _sigmask = _oldmask;

    /* 成功 */
    return 0;
}
