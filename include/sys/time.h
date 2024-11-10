/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: time.h,v 1.2 1993/10/06 16:46:42 mura Exp $
 */

#ifndef __sys_time_h__
#define __sys_time_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define ITIMER_REAL 0

struct timeval {
  long tv_sec;
  long tv_usec;
};

struct itimerval {
  struct timeval it_interval;
  struct timeval it_value;
};

#define timerisset(p) ((p)->tv_sec || (p)->tv_usec)
#define timerclear(p) ((p)->tv_sec = (p)->tv_usec = 0)
#define timercmp(a, b, op) \
    ((a)->tv_sec op (b)->tv_sec || \
     ((a)->tv_sec == (b)->tv_sec && (a)->tv_usec op (b)->tv_usec))

_EXTERN (int_ getitimer (int_, struct itimerval *));
_EXTERN (int_ setitimer (int_, struct itimerval *, struct itimerval *));

#endif
