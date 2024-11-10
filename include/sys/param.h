/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: param.h,v 1.1.1.1 1993/04/18 16:14:41 mura Exp $
 */

#ifndef __sys_param_h__
#define __sys_param_h__

#ifndef __limits_h__
#include <limits.h>
#endif

#define MAXPATHLEN      PATH_MAX
#define MAXSYMLINKS     LINK_MAX
#define MAXHOSTNAMELEN  64
#define HZ              60

#define MAXPID   ((pit_t) 30000)
#define MAXUID   ((gid_t) 65534)
#define NODEV    ((dev_t) -1)
#define NOGROUP  ((gid_t) 65535)

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

#endif
