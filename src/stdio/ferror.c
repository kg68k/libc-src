/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ferror.c,v 1.1.1.1 1993/04/18 16:22:23 mura Exp $
 */

/* System headers */
#include <stdio.h>

/* Functions */
int ferror (FILE *fp)
{
    /* エラーフラグを調べる */
    return (fp->_flag & _IOERR);
}
