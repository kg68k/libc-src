/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: locking.h,v 1.2 1993/10/06 16:46:17 mura Exp $
 */

#ifndef __sys_locking_h__
#define __sys_locking_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define LK_LOCK   0
#define LK_NBLCK  1
#define LK_NBRLCK 2
#define LK_RLCK   3
#define LK_UNLCK  4

_EXTERN (int_ locking (int_, int_, long));

#endif
