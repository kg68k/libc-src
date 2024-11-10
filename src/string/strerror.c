/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strerror.c,v 1.2 1994/07/27 13:50:44 mura Exp $
 */

/* System headers */
#include <string.h>
#include <errno.h>
#include <stdlib.h>

/* Functions */
char *strerror (int error)
{
    /* error の値チェック */
    if (error < 0 || error >= sys_nerr)
	error = -1;

    /* 該当するメッセージを返す */
    return (char *) sys_errlist[error + 1];
}
