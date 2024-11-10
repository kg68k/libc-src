/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _fpuoff.c,v 1.1.1.1 1993/04/18 16:17:48 mura Exp $
 */

/* System headers */
#include <interrupt.h>
#include <sys/xmath.h>
#undef _fpu_off

/* Functions */
void _fpu_off (void)
{
    _havefpu = _ohavefpu & ~(_FLG_FPU | _FLG_IOFPU);
}
