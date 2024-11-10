/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: asctime.c,v 1.1.1.1 1993/04/18 16:38:20 mura Exp $
 */

/* System headers */
#include <time.h>
#include <stdio.h>

/* File scope variables */
static char wday_name[][4] = {
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat",
};

/* File scope variables */
static char mon_name[][4] = {
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec",
};

/* Functions */
char *asctime (const struct tm *timeptr)
{
    static char buffer[32];

    /* フォーマット変換 */
    sprintf (buffer, "%.3s %.3s %02d %.2d:%.2d:%.2d %d\n",
	     wday_name[timeptr->tm_wday],
	     mon_name[timeptr->tm_mon],
	     timeptr->tm_mday,
	     timeptr->tm_hour,
	     timeptr->tm_min,
	     timeptr->tm_sec,
	     timeptr->tm_year + 1900);

    return buffer;
}
