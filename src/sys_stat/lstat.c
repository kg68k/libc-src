/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: lstat.c,v 1.2 1993/08/16 13:40:55 mura Exp $
 */

/* System headers */
#include <sys/stat.h>
#include <sys/xstat.h>

/* Functions */
int lstat (const char *name, struct stat *st)
{
    /* lstat モードで実行 */
    return _statsub (S_IFLNK, name, st);
}
