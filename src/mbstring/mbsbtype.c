/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsbtype.c,v 1.2 1993/06/07 15:28:34 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <mbstring.h>

/* File scope functions */
static int is1byte (const unsigned char *str, size_t nbyte)
{
    int index;

    /* 1 バイト目と思われる位置を遡って探す */
    for (index = nbyte; index >= 0 && ismbblead (str[index]); index--);

    /* 1 バイト目か? */
    return ((nbyte - index) & 1) && ismbblead (str[nbyte]);
}

/* Functions */
int mbsbtype (const unsigned char *str, size_t nbyte)
{
    /* 1 バイト目か? */
    if (is1byte (str, nbyte))
	return _MBC_LEAD;

    /* 2 バイト目か? */
    if (nbyte > 0 && is1byte (str, nbyte - 1))
	return _MBC_TRAIL;

    /* ILLEGAL チェック */
    if (str[nbyte] <= 0x1f || str[nbyte] >= 0xfd)
	return _MBC_ILLEGAL;

    /* ANK である */
    return _MBC_SINGLE;
}
