/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setbuf.c,v 1.1.1.1 1993/04/18 16:23:12 mura Exp $
 */

/* System headers */
#include <stdio.h>

/* Functions */
void setbuf (FILE *fp, char *buf)
{
    /* buf が null かどうかによって異なる */
    setvbuf (fp, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
}
