/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: tmpnam.c,v 1.1.1.1 1993/04/18 16:23:22 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/xglob.h>
#include <sys/xstdio.h>

/* Functions */
char *tmpnam (char *name)
{
    int i;
    char *ptr;
    static char local_header[5] = "aaaa\0";
    static char local_buffer[L_tmpnam];

    /*
     ** 呼び出し回数は特に管理していない。TMP_MAX の値は小文字アルファベット
     ** 4 文字の組み合わせの数 26^4 である。これを越えた場合も単に循環するだ
     ** けなので問題はない。
     */

    /* name が null の場合は内部バッファを使用する */
    if (name == 0)
	name = local_buffer;

    /* 環境変数 temp の値を参照する */
    if (ptr = getenv ("temp"))
	_toslash (strcpy (name, ptr));
    else
	_sysroot (name, P_tmpdir, L_tmpnam);

    /* 最後の / を加える */
    _addlastsep (name);

    /* テンプレートを作る */
    strcat (name, local_header);
    strcat (name, "XXXXXX");

    /* テンプレートヘッダ (4 文字の小文字アルファベット) を更新 */
    i = 3;
    while (1) {

	/* 繰り上がりがないなら、これでおしまい */
	if (++local_header[i] <= 'z')
	    break;

	/* z->a に戻す */
	local_header[i] = 'a';

	/* 桁あふれしたら、全てを元に戻す */
	if (--i < 0) {
	    strcpy (local_header, "aaaa");
	    break;
	}
    }

    /* mktemp をコールし、ファイル名を生成する */
    return mktemp (name);
}
