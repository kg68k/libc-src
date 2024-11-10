/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: vfprintf.c,v 1.1.1.1 1993/04/18 16:23:26 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdarg.h>
#include <sys/xstdio.h>

/* Functions */
int vfprintf (FILE *fp, const char *format, va_list ap)
{
    /* フォーマット出力 */
    return _doprnt (format, ap, fp);
}
