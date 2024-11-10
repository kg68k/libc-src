/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strcoll.c,v 1.1.1.1 1993/04/18 16:25:26 mura Exp $
 */

/* System headers */
#include <string.h>

/* Functions */
int strcoll (const char *s1, const char *s2)
{
    /*
    ** 本来なら、LC_COLLATE によってコードセットを変更するのだが
    ** 本関数はその機能を実装していない。LC_COLLATE はいつでも "C"
    ** を想定する
    */
    return (strcmp (s1, s2));
}
