/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: atexit.c,v 1.1.1.1 1993/04/18 16:23:57 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <sys/xstart.h>

/* Functions */
int atexit (void (*funcptr) (void))
{
    /* すでに最大登録数を越えているか */
    if (_exitnums >= ATEXIT_MAX) {
	errno = EINVAL;
	return -1;
    }

    /* 関数をリストに登録する */
    _exitprcs[_exitnums++] = funcptr;

    return 0;
}
