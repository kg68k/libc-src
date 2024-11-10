/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: tmpfile.c,v 1.2 1993/11/13 06:34:50 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <unistd.h>
#include <sys/xunistd.h>

/* Functions */
FILE *tmpfile (void)
{
    FILE *fp;
    char *fname;

    /* ファイル名を求める */
    fname = tmpnam (0);

    /* そのファイルを wb+ でオープンする */
    if ((fp = fopen (fname, "wb+")) == 0)
	return 0;

    /*
    ** 筋から言えば unlink (fname) が正しいが、若干時間がかかるため
    ** ここでは直接 _fddb を書き換えることにする。
    */
    _fddb[fp->_file].unlink = 1;

    /* 戻る */
    return fp;
}
