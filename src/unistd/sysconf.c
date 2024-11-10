/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sysconf.c,v 1.1.1.1 1993/04/18 16:40:40 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include <sys/xunistd.h>

/* Functions */
long sysconf (int name)
{
    /* name を解析する */
    switch (name) {

    case _SC_ARG_MAX:
	return ARG_MAX;
    case _SC_CHILD_MAX:
	return CHILD_MAX;
    case _SC_CLK_TCK:
	return CLOCKS_PER_SEC;
    case _SC_NGROUPS_MAX:
	return NGROUPS_MAX;
    case _SC_OPEN_MAX:
	return OPEN_MAX;
    case _SC_JOB_CONTROL:
	return _POSIX_JOB_CONTROL;
    case _SC_SAVED_IDS:
	return _POSIX_SAVED_IDS;
    case _SC_VERSION:
	return _POSIX_VERSION;
    case _SC_PASS_MAX:
	return PASS_MAX;
    case _SC_XOPEN_VERSION:
	return _XOPEN_VERSION;
    case _SC_ATEXIT_MAX:
	return ATEXIT_MAX;
    case _SC_PAGE_SIZE:
	return PAGE_SIZE;
    case _SC_AES_OS_VERSION:
	return _AES_OS_VERSION;
    case _SC_PROJ_VERSION:
	return _PROJ_VERSION;

    }

    /* それ以外はエラー */
    errno = EINVAL;
    return -1;
}
