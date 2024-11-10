/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setvbuf.c,v 1.4 1993/09/07 16:20:23 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/* Functions */
int setvbuf (FILE *fp, char *buf, int type, size_t size)
{
    int bufsiz;

    /* type が FBF,LBF,NBF 以外ならばエラー */
    if (type != _IOFBF && type != _IOLBF && type != _IONBF)
	return -1;

    /* 既にバッファ操作が行なわれている時はエラー */
    if (fp->_flag & (_IOR | _IOW))
	return -1;

    /* _IONBF の時は自前のバッファを利用する */
    if (type == _IONBF) {
	bufsiz = 1;
	buf = (char *) fp->_nbuff;
    }

    /* buf が null pointer ならば自前で用意する */
    else {
	bufsiz = size;
	if (buf == 0) {
	    type |= _IOFREE;
	    if ((buf = (char *) malloc (bufsiz)) == 0)
		return -1;
	}
    }

    /* 割当が成功した場合に限り今使われているバッファを解放する */
    if (fp->_flag & _IOFREE) {
	fp->_flag &= ~_IOFREE;
	free (fp->_base);
    }

    /* バッファサイズ、ポインタ等を書き換える */
    fp->_flag &= ~(_IOLBF | _IOFBF | _IONBF);
    fp->_flag |= type;
    fp->_base = (unsigned char *) buf;
    fp->_ptr = (unsigned char *) buf;
    fp->_bufsiz = bufsiz;
    fp->_cnt = 0;
    fp->_nback = 0;

    /* 終り */
    return 0;
}
