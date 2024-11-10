/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: chkml.c,v 1.1.1.1 1993/04/18 16:24:06 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <sys/dos.h>

/* Functions */
size_t chkml (void)
{
    unsigned long bsize;

    /* 不可能なサイズの malloc を行って調べる */
    bsize = (unsigned long) _dos_malloc (0xffffff);

    /* 完全に確保不可能なら ... */
    if (bsize > 0x82000000UL)
	return 0;

    /* 何バイトまで確保できるか調べて返す */
    return (size_t) (bsize & 0x00ffffff);
}
