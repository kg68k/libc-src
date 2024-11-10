/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: types.h,v 1.5 1994/05/02 16:10:08 mura Exp $
 */

#ifndef __sys_types_h__
#define __sys_types_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __clock_t_defined__
#define __clock_t_defined__
typedef long clock_t;
#endif

#ifndef __dosmode_t_defined__
#define __dosmode_t_defined__
typedef int_ dosmode_t;
#endif

#ifndef __devmode_t_defined__
#define __devmode_t_defined__
typedef int_ devmode_t;
#endif

#ifndef __size_t_defined__
#define __size_t_defined__
typedef unsigned long size_t;
#endif

#ifndef __wchar_t_defined__
#define __wchar_t_defined__
typedef int_ wchar_t;
#endif

#ifndef __time_t_defined__
#define __time_t_defined__
typedef int_ time_t;
#endif

typedef char *caddr_t;
typedef char *daddr_t;
typedef int_ dev_t;
typedef int_ gid_t;
typedef int_ nlink_t;
typedef int_ pid_t;
typedef int_ uid_t;
typedef long ino_t;
typedef long off_t;
typedef unsigned int_ mode_t;

typedef unsigned char u_char;
typedef unsigned char unchar;
typedef unsigned int_ u_int;
typedef unsigned long u_long;
typedef unsigned short u_short;

typedef unsigned int_ uint;
typedef unsigned long ulong;
typedef unsigned short ushort;

typedef long fd_mask;

#define FD_SETSIZE (128)
#define NBBY       (8)
#define NFDBITS    (sizeof (fd_mask) * NBBY)

typedef struct {
    fd_mask fds_bits[(FD_SETSIZE + NFDBITS - 1) / NFDBITS];
} fd_set;

#define FD_CLR(f,p)   ((p)->fds_bits[(f) / NFDBITS] &= ~(1 << ((f) % NFDBITS)))
#define FD_SET(f,p)   ((p)->fds_bits[(f) / NFDBITS] |=  (1 << ((f) % NFDBITS)))
#define FD_ISSET(f,p) ((p)->fds_bits[(f) / NFDBITS] &   (1 << ((f) & NFDBITS)))
#define FD_ZERO(p)    (bzero ((char *) (p), sizeof (*(p))))

#endif
