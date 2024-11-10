/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sizmem.c,v 1.1.1.1 1993/04/18 16:24:46 mura Exp $
 */

/* System headers */
#include <stdlib.h>

/* Functions */
size_t sizmem (void)
{
    /* ロングワード単位に直す */
    return (chkml () >> 2);
}
