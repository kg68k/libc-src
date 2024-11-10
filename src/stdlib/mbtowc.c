/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbtowc.c,v 1.2 1993/08/16 13:36:16 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <mbctype.h>
#include <sys/types.h>

/* Functions */
int mbtowc (wchar_t *charptr, const char *address, size_t number)
{
    int bytes;

    /* ja_JP.SJIS は状態依存ではない */
    if (address == 0)
	return 0;

    /* マルチバイト文字のバイト数を調べる */
    if ((bytes = mblen (address, number)) < 0)
	return bytes;

    /* バイト数に応じて encoding する */
    if (charptr) {
	switch (bytes) {
	case 0:
	    if (number > 0) 
		*charptr = (wchar_t) '\0';
	    break;
	case 1:
	    *charptr = (wchar_t) ((unsigned char) address[0]);
	    break;
	case 2:
	    *charptr = (wchar_t) (((unsigned char) address[0] << 8)
				  | (unsigned char) address[1]);
	    break;
	}
    }

    return bytes;
}
