/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _ma_recycle.c,v 1.1.1.1 1993/04/18 16:23:45 mura Exp $
 */

/* System headers */
#include <sys/xstdlib.h>

/* Functions */
char *_ma_recycle (char *block, size_t *size)
{
    int need;				/* 必要バイト数 */
    int current_size;			/* 現在のブロックサイズ */

    /*
    ** 必要サイズと今の空きブロックサイズを得る。
    */
    need = *size;
    current_size = MA_FASTMASK (MA_FFLAG (block));

    /*
    ** 空きブロックを分割できないようならブロックを空きブロックリ
    ** ストから削除してそのサイズのままで利用する。つまり、分割後
    ** の空きブロック大きさが MIN_BLOCKSIZ バイトを下回るようなら
    ** ば分割しない。
    */
    if (current_size - need < MIN_BLOCKSIZ) {
	_ma_remove (block);
	*size = current_size;
	return block;
    }

    /*
    ** 空きブロックのサイズを変更する。位置は変更しないのでリスト
    ** への変更はない。次にその後ろの透き間を新しいメモリブロック
    ** として活用する。
    */
    current_size  -= need;
    MA_FFLAG (block) = MA_VALUE (MA_FREE, current_size);
    block += current_size;
    MA_BFLAG (block) = MA_VALUE (MA_FREE, current_size);

    /*
    ** アドレスを返す。
    */
    return block;
}
