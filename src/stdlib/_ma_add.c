/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _ma_add.c,v 1.1.1.1 1993/04/18 16:23:42 mura Exp $
 */

/* System headers */
#include <sys/xstdlib.h>

/* Functions */
void _ma_add (char *block)
{
    char *list;				/* 空きブロックリストの先頭 */
    char *last;				/* 空きブロックリストの最後 */

    /*
    ** もし、リストが空ならば指定されたブロックを先頭のブロックとし
    ** て登録する。空でなければ新たなブロックを最後尾に登録し、前後
    ** 方向にリンクを張り直す。
    */
    if ((list = _ma_flist) == 0) {
	_ma_flist = block;
	MA_PREV (block) = block;
	MA_NEXT (block) = block;
    }
    else {
	last = MA_PREV (list);
	MA_NEXT (last) = block;
	MA_PREV (block) = last;
	MA_NEXT (block) = list;
	MA_PREV (list) = block;
    }

    /*
    ** 空きブロック数加算
    */
    _ma_fnum++;
}
