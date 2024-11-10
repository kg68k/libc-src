/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fseek.c,v 1.1.1.1 1993/04/18 16:22:47 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>

/* Functions */
int fseek (FILE *fp, long offset, int whence)
{
    /* ストリームをフラッシュする */
    if (fflush (fp) < 0)
	return -1;

    /* 実際に seek する */
    if (lseek (fp->_file, offset, whence) < 0)
	return -1;

    /* 終端指示子をクリアする */
    fp->_flag &= ~_IOEOF;

    /* 成功した */
    return 0;
}
