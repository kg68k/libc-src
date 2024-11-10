/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from AOI (MAKI aoi).
 * --------------------------------------------------------------------
 * $Id: audio.h,v 1.1.1.1 1993/05/24 15:00:00 
 */

#ifndef __audio_h__
#define __audio_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

_EXTERN (int_ a_stat (void));
_EXTERN (void a_cont (void));
_EXTERN (void a_end (void));
_EXTERN (void a_play (const void *, int_, int_, int_, int_));
_EXTERN (void a_rec (void *, int_, int_, int_));
_EXTERN (void a_stop (void));

#endif
