/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from Mariko.
 * --------------------------------------------------------------------
 * $Id: interrupt.h,v 1.2 1993/10/06 16:44:06 mura Exp $
 */

#ifndef __interrupt_h__
#define __interrupt_h__

#if !defined (__MARIKO_CC__)
#error You lose. This file can be compiled only by GNU-C(Mariko) compiler.
#endif

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define IJUMP(addr) __builtin_saveregs (addr)
#define IJUMP_RTE() __builtin_saveregs (__builtin_saveregs)
#define IRTE() __builtin_saveregs ()
#define IRTS() __builtin_saveregs (0)
#define PRAMREG(var, reg) register int_ var asm ("extern " #reg)
#define RETREG(var, reg) register int_ var asm("extern " #reg)
#define SET_FRAME(reg) register void *__frame asm("frame " #reg)

_EXTERN (int_ intlevel (int_));

#endif
