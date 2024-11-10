/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fcntl.h,v 1.4 1993/10/06 16:43:54 mura Exp $
 */

#ifndef __fcntl_h__
#define __fcntl_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_types_h__
#include <sys/types.h>
#endif

#define O_RDONLY   0x000
#define O_WRONLY   0x001
#define O_RDWR     0x002

#define O_CREAT    0x004
#define O_EXCL     0x008
#define O_TRUNC    0x010
#define O_TEXT     0x020
#define O_BINARY   0x040
#define O_APPEND   0x080
#define O_TXTEOF   0x100

#define O_SYNC     0x000 /* for compatibility */
#define O_NOCTTY   0x000 /* for compatibility */
#define O_NONBLOCK 0x000 /* for compatibility */
#define O_NDELAY   0x000 /* for compatibility */

#define O_ACCMODE  (O_RDONLY | O_WRONLY | O_RDWR)
#define O_STSMODE  (O_APPEND | O_NONBLOCK | O_SYNC | O_TEXT | O_BINARY)

#define FAPPEND O_APPEND /* for compatibility */
#define FCREAT  O_CREAT  /* for compatibility */
#define FEXCL   O_EXCL   /* for compatibility */
#define FNDELAY O_NDELAY /* for compatibility */
#define FSYNC   O_SYNC   /* for compatibility */
#define FTRUNC  O_TRUNC  /* for compatibility */

#define F_DUPFD  0
#define F_GETFD  1
#define F_SETFD  2
#define F_GETFL  3
#define F_SETFL  4
#define F_GETLK  5
#define F_SETLK  6
#define F_SETLKW 7

#define F_RDLCK  1
#define F_WRLCK  2
#define F_UNLCK  3

struct flock {
    short l_type;
    short l_whence;
    off_t l_start;
    off_t l_len;
    pid_t l_pid;
};

_EXTERN (int_ creat (const char *, mode_t));
_EXTERN (int_ fcntl (int_, int_ dotdot_));
_EXTERN (int_ open (const char *, int_ dotdot_));

#endif
