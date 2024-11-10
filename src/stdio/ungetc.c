/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ungetc.c,v 1.1.1.1 1993/04/18 16:23:24 mura Exp $
 */

/* System headers */
#include <stdio.h>

/* Functions */
int ungetc (int character, FILE *fp)
{
    /* 制限チェック */
    if ((character == EOF) || (fp->_flag & (_IOREAD | _IOW)) != _IOREAD) {
	fp->_flag |= _IOERR;
	return EOF;
    }

    /* バッファに空きがあれば、そちらへ戻す */
    if (fp->_cnt < fp->_bufsiz) {
	fp->_cnt++;
	return (int) (*--fp->_ptr = (unsigned char) character);
    }

    /* push back バッファに空きがあるか? */
    if (fp->_nback >= sizeof (fp->_pback)) {
	fp->_flag |= _IOERR;
	return EOF;
    }

    /* push back バッファへデータを入れる */
    fp->_flag &= ~_IOEOF;
    fp->_flag |= _IOR;
    return (int) (fp->_pback[fp->_nback++] = (unsigned char) character);
}
