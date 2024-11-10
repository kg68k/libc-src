/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: flushall.c,v 1.1.1.1 1993/04/18 16:22:33 mura Exp $
 */

/* System headers */
#include <stdio.h>

/* Functions */
int flushall (void)
{
    int i;
    int rc = 0;

    /* 全てのストリームをフラッシュする */
    for (i = 0; i < FOPEN_MAX; i++)
	if (_iob[i]._flag && fflush (&_iob[i]) < 0)
	    rc = -1;

    /* 戻る */
    return rc;
}
