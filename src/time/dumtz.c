/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: dumtz.c,v 1.2 1994/07/27 13:52:41 mura Exp $
 */

/* System headers */
#include <time.h>
#include <sys/xtime.h>

/* External variables */
__common char *tzname[2] = { "JST", "" };
__common int daylight;
__common long timezone = -9 * 60 * 60;
__common long timezone_dst = -9 * 60 * 60;
__common long timezone_std = -9 * 60 * 60;

/* Functions */
void tzset (void)
{
}
