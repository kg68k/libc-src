/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: kbhit.c,v 1.1.1.1 1993/04/18 16:16:07 mura Exp $
 */

/* System headers */
#include <conio.h>
#include <sys/dos.h>

/* Functions */
int kbhit (void)
{
    extern int _con_pback;

    /* キーバッファを先読みする */
    return (_con_pback) ? : _dos_inpout (0xfe);
}
