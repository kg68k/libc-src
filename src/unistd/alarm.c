/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: alarm.c,v 1.1.1.1 1993/04/18 16:39:06 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/xsignal.h>

/* Functions */
unsigned int alarm (unsigned int seconds)
{
    int rest;

    /* 現在の残り秒数を得る */
    rest = _rtccnt / RTC_HZ;

    /* seconds が 0 ならばキャンセル */
    if (seconds == 0)
	_sigclrcnt ();

    /* さもなくばリセットする */
    else
	_sigsetcnt (seconds * RTC_HZ, 0);

    /* 前回の残り秒数を返す */
    return rest;
}
