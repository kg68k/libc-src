/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fdopen.c,v 1.2 1993/08/16 13:35:37 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/xstdio.h>

/* Functions */
FILE *fdopen (int fd, const char *mode)
{
    int new_md;
    int old_md;
    FILE *fp;

#ifdef EBADF_CHECKER
    /* 有効なファイルハンドルか */
    if (_usedfd (fd) < 0) {
       errno = EBADF;
       return 0;
   }
#endif

    /* 空いている iob を探す */
    if ((fp = _getemptyiob ()) == 0) {
	errno = EMFILE;
	return 0;
    }

    /* fp のFILE 構造体を作成する */
    if ((new_md = _sopen (fp, mode, _IOFBF)) < 0) {
	fclose (fp);
	return 0;
    }

    /* ファイルディスクリプタを設定する */
    fp->_file = fd;

    /* 元のモードを取得する */
    old_md = fcntl (fd, F_GETFL);

    /* オープンモード調整 */
    new_md = (old_md & ~O_STSMODE) | (new_md & O_STSMODE);

    /* ファイルモード再設定 */
    fcntl (fd, F_SETFL, new_md);

    return fp;
}
