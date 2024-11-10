/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sleep.c,v 1.1.1.1 1993/04/18 16:38:57 mura Exp $
 */

/* System headers */
#include <sys/dos.h>
#include <sys/iocs.h>
#include <sys/xsignal.h>
#include <sys/xunistd.h>

/* File scope functions */
unsigned int _tsleep (unsigned int ticks)
{
    int start, rest;

    /* 測定開始時刻を記録 */
    start = _iocs_ontime ();

    /* pause フラグを立てる */
    _pause = 1;

    /* あとは設定時刻がくるまで待つ */
    do {

	/* 残り単位時間を計算 */
	if ((rest = (_iocs_ontime () - start) % 8640000) < 0)
	    rest += 8640000;

    } while (_pause && rest < ticks);

    /* pause フラグを消す */
    _pause = 0;

    return 0;
}
