/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _ma_remove.c,v 1.1.1.1 1993/04/18 16:23:47 mura Exp $
 */

/* System headers */
#include <sys/xstdlib.h>

/* Functions */
void _ma_remove (char *block)
{
    char *next;				/* 前の空きブロック */
    char *prev;				/* 次の空きブロック */

    /*
    ** 次の空きブロックを求める。
    */
    next = MA_NEXT (block);

    /*
    ** 空きブロックリストに登録されていた最後のブロックだった場合
    ** は空きブロックリストを空にする。さもなくばブロックの登録を
    ** 消し、前後にリンクを張り直す。先頭空きブロックだった場合は、
    ** _ma_flist の値を置き換える。
    */
    if (next == block) {
	_ma_flist = 0;
    }
    else {
	if (block == _ma_flist) {
	    _ma_flist = next;
	}
	prev = MA_PREV (block);
	MA_NEXT (prev) = next;
	MA_PREV (next) = prev;
    }

    /*
    ** 空きブロック数を減らす。
    */
    _ma_fnum--;
}
