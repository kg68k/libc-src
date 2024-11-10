/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: putch.c,v 1.2 1993/10/06 16:48:51 mura Exp $
 */

/* System headers */
#include <conio.h>
#include <sys/dos.h>

/* Functions */
int putch (int c)
{
    /* 1 バイトコンソール出力 */
    _dos_c_putc (c);

    /* c を返す */
    return c;
}
