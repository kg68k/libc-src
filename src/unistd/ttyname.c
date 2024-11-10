/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ttyname.c,v 1.3 1994/11/26 15:12:47 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xunistd.h>

/* Functions */
char *ttyname (int fd)
{
    int n;
    static char termname[L_ctermid];

#ifdef EBADF_CHECKER
    /* ファイルハンドルチェック */
    if (_usedfd (fd) < 0) {
	errno = EBADF;
	return 0;
    }
#endif

    /* 端末じゃない */
    if (!isatty (fd)) {
	errno = ENOTTY;
	return 0;
    }

    /* キャラクタデバイスならばその名前を返す */
    memcpy (termname, _fddb[fd].fcb.chr.name1, 8);

    /* 有効文字部分を取り出す */
    for (n = 7; termname[n] == ' '; n--);
    termname[n + 1] = '\0';

    /* 文字列を返す */
    return termname;
}
