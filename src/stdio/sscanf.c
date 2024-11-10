/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sscanf.c,v 1.2 1993/06/06 06:09:32 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sys/xstdio.h>

/* Functions */
int sscanf (const char *buffer, const char *format, ...)
{
    int cnt;
    va_list ap;
    struct _stdbuf string;

    /* 文字列バッファを FILE 構造体に合致させる */
    string._ptr = string._base = (unsigned char *) buffer;
    string._cnt = string._bufsiz = strlen (buffer);
    string._flag = _IOREAD | _IOR | _IOBIN | _IOEMU;
    string._file = -1;
    string._nback = 0;

    /* フォーマット出力 */
    va_start (ap, format);
    cnt = _doscan (format, ap, &string);
    va_end (ap);
    return cnt;
}
