/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getwd.c,v 1.1 1993/06/06 06:24:20 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <limits.h>

/* Functions */
char *getwd (char *pathname)
{
    /* getcwd に対するインターフェース変換 */
    return getcwd (pathname, PATH_MAX + 1);
}
