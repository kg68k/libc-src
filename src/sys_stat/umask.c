/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: umask.c,v 1.2 1993/08/16 13:41:09 mura Exp $
 */

/* System headers */
#include <sys/stat.h>
#include <unistd.h>

/* Functions */
mode_t umask (mode_t cmask)
{
    mode_t pmask = _umask;

    /* umask のアクセスモード部分だけを更新する */
    _umask = cmask & 0777;

    /* 元のマスクを返す */
    return pmask;
}
