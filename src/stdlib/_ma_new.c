/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _ma_new.c,v 1.3 1994/07/27 13:49:53 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <limits.h>
#include <sys/xstart.h>
#include <sys/xstdlib.h>

#ifdef __LIBSXC__

/* External variables */
int _ma_fnum;
char *_ma_flist;
char *_ma_lptr = 0;
extern size_t _SX_GETMEM_SIZE;

#else

/* External variables */
int _ma_fnum;
char *_ma_flist;
char *_ma_lptr;

#endif

/* Functions */
#ifdef __LIBSXC__
static __inline void *_SX_GET_PTR (size_t size)
{
    register void *reg_d0 asm ("d0");

    /* インラインアセンブラ展開 */
    asm volatile ("move.l %1,-(sp)\n\t"
		  "dc.w $a01e\n\t"
		  "addq.w #4,sp"
		  : "=r" (reg_d0)
		  : "g" (size)
		  : "a0");

    /* 結果を返す */
    return reg_d0;
}
#endif

/* Functions */
char *_ma_new (size_t size)
{
#ifdef __LIBSXC__

    char *alloc;
    size_t newsize = _SX_GETMEM_SIZE;

    /* 要求サイズが既定値より大きかったら要求サイズを確保 */
    if (size > _SX_GETMEM_SIZE)
	newsize = size;

    /* 新しいヒープブロックを確保 */
    if ((alloc = _SX_GET_PTR (newsize + 12)) == 0)
	return 0;

    /* ひとつ前のヒープブロックを覚えておく */
    *(long *) alloc = (long) _ma_lptr;
    _ma_lptr = alloc;

    /* 終端識別子を書き込む */
    alloc += 8;
    MA_BFLAG (alloc) = MA_VALUE (MA_EXIT, 0);
    MA_FFLAG (alloc + newsize) = MA_VALUE (MA_EXIT, 0xffffff);

    /* 全体を空きブロックリストに登録 */
    MA_FFLAG (alloc) = MA_VALUE (MA_FREE, newsize);
    MA_BFLAG (alloc + newsize) = MA_VALUE (MA_FREE, newsize);
    _ma_add (alloc);

    /* その後リサイクル */
    alloc = _ma_recycle (alloc, &size);

#else

    long more;				/* より必要なヒープの量 */
    char *alloc;			/* 新しい割り当てアドレス */

    /*
    ** メモリブロック列の最後のアドレスを得る。ブロック列の最後が
    ** 登録されていないようなら、_hsta + 4 を値として登録する。ま
    ** た、_hsta から先頭識別子 4 バイトを書き込む。
    */
    if ((alloc = _ma_lptr) == 0) {
	alloc = _hsta + 4;
	MA_BFLAG (alloc) = MA_VALUE (MA_EXIT, 0);
    }

    /*
    ** ブロック列の最後のアドレスから size バイト分をヒープ領域内
    ** に確保するとした場合に足りない分のバイト数を計算する。
    */
    more = alloc + size + 4 - (char *) _last;

    /*
    ** もし足りない量が正ならば領域を拡大する。その際、ブレーク値
    ** はページサイズ(4K)バンダリで拡張される。ただし最後の終端情
    ** 報の 4 バイト分を含む。拡張に失敗した場合はエラーリターン。
    */
    if (more > 0) {
	if ((int) sbrk (more) < 0)
	    return 0;
    }

    /*
    ** 新たに算出したメモリブロックをメモリブロック終端とし、その
    ** すぐ後ろに終端識別子を埋め込む。
    */
    _ma_lptr = alloc + size;
    MA_FFLAG (_ma_lptr) = MA_VALUE (MA_EXIT, 0xffffff);

#endif

    /*
    ** アドレスを返す。
    */
    return alloc;
}
