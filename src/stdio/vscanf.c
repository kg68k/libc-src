/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: vscanf.c,v 1.1.1.1 1993/04/18 16:23:31 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdarg.h>
#include <sys/xstdio.h>

/* Functions */
int vscanf (const char *format, va_list ap)
{
    /* フォーマット入力 */
    return _doscan (format, ap, stdin);
}