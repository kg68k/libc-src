/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: realloc.c,v 1.1.1.1 1993/04/18 16:24:43 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/xstdlib.h>

/* Functions */
void *realloc (void *ptr, size_t n)
{
    void *curr_block;
    void *aloc_block;
    void *next_block;
    size_t curr_size;
    size_t next_size;

    /*
    ** ptr がヌルポインタならば malloc と同じ動作をする。
    */
    if (ptr == 0)
	return malloc (n);

    /*
    ** このブロックが使用中のブロックであるかどうか調べる。ただし、チ
    ** ェックは非常にあいまいなものであり、必ずしも判定はできない。
    */
    curr_block = MA_TOPADR (ptr);
    if (MA_ISUSED (curr_block) == 0) {
	errno = EFAULT;
	return 0;
    }

    /*
    ** サイズ n がこのメモリブロックのサイズより小さい場合は位置はそ
    ** のまま。
    */
    curr_size = MA_MASK (MA_FFLAG (curr_block));
    if (curr_size - MA_STRSIZ >= n)
	return ptr;

    /*
    ** すぐ次のメモリブロックを調べる。それが空きブロックであり、かつ
    ** それと合わせることで新しいサイズに適合するならばメモリブロック
    ** を融合する。
    */
    next_block = curr_block + curr_size;
    if (MA_ISFREE (next_block)) {
	next_size = MA_FASTMASK (MA_FFLAG (next_block));
	if (next_size + curr_size - MA_STRSIZ >= n) {
	    _ma_remove (next_block);
	    curr_size += next_size;
	    MA_FFLAG (curr_block) = MA_VALUE (MA_USED, curr_size);
	    MA_BFLAG (curr_block + curr_size) = MA_VALUE (MA_USED, curr_size);
	    return ptr;
	}
    }

    /*
    ** 新しいメモリブロックを確保し、メモリブロックの内容をコピーし、
    ** 最後に古いメモリブロックを解放する。必ずワード境界であり、8バ
    ** イトバンダリなので long word でコピー。
    */
    if (aloc_block = malloc (n)) {
	int *dst = aloc_block;
	int *src = ptr;
	int copysize = (curr_size >> 2) - 2;
	while (copysize--) *dst++ = *src++;
	free (ptr);
    }

    /*
    ** アドレスを返す。
    */
    return aloc_block;
}
