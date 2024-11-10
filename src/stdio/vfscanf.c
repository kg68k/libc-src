/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: vfscanf.c,v 1.1.1.1 1993/04/18 16:23:27 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdarg.h>
#include <sys/xstdio.h>

/* Functions */
int vfscanf (FILE *fp, const char *format, va_list ap)
{
    /* フォーマット入力 */
    return _doscan (format, ap, fp);
}
