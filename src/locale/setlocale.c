/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setlocale.c,v 1.1.1.1 1993/04/18 16:17:42 mura Exp $
 */

/* System headers */
#include <locale.h>
#include <errno.h>
#include <string.h>

/*
** 現在は C ロケールしかサポートしていない
*/

/* Functions */
char *setlocale (int category, const char *locale)
{
    /* category チェック */
    if (category != LC_ALL &&
	category != LC_COLLATE &&
	category != LC_CTYPE &&
	category != LC_MONETARY &&
	category != LC_NUMERIC &&
	category != LC_TIME) {
	errno = EINVAL;
	return 0;
    }

    /* locale を設定する? */
    if (locale) {

	/* locale が C 以外はエラー */
	if (strcmp (locale, "C") != 0) {
	    errno = EINVAL;
	    return 0;
	}

	/* 一切効果がない */
	/* .... */

    }

    /* 現在の状態を返す */
    return "C";
}
