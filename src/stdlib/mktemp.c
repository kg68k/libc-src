/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mktemp.c,v 1.2 1994/11/26 14:59:15 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/stat.h>

/* Functions */
char *mktemp (char *template)
{
    int ch, count, pid;
    char *p;
    struct stat st;

    /* 現在時刻 を求める */
    p = template;
    count = 0;
    pid = (int) _dos_gettim2 () & 0x7fff;

    /* まずテンプレートの最後に移動する */
    while (*p)
	p++;

    /* テンプレートの最後から X である限り数字に置き換えていく */
    while (*--p == 'X' && ++count <= 6) {
	*p = (pid % 10) + '0';
	pid /= 10;
    }

    /* 一つも変換できない場合は template がおかしい */
    if (count <= 0)
	return (char *) -1;

    /* 補正文字は a から始まる */
    ch = 'a';
    p++;

    /* ファイル名が既にある場合は、テンプレートを補正する */
    while (stat (template, &st) >= 0) {

	/* 補正文字が z を越えたらもう任意にできない */
	if (ch > 'z') {
	    *template = '\0';
	    return template;
	}

	/* last の部分の文字を補正する */
	*p = ch++;

    }

    /* ENOENT 以外は他の要因によるエラー */
    if (errno != ENOENT)
	return (char *) -1;

    /* template を返す */
    return template;
}
