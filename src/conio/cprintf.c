/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: cprintf.c,v 1.2 1993/10/06 16:48:36 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <sys/dos.h>

/* Functions */
int cprintf (const char *format, ...)
{
    int cnt;
    va_list ap;
    char buffer[512];

    /* フォーマット出力 */
    va_start (ap, format);
    cnt = vsprintf (buffer, format, ap);
    va_end (ap);

    /* コンソール出力 */
    _dos_c_print (buffer);

    /* cnt を返す */
    return cnt;
}
