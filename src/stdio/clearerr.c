/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: clearerr.c,v 1.2 1993/08/16 13:35:32 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>

/* Functions */
void clearerr (FILE *fp)
{
    /* エラーフラグ, EOF フラグを消す */
    fp->_flag &= ~(_IOERR | _IOEOF);

    /* ストリームをフラッシュする */
    fflush (fp);
}
