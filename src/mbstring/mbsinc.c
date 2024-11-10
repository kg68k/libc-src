/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsinc.c,v 1.1.1.1 1993/04/18 16:19:41 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <mbstring.h>
#include <sys/xmbstring.h>

/* Functions */
unsigned char *mbsinc (unsigned char *string)
{
    int bytes;

    /*
    ** 厳密に 1 マルチバイト進む。不正な漢字コードに対しては null とみな
    ** して進まない
    */
    if ((bytes = _mblen (string)) <= 0)
	return string;

    /* 次の 1 マルチバイトのバイト数だけ進む */
    return string + bytes;
}
