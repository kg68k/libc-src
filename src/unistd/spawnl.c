/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from hupairlib by K.Abe (Abechan).
 * --------------------------------------------------------------------
 * $Id: spawnl.c,v 1.2 1993/09/16 15:29:42 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/xunistd.h>

/* Functions */
int spawnl (int mode, const char *path, const char *arg0, ...)
{
    /* 実行する */
    return _spawn (mode, path, (char **) &arg0, 0, 0);
}
