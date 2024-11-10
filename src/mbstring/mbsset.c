/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsset.c,v 1.2 1994/11/26 14:54:38 mura Exp $
 */

/* System headers */
#include <string.h>
#include <mbctype.h>
#include <mbstring.h>

/* Functions */
unsigned char *mbsset (unsigned char *string, int c)
{
    size_t len;
    unsigned char ch, cl;
    unsigned char *save = string;

    /* 文字列のバイト数を得る */
    len = strlen (string);

    /* c が 16bit 幅の文字列であればそれを分解する */
    if (_MBIS16 (c)) {

	/* ただし、下位 8bit が null 文字ならば null 文字とみなす */
	if (_MBLMASK (c) == 0) {
	    ch = '\0';
	    cl = '\0';
	}
	else {
	    ch = _MBGETH (c);
	    cl = _MBGETL (c);
	}

	/* 文字列全体を埋める */
	while (len > 1) {
	    *string++ = ch;
	    *string++ = cl;
	    len -= 2;
	}

	/* 最後の1バイトの余りはスペースで埋める */
	if (len > 0)
	    *string++ = ' ';

    }
    else {

	/* 文字列全体を埋める */
	while (len-- > 0)
	    *string++ = c;

    }

    /* 元の string を返す */
    return save;
}
