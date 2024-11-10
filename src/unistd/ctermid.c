/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ctermid.c,v 1.2 1994/11/26 15:10:29 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/dos.h>
#include <sys/xunistd.h>

/* Functions */
char *ctermid (char *buff)
{
    int n;
    char *ptr;
    static char termid[L_ctermid];

    /* 出力バッファ選択 */
    ptr = buff ? buff : termid;

    /* キャラクタデバイスならばその名前を返す */
    if (_fddb[STDIN_FILENO].cdev) {
	memcpy (ptr, _fddb[STDIN_FILENO].fcb.chr.name1, 8);
	for (n = 7; ptr[n] == ' '; n--);
	ptr[n + 1] = '\0';
    }

    /* 標準入力がブロックデバイスならば con を返す */
    else
	strcpy (ptr, "CON");

    /* アドレスを返す */
    return ptr;
}
