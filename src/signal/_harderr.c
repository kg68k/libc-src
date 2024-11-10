/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _harderr.c,v 1.2 1993/11/13 06:34:04 mura Exp $
 */

/* System headers */
#include <interrupt.h>
#include <sys/dos.h>
#include <sys/xsignal.h>

/* External varaibles */
hardfunc_t _harderr_handler;

/* Functions */
void _harderr (void (*func) ())
{
    /* ハンドラを記憶 */
    _harderr_handler = (hardfunc_t) func;
}

/* Functions */
void __volatile _hardresume (int result)
{
    RETREG (value, d0);

    /* result の値によって分類 */
    switch (result) {

    case _HARDERR_ABORT:
	value = _TE_ABORT;		/* 終了 (A) */
	break;

    case _HARDERR_FAIL:
	_doscall_escape (_DOSE_NOENT);	/* 失敗 (F) */
	break;

    case _HARDERR_IGNORE:
	value = _TE_IGNORE;		/* 無視 (I) */
	break;

    case _HARDERR_RETRY:
	value = _TE_RETRY;		/* 再試行 (R) */
	break;

    default:
	value = _TE_OLDVEC;		/* それ以外は元のベクタへ */
	break;

    }

    /* 実際の処理ルーチンへ */
    _harderror_return ();
}

/* Functions */
void __volatile _hardretn (int dos_err_code)
{
    /* DOS コールを中断し、呼び出しもとへ戻る */
    _doscall_escape (dos_err_code);
}
