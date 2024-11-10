/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: rbrk.c,v 1.1.1.1 1993/04/18 16:24:41 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <sys/xstart.h>

/* Functions */
void rbrk (void)
{
    /* ヒープ領域を元に戻す */
    brk (_hsta);
}
