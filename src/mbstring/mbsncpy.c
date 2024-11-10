/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsncpy.c,v 1.2 1994/11/27 13:03:38 mura Exp $
 */

/* System headers */
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
unsigned char *mbsncpy (unsigned char *dst, const unsigned char *src, size_t n)
{
    int c;
    unsigned char *save = dst;

    /* 文字列を複写する */
    while ((c = mbsnextc (src)) && n-- > 0) {

	/* コピー先に複写 */
	_mbset (dst, c);

	/* コピー先ポインタを進める */
	dst = mbsinc (dst);

	/* コピー元ポインタを進める */
	src = mbsinc ((unsigned char *) src);

    }

    /* null 文字に達した場合は残りを null 文字で埋める */
    if (c == '\0') {
	while (n-- > 0)
	    *dst++ = '\0';
    }

    /* 元の dst を返す */
    return save;
}
