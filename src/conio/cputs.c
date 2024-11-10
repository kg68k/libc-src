/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: cputs.c,v 1.2 1993/10/06 16:48:40 mura Exp $
 */

/* System headers */
#include <conio.h>
#include <sys/dos.h>

/* Functions */
int cputs (const char *string)
{
    /* コンソール出力 */
    _dos_c_print (string);

    /* 成功 */
    return 0;
}
