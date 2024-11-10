/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbbtype.c,v 1.1.1.1 1993/04/18 16:19:28 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <mbstring.h>

/* Functions */
int mbbtype (unsigned char ch, int type)
{
    /* type が 1 なら... */
    if (type == 1) {

	/* SJIS 2 バイト目チェック */
	if ((ch >= 0x40 && ch <= 0x7e) || (ch >= 0x80 && ch <= 0xfc))
	    return _MBC_TRAIL;
	else
	    return _MBC_ILLEGAL;

    }

    /* type が 1 以外ならば... */
    else {

	/* SJIS チェック */
	if ((ch >= 0x81 && ch <= 0x9f) || (ch >= 0xe0 && ch <= 0xfc))
	    return _MBC_LEAD;
	else if (ch <= 0x1f || ch >= 0xfd)
	    return _MBC_ILLEGAL;
	else
	    return _MBC_SINGLE;

    }
}
