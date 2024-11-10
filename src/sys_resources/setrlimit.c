/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setrlimit.c,v 1.1.1.1 1993/04/18 16:36:53 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <sys/resource.h>
#include <sys/xresource.h>

/* Functions */
int setrlimit (int restype, struct rlimit *rlp)
{
    /* rlim_cur は rlim_max を上回ってはいけない */
    if (rlp->rlim_cur > rlp->rlim_max) {
	errno = EINVAL;
	return -1;
    }

    /* restype によって処理を変える */
    switch (restype) {
    case RLIMIT_CPU:
    case RLIMIT_FSIZE:
    case RLIMIT_STACK:
    case RLIMIT_RSS:
	errno = EPERM;
	return -1;
    case RLIMIT_DATA:
    case RLIMIT_CORE:
	_limits[restype].rlim_cur = rlp->rlim_cur;
	return 0;
    default:
	errno = EINVAL;
	return -1;
    }
}
