/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from hupairlib by K.Abe (Abechan).
 * --------------------------------------------------------------------
 * $Id: execv.c,v 1.2 1993/09/16 15:29:28 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/xunistd.h>

/* Functions */
int execv (const char *path, char *const argv[])
{
     /* 実行する */
    return _spawn (P_OVERLAY, path, argv, 0, 0);
}