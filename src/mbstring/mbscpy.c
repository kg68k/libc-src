/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbscpy.c,v 1.2 1994/11/27 13:03:07 mura Exp $
 */

/* System headers */
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
unsigned char *mbscpy (unsigned char *dst, const unsigned char *src)
{
    int c;
    unsigned char *save = dst;

    /* 文字列を複写する */
    while (c = mbsnextc (src)) {

	/* コピー先に複写 */
	_mbset (dst, c);

	/* コピー先ポインタを進める */
	dst = mbsinc (dst);

	/* コピー元ポインタを進める */
	src = mbsinc ((unsigned char *) src);

    }

    /* 最後の null 文字を打つ */
    *dst = '\0';

    /* 元の dst を返す */
    return save;
}
