/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sigclrcnt.c,v 1.3 1994/11/26 14:55:57 mura Exp $
 */

/* System headers */
#include <sys/dos.h>
#include <sys/xsignal.h>

/* Functions */
void _sigclrcnt (void)
{
    int ssp;

    /* alarm の設定のフラグ */
    _alarm_on = 0;

    /* カウンタをゼロにする */
    _rtccnt = 0;
    _rtcnxt = 0;

    /* 16Hzを停止し、1Hz (Human68K の Default 値) に設定する */
    ssp = _dos_super (0);
    RTC_RESET_CTRL = 0x04;
    if (ssp > 0)
	_dos_super (ssp);
}
