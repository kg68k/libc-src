/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: tempnam.c,v 1.1.1.1 1993/04/18 16:23:19 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/xglob.h>
#include <sys/xstdio.h>

/* Functions */
char *tempnam (const char *dir, const char *prefix)
{
    int last;
    char *buffer;
    struct stat st;

    /*
     ** 呼び出し回数は特に管理していない。TMP_MAX の値は小文字アルファベット
     ** 4 文字の組み合わせの数 26^4 である。これを越えた場合も単に循環するだ
     ** けなので問題はない。
     */

    /* L_tmpnam 分のバッファを確保する */
    if ((buffer = (char *) malloc (L_tmpnam)) == 0)
	return 0;

    /* dir というディレクトリを調べる */
    if (dir == 0 || stat (dir, &st) < 0 || S_ISDIR (st.st_mode) == 0)
	dir = P_tmpdir;

    /* dir/ という template を作成する */
    strcpy (buffer, dir);
    _toslash (buffer);
    _addlastsep (buffer);

    /* dir/prefix ただし prefix は 5 文字まで */
    last = strlen (buffer);
    strcpy (buffer + last, prefix);
    buffer[last + 5] = '\0';

    /* dir/prefixXXXXXX を作成 */
    strcat (buffer, "XXXXXX");

    /* mktemp をコールし、ファイル名を生成する */
    return mktemp (buffer);
}
