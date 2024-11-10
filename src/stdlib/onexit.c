/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: onexit.c,v 1.1.1.1 1993/04/18 16:24:33 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <sys/xstart.h>

/* Functions */
onexit_t onexit (onexit_t funcptr)
{
    /* すでに最大登録数を越えているか */
    if (_onexnums >= ONEXIT_MAX) {
	errno = EINVAL;
	return 0;
    }

    /* 関数をリストに登録する */
    _onexprcs[_onexnums++] = (void (*) (void)) funcptr;

    return funcptr;
}
