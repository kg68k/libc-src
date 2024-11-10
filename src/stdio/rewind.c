/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: rewind.c,v 1.1.1.1 1993/04/18 16:23:09 mura Exp $
 */

/* System headers */
#include <stdio.h>

/* Functions */
void rewind (FILE *fp)
{
    /* 先頭にシークする */
    fseek (fp, 0, SEEK_SET);
}
