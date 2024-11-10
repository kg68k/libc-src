/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: time.h,v 1.4 1994/07/27 13:43:45 mura Exp $
 */

#ifndef __time_h__
#define __time_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __size_t_defined__
#define __size_t_defined__
typedef unsigned int_ size_t;
#endif

#ifndef __clock_t_defined__
#define __clock_t_defined__
typedef long clock_t;
#endif

#ifndef __time_t_defined__
#define __time_t_defined__
typedef int_ time_t;
#endif

#ifndef NULL
#define NULL ((void *) 0)
#endif

#define CLOCKS_PER_SEC 100
#define CLK_TCK CLOCKS_PER_SEC

struct tm {
    int_ tm_sec;	/* 0 ... 61 */
    int_ tm_min;	/* 0 ... 59 */
    int_ tm_hour;	/* 0 ... 23 */
    int_ tm_mday;	/* 1 ... 32 */
    int_ tm_mon;	/* 0 ... 11 */
    int_ tm_year;	/* 1900 + x */
    int_ tm_wday;	/* 0 ... 7 */
    int_ tm_yday;	/* 0 ... 365 */
    int_ tm_isdst;	/* 0 or 1 */
    int_ tm_gmtoff;	/* offset from GMT */
    char *tm_zone;	/* timezone name */
};

extern __common char *tzname[];
extern __common int_ daylight;
extern __common long timezone;
extern __common long timezone_dst;
extern __common long timezone_std;

_EXTERN (char *asctime (const struct tm *));
_EXTERN (char *ctime (const time_t *));
_EXTERN (clock_t clock (void_));
_EXTERN (double __const difftime (time_t, time_t));
_EXTERN (size_t strftime (char *, size_t, const char *, const struct tm *));
_EXTERN (struct tm *gmtime (const time_t *));
_EXTERN (struct tm *localtime (const time_t *));
_EXTERN (time_t mktime (struct tm *));
_EXTERN (time_t time (time_t *));
_EXTERN (void tzset (void_));

#endif
