/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mman.h,v 1.2 1993/10/06 16:46:21 mura Exp $
 */

/*
** PLEASE DO NOT USE THIS HEADER FILE !!!
** ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
** The following features will be supported in the long long
** future,  but not supprted now.   If you want to use these
** features, please make the following interfaces, and contribute
** them to us.
*/

#ifndef __sys_mman_h__
#define __sys_mman_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_types_h__
#include <sys/types.h>
#endif

#define MADV_NORMAL     1
#define MADV_RANDOM     2
#define MADV_SEQUENTIAL 3
#define MADV_WILLNEED   4
#define MADV_DONTNEED   5
#define MADV_SPACEAVAIL 6

#define PROT_NONE       0x00
#define PROT_READ       0x01
#define PROT_WRITE      0x02
#define PROT_EXEC       0x04

#define MAP_FILE        0x01
#define MAP_ANONYMOUS   0x02
#define MAP_VARIABLE    0x04
#define MAP_FIXED       0x08
#define MAP_SHARED      0x10
#define MAP_PRIVATE     0x20

#define MS_SYNC         0
#define MS_ASYNC        1
#define MS_INVALIDATE   2

#define MSEM_LOCKED     0
#define MSEM_UNLOCKED   1
#define MSEM_IF_NOWAIT  2
#define MSEM_IF_WAITERS 3

typedef int_ msemaphore;

_EXTERN (caddr_t mmap (caddr_t, size_t, int_, int_, int_, off_t));
_EXTERN (int_ madvise (caddr_t, size_t, int_));
_EXTERN (int_ mprotect (caddr_t, size_t, int_));
_EXTERN (int_ msem_lock (msemaphore *, int_));
_EXTERN (int_ msem_remove (msemaphore *));
_EXTERN (int_ msem_unlock (msemaphore *, int_));
_EXTERN (int_ msync (caddr_t, size_t, int_));
_EXTERN (int_ munmap (caddr_t, size_t));
_EXTERN (msemaphore *msem_init (msemaphore *, int_));

#endif
