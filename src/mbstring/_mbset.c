/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _mbset.c,v 1.1 1994/11/27 13:02:56 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <mbstring.h>

/* Functions */
unsigned char *_mbset (unsigned char *string, int c)
{
    unsigned char *save = string;

    /* c が 16bit 幅の文字列であればそれを分解する */
    if (_MBIS16 (c)) {

	/* ただし、下位 8bit が null 文字ならば全体を null 文字とみなす */
	if (_MBLMASK (c) == 0) {
	    *string++ = '\0';
	    *string++ = '\0';
	}
	else {
	    *string++ = _MBGETH (c);
	    *string++ = _MBGETL (c);
	}

    }
    else {

	/* 8bit 幅の文字はそのままコピー */
	*string++ = c;

    }

    /* 元の string を返す */
    return save;
}
