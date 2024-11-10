/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from Mariko.
 * --------------------------------------------------------------------
 * $Id: _fncprof.c,v 1.3 1993/09/07 16:19:26 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <interrupt.h>
#include <sys/dos.h>
#include <sys/iocs.h>
#include <sys/wait.h>
#include <sys/xprof.h>

/* External variables */
int _fpcnt;				/* テーブル使用量 */
int _fpmax;				/* テーブルサイズ */
int _fpuse;				/* プロファイラ実行フラグ */
struct _fncprof **_fpbuf;		/* プロファイルテーブル */

/* Functions */
void __ftime_start (void)
{
    union wait r;
    register struct _fncprof *ptr asm ("extern a2");

    /* profile バッファが未初期化ならば初期化する */
    if (_fpbuf == 0) {

	/* テーブルを初期化する */
	_fpcnt = 0;
	_fpmax = FNC_INITIAL_ALLOC_SIZE;
	_fpbuf = (struct _fncprof **)
	    malloc (sizeof (struct _fncprof *) * _fpmax);

    nomem:

	/* 成功したか? */
	if (_fpbuf == 0) {
	    r.w_status = 0;
	    r.w_retcode = ENOMEM;
	    r.w_liberror = 1;
	    _dos_print ("libprof: virtual memory exhausted\r\n");
	    _dos_exit2 (r.w_status);
	}

	/* フラグを立てる */
	_fpuse = 1;

    }

    /* バッファが一杯ならば拡張する */
    else if (_fpcnt >= _fpmax - 1) {

	/* テーブルを更新する */
	_fpmax += FNC_ENLARGE_BUFFER_STEP;
	_fpbuf = (struct _fncprof **)
	    realloc (_fpbuf, sizeof (struct _fncprof *) * _fpmax);

	/* あとは同じ処理 */
	goto nomem;

    }

    /* 再帰レベルが 0 ならば時間を記録 */
    if (ptr->call_c == 0) {

	/* カウント 0 の時にテーブルに登録 */
	if (ptr->count == 0)
	    _fpbuf[_fpcnt++] = ptr;

	/* 開始時間を記録する */
	ptr->wtime = _iocs_ontime ();

    }

    /* 再帰レベル、呼び出し回数カウント */
    ptr->call_c++;
    ptr->count++;

    /* 戻る */
    IRTS ();
}

/* Functions */
void __ftime_end (void)
{
    int now;
    register struct _fncprof *ptr asm ("extern a2");

    /* 再帰レベルを減算し、0 ならば処理 */
    if (--ptr->call_c <= 0) {

	/* 現在のシステムクロックを求める */
	now = _iocs_ontime ();

	/* 経過時間を加算する */
	ptr->atime += now - ptr->wtime;

    }

    /* 戻る */
    IRTS ();
}

/* Functions */
void __display_function_profile (void)
{
    int i, now;
    double tim;
    char buffer[256];

    /* 関数毎にチェック */
    for (i = 0; i < _fpcnt; i++) {

	/* 計測中の関数があれば計測を確定させる */
	if (_fpbuf[i]->call_c) {

	    /* 現在のシステムクロックを求める */
	    now = _iocs_ontime ();

	    /* 経過時間を加算する */
	    _fpbuf[i]->atime += now - _fpbuf[i]->wtime;

	}

    }

    /* 関数毎に出力 */
    for (i = 0; i < _fpcnt; i++) {

	/* 積算時間を求める */
	tim = (double) _fpbuf[i]->atime / 100.0;

	/* 積算時間を表示する */
	sprintf (buffer, "Function %32s : %c%8.2f sec(s) : %10d time(s)\r\n",
		 _fpbuf[i]->name,
		 _fpbuf[i]->call_c ? '*' : ' ', tim,
		 _fpbuf[i]->count);

	/* DOS コールで表示させる */
	_dos_print (buffer);

    }
}
