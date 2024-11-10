/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: bsearch.c,v 1.2 1994/05/02 16:52:08 mura Exp $
 */

/* System headers */
#include <stdlib.h>

/* Functions */
void *bsearch (const void *item, const void *array, size_t number,
	       size_t size, int (*comparison) (const void *, const void *))
{
    int rc;
    int left, mid, right;
    const void *ptr;

    /* 左右の比較領域マーカーを初期化する */
    left = 0;
    right = number - 1;

    /* 領域マーカが重なるまで検索する */
    while (left <= right) {

	/* 比較の中間点を算出する */
	mid = (left + right) >> 1;

	/* 比較対象データを fetch する */
	ptr = (const void *) ((const char *) array + size * mid);

	/* item と比較する */
	rc = (*comparison) (ptr, item);

	/* 比較結果に応じて左右のマーカを移動する */
	if (rc < 0)
	    left = mid + 1;
	else if (rc > 0)
	    right = mid - 1;
	else
	    return (void *) ptr;
    }

    /* 見つからない */
    return 0;
}
