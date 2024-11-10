/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getpagesize.c,v 1.1.1.1 1993/04/18 16:39:53 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <limits.h>

/* Functions */
int getpagesize (void)
{
    /* ページサイズを返す */
    return PAGE_SIZE;
}
