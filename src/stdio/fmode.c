/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fmode.c,v 1.1.1.1 1993/04/18 16:22:34 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* Functions */
void fmode (FILE *fp, int mode)
{
    /* 値チェック */
    if (mode != _IOBINARY && mode != _IOTEXT)
	return;

    /* ストリームにフラグを設定 */
    fp->_flag &= ~(_IOBINARY | _IOTEXT);
    fp->_flag |= mode;

    /* ストリームに関連するファイルハンドルも設定 */
    setmode (fp->_file, (mode == _IOBINARY) ? O_BINARY : O_TEXT);
}
