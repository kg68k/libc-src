/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fopen.c,v 1.1.1.1 1993/04/18 16:22:36 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* Functions */
FILE *fopen (const char *fname, const char *mode)
{
    int omode;
    FILE *fp;

    /* 空いている iob を探す */
    if ((fp = _getemptyiob ()) == 0) {
	errno = EMFILE;
	return 0;
    }

    /* FILE 構造体を作成する */
    if ((omode = _sopen (fp, mode, _IOFBF)) < 0) {
	fclose (fp);
	return 0;
    }

    /* 実際にファイルをオープンする */
    if ((fp->_file = open (fname, omode, 0666)) < 0) {
	fclose (fp);
	return 0;
    }

    return fp;
}
