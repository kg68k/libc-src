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
#include <search.h>

/* Functions */
void *lfind (const void *key, const void *base,
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

    /* 見つからなかった */
    return 0;
}
