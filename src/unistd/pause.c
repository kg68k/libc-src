/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: pause.c,v 1.1.1.1 1993/04/18 16:40:09 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xsignal.h>
#include <sys/xunistd.h>

/* Functions */
int pause (void)
{
    /* pause フラグをセットする */
    _pause = 1;

    /* pause フラグが割り込みルーチンによってクリアされるまで待つ */
    while (_pause);

    /* 常にエラーを返す */
    errno = EINTR;
    return -1;
}
