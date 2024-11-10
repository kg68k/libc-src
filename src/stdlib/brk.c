/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: brk.c,v 1.4 1994/07/27 13:50:09 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <sys/resource.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xstart.h>
#include <sys/xresource.h>

/* Macros */
#define PAGEMASK (PAGE_SIZE - 1) /* must be 2^n - 1 */

/* Functions */
int brk (void *addr)
{
    int rc;
    void *ptr, *maxpos;

    /* バンダリ調整 */
    ptr = (void *) (((int) addr + PAGEMASK) & ~PAGEMASK);
    maxpos = _hsta + _limits[RLIMIT_DATA].rlim_cur;

    /* _hsta を下回るか、rlimit を越えるとエラー */
    if (ptr < _hsta || ptr >= maxpos) {
	errno = ENOMEM;
	return -1;
    }

    /* 新しい境界で SETBLOCK する */
    if (ptr != _memcp->block_end
	&& (rc = _dos_setblock (_procp, (int) ptr - (int) _procp)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    /* ブレーク値を変更する */
    _last = ptr;

    /* 成功 */
    return 0;
}
