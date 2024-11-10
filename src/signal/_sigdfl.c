/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sigdfl.c,v 1.4 1993/06/22 07:13:45 mura Exp $
 */

/* System headers */
#include <a_out.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/dos.h>
#include <sys/iocs.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/xglob.h>
#include <sys/xstart.h>
#include <sys/xsignal.h>
#include <sys/xresource.h>

/* External variables */
volatile struct sigaction _sigactions[SIG_MAX] = {
    { SIG_DFL, 0, SA_FORCEEXIT },		/* 0 */
    { SIG_DFL, 0, SA_DUMPCORE  },		/* SIGABRT */
    { SIG_DFL, 0, SA_DUMPCORE  },		/* SIGFPE  */
    { SIG_DFL, 0, SA_DUMPCORE  },		/* SIGILL  */
    { SIG_DFL, 0, SA_FORCEEXIT },		/* SIGINT  */
    { SIG_DFL, 0, SA_DUMPCORE  },		/* SIGSEGV */
    { SIG_DFL, 0, SA_FORCEEXIT },		/* SIGTERM */
    { SIG_DFL, 0, SA_FORCEEXIT },		/* SIGALRM */
    { SIG_DFL, 0, SA_DUMPCORE  },		/* SIGKILL */
    { SIG_DFL, 0, SA_DUMPCORE  },		/* SIGBUS  */
    { SIG_DFL, 0, SA_STOPPROC  },		/* SIGSTOP */
    { SIG_DFL, 0, SA_DUMPCORE  },		/* SIGEMT  */
    { SIG_DFL, 0, SA_FORCEEXIT },		/* SIGUSR1 */
    { SIG_DFL, 0, SA_FORCEEXIT },		/* SIGUSR2 */
};

/* File scope functions */
static void _sigcore (einfo_t *info, int size)
{
    int fd;
    int bytes;
    struct corehdr co;

    /* dump するバイト数を求める (size = -1 は Unlimited) */
    bytes = _memcp->block_end - (void *) _memcp;
    if (size > 0 && bytes > size)
	bytes = size;

    /* 全ての領域をクリアする */
    memset (&co, '\0', sizeof (co));

    /* ファイル名を記録する */
    strcpy (co.fname, _argv[0]);

    /* ヘッダを作成する */
    co.magic = CMAGIC;
    co.pc    = info->pc;
    co.sp    = info->sp;
    co.sr    = info->sr;
    co.memcp = (long) _memcp;
    co.procp = (long) _procp;
    co.psta  = (long) _psta;
    co.dsta  = (long) _dsta;
    co.bsta  = (long) _bsta;
    co.csta  = (long) _csta;
    co.vsta  = (long) _vsta;
    co.esta  = (long) _esta;
    co.fsta  = (long) _fsta;
    co.ssta  = (long) _ssta;
    co.hsta  = (long) _hsta;
    co.last  = (long) _last;
    co.mmax  = (long) _mmax;

    /* コアファイルをオープンする */
    if ((fd = _dos_create ("core", _DOS_IFREG)) < 0)
	return;

    /* コアファイルのヘッダを書き込む */
    if (_dos_write (fd, (char *) &co, sizeof co) < 0)
	return;

    /* メモリイメージをダンプする */
    if (_dos_write (fd, (char *) _memcp, bytes) < 0)
	return;

    /* ファイルをクローズする */
    _dos_close (fd);
}

/* Functions */
void _sigdfl (int sig, einfo_t *info)
{
    int mode, limit;
    union wait r;

    /* 動作モードを調べる */
    mode  = _sigactions[sig].sa_flags & SA_MODEMASK;
    limit = _limits[RLIMIT_CORE].rlim_cur;

    /* コアダンプできるかどうかチェックする */
    if (mode == SA_DUMPCORE && limit == 0)
	mode = SA_FORCEEXIT;

    /* 終了コードクリア */
    r.w_status = 0;
    r.w_termsig = sig;

    /* デフォルトの動作を調べる */
    switch (mode) {

    /* SA_FORCEEXIT は強制終了 */
    case SA_FORCEEXIT:
	_print ("%s\r\n", strsignal (sig));
	break;

    /* SA_DUMPCORE はコアダンプ */
    case SA_DUMPCORE:
	_sigcore (info, limit);
	_print ("%s (core dumped)\r\n", strsignal (sig));
	r.w_coredump = 1;
	break;

    /* SA_SIGIGN や SA_STOPPROC は何もしない */
    default:
	return;
    }

    /* 情報を出力する */
    _print ("pc:%x, sp:%x, sr:%x\r\n", info->pc, info->sp, info->sr);

    /* プログラムを exit する */
    _exit (r.w_status);
}
