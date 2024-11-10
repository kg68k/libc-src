/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: gmtime.c,v 1.1.1.1 1993/04/18 16:38:27 mura Exp $
 */

/* System headers */
#include <time.h>
#include <sys/xtime.h>

/* External variables */
struct tm _gmtm;

/* Functions */
struct tm *gmtime (const time_t *caltime)
{
    int year, mon, day;
    time_t tick, ytik;

    /* 秒数を取り出す */
    tick = *caltime;

    /* まず、時分秒を求める */
    _gmtm.tm_sec = tick % 60;
    tick /= 60;
    _gmtm.tm_min = tick % 60;
    tick /= 60;
    _gmtm.tm_hour = tick % 24;
    tick /= 24;

    /* 曜日を求める */
    _gmtm.tm_wday = (tick + 4) % 7;

    /* カウンタの初期化 */
    ytik = tick;
    year = 1970;
    mon  = 0;

    /* 年月日および年内の通し日数を求める */
    while (tick >= (day = _getmday (mon, year))) {
	tick -= day;
	if (++mon >= 12) {
	    ytik -= _isleap (2, year) ? 366 : 365;
	    mon = 0;
	    year++;
	}
    }

    /* 求めたデータを設定する (UTC は常に isdst = 0) */
    _gmtm.tm_yday   = ytik;
    _gmtm.tm_year   = year - 1900;
    _gmtm.tm_mon    = mon;
    _gmtm.tm_mday   = tick + 1;
    _gmtm.tm_isdst  = 0;
    _gmtm.tm_gmtoff = 0;
    _gmtm.tm_zone   = "GMT";

    /* t へのポインタを返す */
    return &_gmtm;
}
