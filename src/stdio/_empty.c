/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _empty.c,v 1.1.1.1 1993/04/18 16:22:06 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <sys/xstdio.h>

/* Functions */
FILE *_getemptyiob (void)
{
    int i;

    /* 使われていない _iob を探す */
    for (i = 0; i < FOPEN_MAX; i++) {
	if (_iob[i]._flag == 0)
	    return &_iob[i];
    }

    /* 見つからない */
    return 0;
}
