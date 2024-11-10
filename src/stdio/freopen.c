/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: freopen.c,v 1.1.1.1 1993/04/18 16:22:43 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/xstdio.h>

/* Functions */
FILE *freopen (const char *fname, const char *mode, FILE *fp)
{
    int omode;

    /* 元のファイルをクローズする */
    fclose (fp);

    /* fp のFILE 構造体を作成する */
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
