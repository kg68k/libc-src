/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: calloc.c,v 1.2 1994/05/02 16:52:24 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* Functions */
void *calloc (size_t count, size_t size)
{
    size_t total;
    void *ptr;

    /* サイズチェック */
    if ((signed) (total = count * size) < 0) {
	errno = EINVAL;
	return 0;
    }

    /* メモリ確保 */
    if ((ptr = malloc (total)) == 0)
	return 0;

    /* メモリ領域をクリアする */
    memset (ptr, '\0', total);

    /* ポインタを返す */
    return ptr;
}
