/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: timers.h,v 1.3 1993/11/13 06:32:28 mura Exp $
 */

#ifndef __sys_timers_h__
#define __sys_timers_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define DELIVERY_SIGNALS 1

#define TIMEOFDAY 1
#define UPTIME    2

struct timespec {
    unsigned long tv_sec;
    long tv_nsec;
};

struct itimespec {
    struct timespec it_interval;
    struct timespec it_value;
};

typedef int_ timer_t;

_EXTERN (int_ getclock (int_, struct timespec *));
_EXTERN (int_ gettimer (timer_t, struct itimespec *));
_EXTERN (int_ reltimer (timer_t, struct itimespec *, struct itimespec *));
_EXTERN (int_ rmtimer (timer_t));
_EXTERN (int_ setclock (int_, struct timespec *));
_EXTERN (timer_t mktimer (int_, int_, void *));

#endif
