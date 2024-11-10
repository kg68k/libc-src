/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sbrk.c,v 1.2 1993/05/15 15:38:49 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <sys/xstart.h>

/* Functions */
void *sbrk (int incre)
{
    void *ret = _last;

    /* size が 0 以外ならブレーク値を変更 */
    if (incre != 0) {
	if (brk (_last + incre) < 0)
	    return (void *) -1;
    }

    /* 古いブレーク値を返す */
    return ret;
}
