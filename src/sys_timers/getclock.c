/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getclock.c,v 1.1 1993/11/13 06:36:49 mura Exp $
 */

/* System headers */
#include <sys/timers.h>
#include <sys/iocs.h>
#include <time.h>
#include <errno.h>

/* Functions */
int getclock (int clock_type, struct timespec *tp)
{
    int clock;

    /* 引き数チェック */
    if (tp == 0) {
	errno = EINVAL;
	return -1;
    }

    /* 1/100 単位クロックを得る */
    clock = _iocs_ontime ();

    /* クロックタイプにより分岐 */
    switch (clock_type) {

    case TIMEOFDAY:			/* 時刻 */
	tp->tv_sec  = (time (0));
	tp->tv_nsec = (clock % 100) * 10000000;
	break;

    case UPTIME:			/* 起動からの時間 */
	tp->tv_sec  = (clock / 100);
	tp->tv_nsec = (clock % 100) * 10000000;
	break;

    default:				/* それ以外 */
	errno = EINVAL;
	return -1;

    }

    /* 正常終了 */
    return 0;
}
