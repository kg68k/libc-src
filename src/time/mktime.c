/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mktime.c,v 1.1.1.1 1993/04/18 16:38:30 mura Exp $
 */

/* System headers */
#include <time.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <sys/xtime.h>

/* Functions */
time_t mktime (struct tm *timeptr)
{
    int y, m, d, s;
    long savtz;
    double ts;
    struct tm *tm;
    time_t retval;

    /* 地域時間情報を初期化 */
    tzset ();

    /* 年月日を補正する */
    m = timeptr->tm_year * 12 + timeptr->tm_mon;
    y = m / 12 + 1900;
    m = m % 12;
    d = 365 * (y - 1970) + _getleaps (y)
	+ _getyday (m, y) + timeptr->tm_mday - 1;

    /* その日の内の秒数を計算する */
    s = 3600 * timeptr->tm_hour
	+ 60 * timeptr->tm_min + timeptr->tm_sec;

    /* トータル秒数を計算 */
    ts = (double) d * 86400.0 + (double) s;

    /* 時間チェック */
    if (ts < 0.0 || ts > (double) LONG_MAX) {
	errno = EINVAL;
	return -1;
    }

    /* time_t に変換 */
    retval = (time_t) ts;

    /* 一時的にタイムゾーンを退避する */
    savtz = timezone;

    /* isdst が正ならばサマータイムを仮定する */
    if (timeptr->tm_isdst > 0) {
	retval += timezone_dst;
	timezone = timezone_dst;
    }

    /* isdst が 0 ならばサマータイムでないと仮定する */
    else if (timeptr->tm_isdst == 0) {
	retval += timezone_std;
	timezone = timezone_std;
    }

    /* isdst が負ならばサマータイムかどうかは現在の状態による */
    else {
	retval += timezone;
	timezone = timezone;
    }

    /* 補正後の値からまた地域時間に戻す */
    tm = localtime (&retval);
    *timeptr = *tm;

    /* 退避していたタイムゾーンを戻す */
    timezone = savtz;

    /* 秒数を戻す */
    return retval;
}
