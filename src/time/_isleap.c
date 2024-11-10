/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _isleap.c,v 1.1.1.1 1993/04/18 16:38:18 mura Exp $
 */

/* System headers */
#include <time.h>
#include <sys/xtime.h>

/* Functions */
int _isleap (int months, int year)
{
    return (months == 2 &&
	    ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0)));
}
