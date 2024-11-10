/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strxfrm.c,v 1.1.1.1 1993/04/18 16:26:01 mura Exp $
 */

/* System headers */
#include <string.h>
#include <stddef.h>

/* Functions */
size_t strxfrm (char *dst, const char *src, size_t len)
{
    int ch;
    char *top;

    /* len が 0 の時の処理 */
    if (len == 0)
	return strlen (src);

    /*
    ** 本来なら、LC_COLLATE によってコードセットを変更するのだが
    ** 本関数はその機能を実装していない。LC_COLLATE はいつでも "C"
    ** を想定する
    */
    for (top = dst; len-- && (ch = *src++) ; *dst++ = ch);

    /* 変換したバイト数を返す */
    return dst - top;
}
