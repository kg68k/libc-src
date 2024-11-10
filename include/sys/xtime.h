/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xtime.h,v 1.2 1993/10/06 16:47:56 mura Exp $
 */

#ifndef __sys_xtime_h__
#define __sys_xtime_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __time_h__
#include <time.h>
#endif

#define _TZADJUST (-9 * 60 * 60)

extern clock_t _inclock;
extern struct tm _gmtm;

_EXTERN (int_ __const _isleap (int_, int_));
_EXTERN (int_ __const _getleaps (int_));
_EXTERN (int_ __const _getmday (int_, int_));
_EXTERN (int_ __const _getyday (int_, int_));

#endif
