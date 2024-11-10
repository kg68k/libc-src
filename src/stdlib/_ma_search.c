/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _ma_search.c,v 1.1.1.1 1993/04/18 16:23:48 mura Exp $
 */

/* System headers */
#include <sys/xstdlib.h>

/* Functions */
char *_ma_search (size_t size)
{
    int count;
    char *list, *prev, *next;

    /*
    ** 空きブロックリストを得る。
    */
    if ((list = _ma_flist) == 0)
	return 0;

    /*
    ** 最初の空きブロックについて試験する。ブロックのサイズが size
    ** 以上ならばそれを使うことにする。
    */
    if (MA_FASTMASK (MA_FFLAG (list)) >= size)
	return list;

    /*
    ** 最初のブロックでだめなようならそこから前後双方向にリストを辿
    ** り、適切なブロックを探索する。まず、その探索回数を算出する。
    */
    if ((count = (_ma_fnum >> 1)) == 0)
	return 0;

    /*
    ** 探索回数 count 分だけループし、前後に空きブロックリストを探
    ** 索する。
    */
    prev = MA_PREV (list);
    next = MA_NEXT (list);
    while (count--) {
	if (MA_FASTMASK (MA_FFLAG (next)) >= size)
	    return next;
	if (MA_FASTMASK (MA_FFLAG (prev)) >= size)
	    return prev;
	next = MA_NEXT (next);
	prev = MA_PREV (prev);
    }

    /*
    ** 結局見付からなかった。
    */
    return 0;
}
