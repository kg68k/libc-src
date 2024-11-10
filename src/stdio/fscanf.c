/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: fscanf.c,v 1.1.1.1 1993/04/18 16:22:45 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdarg.h>
#include <sys/xstdio.h>

/* Functions */
int fscanf (FILE *fp, const char *format, ...)
{
    int cnt;
    va_list ap;

    /* フォーマット出力 */
    va_start (ap, format);
    cnt = _doscan (format, ap, fp);
    va_end (ap);
    return cnt;
}
