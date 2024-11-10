/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setclock.c,v 1.1 1993/11/13 06:36:53 mura Exp $
 */

/* System headers */
#include <sys/timers.h>
#include <sys/dos.h>
#include <errno.h>
#include <time.h>

/* Functions */
int setclock (int clock_type, struct timespec *tp)
{
    int val;
    struct tm *p;

    /* 引き数チェック */
    if (tp == 0) {
	errno = EINVAL;
	return -1;
    }

    /* クロックタイプにより分岐 */
    switch (clock_type) {

    case TIMEOFDAY:			/* 時刻 */

	/* Epoch からの秒数を JST に変換 */
	p = localtime ((time_t *) &tp->tv_sec);

	/* システム日付を変更する */
	val = ((p->tm_year - 80) << 9) + ((p->tm_mon + 1) << 5) + p->tm_mday;
	_dos_setdate (val);

	/* システム時刻を変更する */
	val = (p->tm_hour << 16) + (p->tm_min << 8) + p->tm_sec;
	_dos_settim2 (val);

	/* 変更完了 */
	break;

    default:				/* それ以外 */
	errno = EINVAL;
	return -1;

    }

    /* 正常終了 */
    return 0;
}
