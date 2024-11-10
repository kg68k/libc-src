/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ungetch.c,v 1.1.1.1 1993/04/18 16:16:10 mura Exp $
 */

/* System headers */
#include <conio.h>
#include <stdio.h>
#include <sys/dos.h>

/* External variables */
int _con_pback;

/* Functions */
int ungetch (int c)
{
    /* pushback できるならする */
    return (_con_pback) ? EOF : (_con_pback = c);
}
