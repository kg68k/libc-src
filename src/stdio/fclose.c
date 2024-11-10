/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fclose.c,v 1.1.1.1 1993/04/18 16:22:17 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* Functions */
int fclose (FILE *fp)
{
    /* バッファをフラッシュする */
    if (fp->_flag != 0)
	fflush (fp);

    /* ファイルをクローズする */
    if (fp->_file >= 0)
	close (fp->_file);

    /* FILE 構造体を解放する */
    return _sclose (fp);
}
