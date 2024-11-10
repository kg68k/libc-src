/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _start.c,v 1.8 1994/07/31 17:23:28 mura Exp $
 */

/* System headers */
#include <sys/types.h>
#include <sys/dos.h>
#include <sys/iocs.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/xstart.h>
#include <sys/xmath.h>
#include <sys/xstat.h>
#include <sys/xsignal.h>
#include <sys/xtime.h>
#include <sys/xstdio.h>
#include <sys/xunistd.h>
#include <sys/xresource.h>

/* Functions */
void _start (struct _mep *mp)
{
    union wait r;
    extern int main (int, char **, char **);

    /*
    ** (1) 固定セクションの位置決定、及びコマンドラインの解析
    */

    {
	/* TEXT, DATA, BSS セクションの位置を決定する */
	_memcp = mp;
	_procp = (struct _psp *) ((char *) mp + 16);
	_psta = (void *) ((char *) mp + 256);
	_dsta = _procp->heap;
	_bsta = _procp->bss;

	/* コマンドラインを内部にコピーする */
	_csta = _procp->stack;
	_comline = _procp->comline + 1;
	_argc = _dehupair (_comline, _csta);

	/* ARGVBUF を生成する */
	_vsta = PAD (_csta + strlen (_comline));
	_argv = _vsta;
	_argc = _enargv (_procp, _argc, _argv, _csta);
    }

    /*
    ** (2) 環境変数エリアの取り込み、及び可変サイズセクションの位置決定
    */

    {
	char *rp, *wp, **vector;

	/* 環境エリアを内部にコピーする */
	_esta = PAD (_vsta + (sizeof (char *) * (_argc + 1)));
	wp = _esta;
	rp = _procp->env + 4;
	while (*rp)
	    while (*wp++ = *rp++);

	/* 最後を null で打ち止めする */
	*wp++ = '\0';

	/* ENVBUF を作成する */
	_fsta = PAD (wp);
	_envp = environ = vector = (char **) _fsta;
	rp = _esta;
	while (*rp) {
	    *vector++ = rp;
	    while (*rp++);
	}

	/* 配列の最後は常に null pointer */
	*vector++ = 0;

	/* スタック、ヒープ位置を計算する */
	_ssta = PAD (vector);
	_hsta = PAD (_ssta + _stacksize);
	_last = PAD (_hsta + _heapsize);
	_mmax = _memcp->block_end;
    }

    /*
    ** (3) スタックの設定
    */

    {
	/* ユーザースタックポインタの設定 */
	asm volatile ("move.l %0,sp" : /* no outputs */ : "g" (_hsta));

	/* 現在までのサイズで SETBLOCK する */
	if (_dos_setblock (_procp, (int) _last - (int) _procp) < 0) {
	    r.w_status = 0;
	    r.w_liberror = 1;
	    r.w_retcode = ENOMEM;
	    _dos_print ("libc: setblock failed.\r\n");
	    _dos_exit2 (r.w_status);
	}
    }

    /*
    ** (4) 各種モジュールの初期化
    */

    {
	/* dos call のベクタ移動 */
	_vectormove ();

	/* クロックの計測開始時間を記録する */
	_inclock = (clock_t) _iocs_ontime ();

	/* コプロセッサチェック */
	_havefpu = _iscopro ();

	/* resource limit の値を取り込む */
	_loadrlimits ();

	/* signal 処理を開始する */
	_siginit ();

	/* 低水準ファイルハンドルの初期化 */
	_finit ();

	/* 高水準ファイルストリームの初期化 */
	_sinit ();

	/* 指定があればスーパーバイザーモードへ */
	if (_superman & _SUPER_GO)
	    _SSP = _dos_super (0);

	/* FLOAT 強制フラグが立っていれば fpu_off */
	if (_superman & _SUPER_FLOAT)
	    _havefpu &= ~(_FLG_IOFPU | _FLG_FPU);

	/* タイムゾーンの初期化 */
	tzset ();

    }

    /*
    ** (5) C++ のグローバルコンストラクタ起動
    */

    /* errno をクリア */
    errno = 0;

    /* C++ のグルーバルコンストラクタを起動する */
    if (_cplusplus)
	_ctors ();

    /*
    ** (6) 起動と終了
    */

    /* main を呼び出す */
    exit (main (_argc, _argv, _envp));
}
