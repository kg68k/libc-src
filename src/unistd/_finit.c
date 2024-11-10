/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _finit.c,v 1.2 1993/05/06 13:43:32 mura Exp $
 */

/* System headers */
#include <fcntl.h>
#include <sys/xunistd.h>

/* File scope variables */
static const char _ttynames[5][4] = {
    "con",				/* STDIN */
    "con",				/* STDOUT */
    "con",				/* STDERR */
    "aux",				/* STDAUX */
    "prn",				/* STDPRN */
};

/* File scope variables */
static int _ttymodes[5] = {
    O_RDONLY | O_TEXT,			/* STDIN */
    O_WRONLY | O_TEXT,			/* STDOUT */
    O_WRONLY | O_TEXT,			/* STDERR */
    O_RDWR | O_BINARY,			/* STDAUX */
    O_WRONLY | O_TEXT,			/* STDPRN */
};

/* Functions */
void _finit (void)
{
    int i;

    /* 標準ファイルハンドルを初期化する */
    for (i = 0; i < 5; i++) {
	_open (_ttynames[i], i, _ttymodes[i]);
	_fddb[i].inuse = _FD_IMPORTED;
    }
}
