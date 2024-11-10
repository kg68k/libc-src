/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: free.c,v 1.3 1994/07/27 13:50:15 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <errno.h>
#include <sys/xstdlib.h>

#ifdef __LIBC_SX__
#include<stdio.h>

/* File scope functions */
static inline int SX_DISPOSE_PTR (char *p)
{
    register int result asm("d0");
    asm volatile("move.l %1,-(sp)\n\t"
		 "dc.w $a02f\n\t"
		 "addq.w #4,sp"
		    : "=r" (result)
		    : "g"(p)
		    : "a0");
    return result;
}
#endif

/* Functions */
void free (void *ptr)
{
    void *curr_block;
    void *next_block;
    size_t curr_size;
    size_t prev_size;

    /*
    ** ptr が NULL ならば何もしない
    */
    if (ptr == 0)
	return;

    /*
    ** このブロックが使用中のブロックであるかどうか調べる。ただし、
    ** チェックは非常にあいまいなものであり、必ずしも判定はできな
    ** い。
    */
    curr_block = MA_TOPADR (ptr);
    curr_size = MA_MASK (MA_FFLAG (curr_block));
    if (MA_ISUSED (curr_block) == 0) {
	errno = EFAULT;
	return;
    }

    /*
    ** 一つ後ろのメモリブロックを調べる。もしも空きブロックならば、
    ** その空きブロックをリストから削除し、このメモリブロックと一
    ** 緒にする。
    */
    next_block = curr_block + curr_size;
    if (MA_ISFREE (next_block)) {
	curr_size += MA_FASTMASK (MA_FFLAG (next_block));
	_ma_remove (next_block);
    }

    /*
    ** 一つ前のメモリブロックを調べる。もしも空きブロックならば、
    ** その空きブロックを拡張してこのメモリブロックと一緒にする。
    ** まとめることで空きブロックリストの操作を無くす。
    */
    if (MA_ISFREE (MA_BACKADR (curr_block))) {
	prev_size = MA_FASTMASK (MA_BFLAG (curr_block));
	MA_BFLAG (curr_block + curr_size) = MA_VALUE (MA_FREE, curr_size + prev_size);
	MA_FFLAG (curr_block - prev_size) = MA_VALUE (MA_FREE, curr_size + prev_size);
#ifdef __LIBC_SX__
	curr_block -= prev_size;
	curr_size += prev_size;
#endif
    }

    /*
    ** メモリブロックを空きブロックとする。
    */
    else {
	MA_BFLAG (curr_block + curr_size) = MA_VALUE (MA_FREE, curr_size);
	MA_FFLAG (curr_block) = MA_VALUE (MA_FREE, curr_size);
	_ma_add (curr_block);
    }

#ifdef __LIBC_SX__
    /*
    ** メモリブロックがヒープ全体ならこれを削除する
    */
    {
	if (MA_RMASK (MA_BFLAG (curr_block)) == MA_EXIT &&
	    MA_RMASK (MA_FFLAG (curr_block + curr_size)) == MA_EXIT) {
	    char **c_heap;
	    char **p_heap;

	    _ma_remove (curr_block);
	    c_heap = (char **) (curr_block - 8);

	    /* ヒープをリストから削除 */
	    p_heap = &_ma_lptr;
	    do {
		if (*p_heap == (char *) c_heap)
		    break;
	    } while ((p_heap = (char **) *p_heap));
	    *p_heap = *c_heap;
	    SX_DISPOSE_PTR ((char *) c_heap);
	}
    }
#endif
}
