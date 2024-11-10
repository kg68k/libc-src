/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: nice.c,v 1.1.1.1 1993/04/18 16:40:05 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/xunistd.h>

/* File scope variables */
static int _nice = NZERO;

/* Functions */
int nice (int incr)
{
    int newval = _nice + incr;

    /* nice 値計算 */
    if (newval < 0)
	newval = 0;
    else if (newval > 2 * NZERO - 1)
	newval = 2 * NZERO - 1;

    /*
    ** Human68k version2 の段階でもバックグラウンド機能は十分にサポートされて
    ** いない。よって、ここでは nice はダミーとし、常に成功するものとする。
    */
    return (_nice = newval);
}
