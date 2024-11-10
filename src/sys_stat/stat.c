/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: stat.c,v 1.2 1993/08/16 13:41:05 mura Exp $
 */

/* System headers */
#include <sys/stat.h>
#include <sys/xstat.h>

/* Functions */
int stat (const char *name, struct stat *st)
{
    /* stat モードで実行 */
    return _statsub (0, name, st);
}
