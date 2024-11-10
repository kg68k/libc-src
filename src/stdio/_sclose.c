/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sclose.c,v 1.1.1.1 1993/04/18 16:22:07 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <sys/xstdio.h>

/* Functions */
int _sclose (FILE *fp)
{
    /* malloc されたバッファ領域を解放 */
    if (fp->_base && (fp->_flag & _IOFREE))
	free (fp->_base);

    /* 構造体を未使用状態にリセット */
    fp->_bufsiz = 0;
    fp->_base = 0;
    fp->_ptr = 0;
    fp->_cnt = 0;
    fp->_flag = 0;
    fp->_file = -1;
    fp->_nback = 0;

    /* 戻る */
    return 0;
}
