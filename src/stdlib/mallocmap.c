/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from oo.
 * --------------------------------------------------------------------
 * $Id: mallocmap.c,v 1.1 1994/11/26 14:58:46 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/xstdlib.h>
#include <sys/xstart.h>

/* Functions */
void fmallocmap (FILE *fp)
{
    int size;
    int real_used;
    int total_used;
    int total_free;
    char *alloc;

    /* 初期化 */
    real_used = total_used = total_free = 0;

    /* ヒープ領域をたどる */
    for (alloc = _hsta + 4; !MA_ISEXIT (alloc); alloc += size) {

	/* ブロックサイズを求める */
	size = MA_MASK (MA_FFLAG (alloc));

	/* ブロックサイズを加算 */
	if (MA_ISUSED (alloc)) {
	    real_used += size - 8;
	    total_used += size;
	}
	else
	    total_free += size;

	/* ブロックの状況を表示 */
	fprintf (fp, "- %#08X:%08d %s (%#08X:%08d)\n",
		 alloc, size,
		 MA_ISUSED (alloc) ? "USED" : "FREE",
		 MA_MPTR (alloc), size - 8);

    }

    /* トータル情報を表示 */
    fprintf (fp, "+ %08d USED\n", total_used);
    fprintf (fp, "+ %08d REAL\n", real_used);
    fprintf (fp, "+ %08d FREE\n", total_free);
}

/* Functions */
void mallocmap (void)
{
    /* 標準出力に出す */
    fmallocmap (stdout);
}
