/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _getmday.c,v 1.1.1.1 1993/04/18 16:38:15 mura Exp $
 */

/* System headers */
#include <time.h>
#include <sys/xtime.h>

/* File scope variables */
static char days[] = {					/* 毎月の日数 */
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/* Functions */
int _getmday (int month, int year)
{
    return days[month]
	+ ((month == 1 && ((year % 400) == 0
			   || ((year % 4) == 0 && (year % 100) != 0))) ? 1 : 0);
}
