/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strsfn.c,v 1.2 1993/08/16 13:37:31 mura Exp $
 */

/* System headers */
#include <limits.h>
#include <string.h>
#include <stdlib.h>

/* Functions */
void strsfn (const char *name, char *drv, char *path, char *node, char *ext)
{
    char xname[PATH_MAX + 1];
    char ename[PATH_MAX + 1];

    /* フルパスに展開する */
    _fullpath (xname, name, sizeof xname);

    /* パス構成要素を分解する */
    _splitpath (xname, drv, path, node, ename);

    /* 拡張子を除いてコピーする */
    strcpy (ext, (*ename == '.') ? ename + 1 : ename);
}
