/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getcwd.c,v 1.2 1993/05/21 14:11:20 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xunistd.h>

/* Functions */
char *getcwd (char *buff, int size)
{
    int drive;

    /* buff が NULL なら malloc する */
    if (buff == 0) {

	/* 最低限 size バイトのサイズを求める */
	size = max (PATH_MAX + 1, size);

	if ((buff = (char *) malloc (size)) == 0)
	    return 0;

    }

    /* 値チェック */
    if (size < 3) {
	errno = EINVAL;
	return 0;
    }

    /* カレントドライブを調べる */
    drive = _dos_curdrv ();
    buff[0] = 'A' + drive;
    buff[1] = ':';
    size -= 2;

    /* カレントディレクトリを調べる */
    return getdcwd (drive + 1, buff + 2, size) - 2;
}
