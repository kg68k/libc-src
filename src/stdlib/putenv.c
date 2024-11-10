/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: putenv.c,v 1.3 1994/07/27 13:50:23 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/xstart.h>

/* Functions */
int putenv (const char *string)
{
    size_t len, size;
    char *equal, *new;
    char **ptr;

    /* = がない場合はエラー */
    if ((equal = strchr (string, '=')) == 0) {
	errno = EINVAL;
	return -1;
    }

    /* = の後ろが空文字の場合はその環境変数を削除 */
    if (equal[1] == '\0') {

	/* string の長さを調べて */
	len = strlen (string) - 1;

	/* 環境変数より string を削除する */
	for (ptr = environ; *ptr; ptr++)
	    if (strncmp (*ptr, string, len) == 0 && (*ptr)[len] == '=')
		do ptr[0] = ptr[1]; while (*++ptr);

	/* 見つかっても見つからなくても成功 */
	return 0;

    }

    /* 設定値の長さを調べて */
    len = equal - string;

    /* 環境変数を探しつつ、テーブルの大きさを計る */
    for (ptr = environ, size = 0; *ptr; ptr++, size++)
	if (strncmp (*ptr, string, len) == 0 && (*ptr)[len] == '=')
	    break;

    /* 見つかったならば、その値を変更する */
    if (*ptr) {

	/* string が原始環境領域以外の位置を指していれば malloc されたものであろう */
	if (*ptr < (char *) _esta || *ptr >= (char *) _fsta)
	    free (*ptr);

	/* 新たに領域を確保する */
	if ((new = strdup (string)) == 0)
	    return -1;

	/* ポインタ書き換え */
	*ptr = new;

	/* 正常終了 */
	return 0;

    }

    /* 追加用に新しい環境配列を確保する */
    if ((ptr = (char **) malloc ((size + 2) * sizeof (char *))) == 0)
	return -1;

    /* 文字列を複製する */
    if ((new = strdup (string)) == 0) {
	free (ptr);
	return -1;
    }

    /* 現在の環境変数テーブルを新しいテーブルにコピー */
    memcpy (ptr, environ, size * sizeof (char *));

    /* 指定された文字列の追加（最終エントリとなる）*/
    ptr[size] = new;
    ptr[size + 1] = 0;

    /* 古い環境変数テーブルを削除 */
    if (environ != _fsta)
	free (environ);

    /* environ を更新 */
    environ = ptr;

    /* 正常終了 */
    return 0;
}
