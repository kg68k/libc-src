/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: localtime.c,v 1.1.1.1 1993/04/18 16:38:29 mura Exp $
 */

/* System headers */
#include <time.h>

/* Functions */
struct tm *localtime (const time_t *caltime)
{
    struct tm *tm;
    time_t newtime;

    /* タイムゾーンを再計算する */
    tzset ();

    /* 地域時間へ補正する */
    newtime = *caltime - timezone;

    /* tm 構造体に変換する */
    tm = gmtime (&newtime);

    /* 地域情報だけ再設定する */
    tm->tm_isdst  = daylight;
    tm->tm_gmtoff = timezone;
    tm->tm_zone   = tzname[(daylight && tzname[1] && *tzname[1]) ? 1 : 0];

    /* tm を戻す */
    return tm;
}
