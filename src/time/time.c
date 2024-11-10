/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: time.c,v 1.1.1.1 1993/04/18 16:38:34 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <time.h>
#include <sys/dos.h>
#include <sys/xtime.h>

/* File scope functions */
time_t tmtosec (struct tm *t)
{
    int y, m, d;
    int h, i, s;

    /* tm 構造体の値は 1900 年からの相対値 */
    y = t->tm_year + 1900;

    /* 0 から 11 */
    m = t->tm_mon;

    /* 0 から 31 配列参照の為、-1 */
    d = t->tm_mday - 1;

    /* 0 から 23 */
    h = t->tm_hour;

    /* 0 から 59 */
    i = t->tm_min;

    /* 0 から 61 */
    s = t->tm_sec;

    /* tm 構造体のチェック */
    if (y < 1970 ||
	m < 0 || m > 11 ||
	d < 0 || d >= _getmday (m, y) ||
	h < 0 || h > 23 ||
	i < 0 || i > 59 ||
	s < 0 || s > 61)
	return -1;

    /* その年における、その月のその日までのトータル日数 */
    d += _getyday (m, y);

    /* 1970/01/01 からのトータル日数 */
    d += 365 * (y - 1970) + _getleaps (y);

    /* 戻り値は秒数なので計算 */
    return 86400 * d + 3600 * h + 60 * i + s;
}

/* Functions */
time_t time (time_t *timeptr)
{
    struct tm t;
    time_t retval;
    unsigned long getdate;
    unsigned long gettime;

    /* DOS コールで日付と時間を調べる */
    getdate = _dos_getdate ();
    gettime = _dos_gettim2 ();

    /* tm 構造体に変換する */
    t.tm_year = ((getdate >> 9) & 0x7f) + 80;
    t.tm_mon  = ((getdate >> 5) & 0x0f) - 1;
    t.tm_mday = (getdate & 0x01f);
    t.tm_wday = (getdate >> 16);
    t.tm_hour = (gettime >> 16);
    t.tm_min  = (gettime >> 8) & 0x0ff;
    t.tm_sec  = (gettime & 0x0ff);

    /* tm 構造体から秒に変換する */
    if ((retval = tmtosec (&t)) >= 0) {

	/* システムクロックが JST なので JST->UTC へ逆補正 */
	retval += _TZADJUST;

    }

    /* timeptr に納める */
    if (timeptr)
	*timeptr = retval;

    return retval;
}
