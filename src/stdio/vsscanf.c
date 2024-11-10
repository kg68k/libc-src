/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: vsscanf.c,v 1.1.1.1 1993/04/18 16:23:34 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdarg.h>
#include <sys/xstdio.h>

/* Functions */
int vsscanf (const char *buffer, const char *format, va_list ap)
{
    struct _stdbuf string;

    /* 文字列バッファを FILE 構造体に合致させる */
    string._ptr = string._base = (unsigned char *) buffer;
    string._cnt = string._bufsiz = 0x10000;
    string._flag = _IOREAD | _IOR | _IOBIN;
    string._file = -1;
    string._nback = 0;

    /* フォーマット出力 */
    return _doscan (format, ap, &string);
}
