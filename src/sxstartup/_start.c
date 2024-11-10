/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _start.c,v 1.2 1994/07/27 13:51:18 mura Exp $
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

/* File scope variables */
static char _argvbuffer[512];
static char *_argvvector[130];

/* Functions */
void _start (struct _sx_reg *_reg_list)
{
    extern int main (int, char **, char **);

    /*
    ** (1) ワークエリアの確保とセット
    */

    {
	handle work;

	work = _sx_rinit ();
	if (work) {
	    asm volatile ("movea.l (%0),a5\n\t"
			  "adda.l #$8000,a5"
			    : /* no outputs */
			    : "a" (work));
	    _data_hdl1 = work;
	}
	else {
	    DMError (0x101,"libc: Not enough memory.\n");
	    exit (-1);
	}
    }

    /*
    ** (2) 固定セクションの位置決定、及びコマンドラインの解析
    */

    {
	char * work = *_data_hdl1;

	/* dos call のベクタ移動 */
	_vectormove ();

	/* コモンエリアの位置を書き込む */
	_common = _reg_list->common_top;

	/* TEXT, DATA, BSS セクションの位置を決定する */
	_procp = _dos_getpdb ();
	_memcp = (struct _mep *) ((char*) _procp - sizeof (struct _mep));
	_psta = ((void *)&__size_info) - __size_info.text;
	_dsta = &__size_info;
	_bsta = _dsta + __size_info.data + __size_info.rdata + __size_info.rldata + __size_info.roffset;
	_rdsta = work;
	_rbsta = work + __size_info.rdata;
	_rssta = _rbsta + __size_info.rbss + __size_info.rcomm;
	_rldsta = _rssta + __size_info.rstack;
	_rlbsta = _rldsta + __size_info.rldata;
	_rlssta = _rlbsta + __size_info.rlbss + __size_info.rlcomm;

	/* コマンドラインを内部にコピーする */
	_csta = _argvbuffer;
	_comline = _reg_list->cmdline + 1;
	_argc = _dehupair (_comline, _csta);

	/* ARGVBUF を生成する */
	_argv = _vsta = _argvvector;
	_argc = _enargv (_argc, _argv, _csta);
    }

    /*
    ** (3) 環境変数エリアの計算、及びスタックエリアの確保
    */

    {
	char *env = _reg_list->envptr + 4;
	int envc, len;

	envc = 1;
	len = 0;
	while (len++, *env++) {
	    envc++;
	    while (len++, *env++);
	}

	_data_hdl2 = MMChHdlNew (envc * sizeof (char *) + len + _stacksize + _heapsize);
	if (!_data_hdl2) {
	    DMError (0x101, "libc: Not enough memory.\n");
	    MMHdlUnlock (_data_hdl1);
	    MMHdlDispose (_data_hdl1);
	    exit (-1);
	}

	MMHdlLock (_data_hdl2);
	_esta = *_data_hdl2;
	_ssta = _esta + envc + len;
	_hsta = PAD(_ssta + _stacksize);
	_last = _hsta + _heapsize;
	_mmax = _procp->block_end;
	asm volatile ("move.l %0,sp\n" :: "g" (_hsta));

	{
	    char *rp, *wp, **vector;

	    /* 環境エリアを内部にコピーする */
	    wp = _esta;
	    rp = _reg_list->envptr + 4;
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

	}
    }

    /*
    ** (4) 各種モジュールの初期化
    */

    {
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
