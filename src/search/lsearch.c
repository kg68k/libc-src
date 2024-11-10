/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setlocale.c,v 1.1.1.1 1993/04/18 16:17:42 mura Exp $
 */

/* System headers */
#include <string.h>
#include <search.h>

/* Functions */
void *lsearch (const void *key, const void *base,
	       size_t *nelp, size_t width,
	       int (*compar) (const void *, const void *))
{
    int n;
    void *ptr;

    /* 検索開始位置 */
    ptr = (void *) base;

    /* 現在の要素数を得る */
    n = *nelp;

    /* 全ての要素をリニアにチェック */
    while (n-- > 0) {

	/* 要素比較 */
	if ((*compar) ((const void *) ptr, key) == 0)
	    return ptr;

	/* 次の要素へ */
	ptr = (void *) ((unsigned long) ptr + width);

    }

    /* 最後に要素を追加 */
    memcpy (ptr, key, width);

    /* 要素数を加算 */
    (*nelp)++;

    /* 追加要素を返す */
    return ptr;
}
