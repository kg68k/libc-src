/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sinit.c,v 1.4 1994/11/26 14:57:29 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* File scope variables */
static const char _smodes[5][4] = {
    "r",				/* stdin */
    "w",				/* stdout */
    "w",				/* stderr */
    "a+b",				/* stdaux */
    "w",				/* stdprn */
};

/* File scope variables */
static int _sbuffs[5] = {
    _IOLBF,				/* stdin */
    _IOLBF,				/* stdout */
    _IONBF,				/* stderr */
    _IONBF,				/* stdaux */
    _IOLBF,				/* stdprn */
};

/* Functions */
void _sinit (void)
{
    int i, buff;

    /* 標準ファイルストリームを初期化する */
    for (i = 0; i < 5; i++) {

	/* 相手が端末じゃないなら強制的に _IOFBF にする */
	buff = isatty (i) ? _sbuffs[i] : _IOFBF;

	/* 初期化 */
	(void) _sopen (&_iob[i], _smodes[i], buff);

	/* _IOAPPLS フラグを消す */
	_iob[i]._flag &= ~_IOAPPLS;

	/* ファイルハンドルを登録 */
	_iob[i]._file = i;

    }
}
