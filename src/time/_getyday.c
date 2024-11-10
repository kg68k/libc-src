/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _getyday.c,v 1.1.1.1 1993/04/18 16:38:17 mura Exp $
 */

/* System headers */
#include <time.h>
#include <sys/xtime.h>

/* File scope variables */
static int ydays[] = {					/* 前月までの日数の累計 */
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};

/* Functions */
int _getyday (int month, int year)
{
    return ydays[month]
	+ ((month >= 1 && ((year % 400) == 0
			   || ((year % 4) == 0 && (year % 100) != 0))) ? 1 : 0);
}
