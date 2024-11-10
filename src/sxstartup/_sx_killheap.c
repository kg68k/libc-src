/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sx_killheap.c,v 1.3 1994/07/27 13:51:26 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <sxlib.h>
#include <sys/xstart.h>
#include <sys/xstdlib.h>

/* Functions */
void _sx_killheap (void)
{
    char *cur, *prev;

    /* ブロックの最終位置からはじめる */
    cur = _ma_lptr;

    /* 全てのブロックに適用 */
    while (cur) {
	prev = *((char **) cur);
	MMPtrDispose (cur);
	cur = prev;
    }
}
