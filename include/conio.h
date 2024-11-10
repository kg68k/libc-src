/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: conio.h,v 1.2 1993/10/06 16:43:30 mura Exp $
 */

#ifndef __conio_h__
#define __conio_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

_EXTERN (char *cgets (char *));
_EXTERN (int_ cprintf (const char * dotdot_));
_EXTERN (int_ cputs (const char *));
_EXTERN (int_ cscanf (const char * dotdot_));
_EXTERN (int_ getch (void_));
_EXTERN (int_ getche (void_));
_EXTERN (int_ kbhit (void_));
_EXTERN (int_ putch (int_));
_EXTERN (int_ ungetch (int_));

#endif
