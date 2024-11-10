/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sigsetcnt.c,v 1.3 1994/11/26 14:56:06 mura Exp $
 */

/* System headers */
#include <sys/dos.h>
#include <sys/xsignal.h>

/* Functions */
void _sigsetcnt (int n, int next)
{
    int ssp;

    /* カウンタをセットする */
    _rtccnt = n;
    _rtcnxt = next;

    /* RTC を操作して 16Hz Clock を開始する */
    ssp = _dos_super (0);
    RTC_RESET_CTRL = 0x08;
    if (ssp > 0)
	_dos_super (ssp);

    /* alarm の設定のフラグ */
    _alarm_on = 1;
}
