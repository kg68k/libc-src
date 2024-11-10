/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _blkprof.c,v 1.3 1993/09/07 16:19:21 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/wait.h>
#include <sys/xprof.h>
#include <sys/xstart.h>

/* External varibles */
int _blcnt;				/* テーブル使用量 */
int _blmax;				/* テーブルサイズ */
int _bluse;				/* プロファイラ実行フラグ */
struct _blkprof **_blbuf;		/* プロファイルテーブル */

/* Functions */
void __bb_init_func (struct _blkprof *block)
{
    union wait r;

    /* profile テーブル は初期化されている? */
    if (_blbuf == 0) {

	/* テーブルを初期化する */
	_blcnt = 0;
	_blmax = BLK_INITIAL_ALLOC_SIZE;
	_blbuf = (struct _blkprof **)
	    malloc (sizeof (struct _blkprof *) * _blmax);

    nomem:

	/* 成功したか? */
	if (_blbuf == 0) {
	    r.w_status = 0;
	    r.w_liberror = 1;
	    r.w_retcode = ENOMEM;
	    _dos_print ("libprof: virtual memory exhausted\r\n");
	    _dos_exit2 (r.w_status);
	}

	/* フラグを立てる */
	_bluse = 1;

    }

    /* バッファが一杯ならば拡張する */
    else if (_blcnt >= _blmax - 1) {

	/* テーブルを更新する */
	_blmax += BLK_ENLARGE_BUFFER_STEP;
	_blbuf = (struct _blkprof **)
	    realloc (_blbuf, sizeof (struct _blkprof *) * _blmax);

	/* あとは同じ処理 */
	goto nomem;

    }

    /* ブロックテーブル初期化ずみフラグ */
    block->init = 1;

    /* ブロックテーブル登録 */
    _blbuf[_blcnt++] = block;
}

/* Functions */
void __display_block_profile (void)
{
    int i, blk;
    struct _blkprof *p;
    char buffer[256];

    /* ブロックテーブルを出力 */
    for (i = 0; i < _blcnt; i++) {

	/* ポインタ取り出し */
	p = _blbuf[i];

	/* プロファイル情報の出力 */
	printf ("\nProfile source %s : %d block(s)\n\n", p->file_name, p->size);

	/* ブロック毎にプロファイル出力 */
	for (blk = 0; blk <  _blbuf[i]->size; blk++) {

	    /* 積算時間を表示する */
	    sprintf (buffer, "\tBlock no. %6d address %6X offset %6X : %10d time(s)\r\n",
		     blk,
		     (int) p->addr[blk],
		     (int) p->addr[blk] - (int) _psta,
		     p->count[blk]);

	    /* DOS コールで表示させる */
	    _dos_print (buffer);

	}

    }
}
