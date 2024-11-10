/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: wcstombs.c,v 1.1.1.1 1993/04/18 16:24:58 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <mbctype.h>
#include <sys/types.h>

/* Functions */
size_t wcstombs (char *string, const wchar_t *widechar, size_t count)
{
    int n, bytes;
    int cnt = 0;

    /* count 文字を処理するまでループ */
    for (n = 0; n < count; n++) {

	/* 不正な文字にであったら... */
	if ((bytes = wctomb (string, *widechar)) < 0)
	    return -1;

	/* null 文字に達したら終り */
	if (*string == 0)
	    return cnt;

	/* カウンタ、ポインタを進める */
	widechar++;
	string += bytes;
	cnt += bytes;
    }

    return cnt;
}
