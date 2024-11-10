/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbsdup.c,v 1.1.1.1 1993/04/18 16:19:38 mura Exp $
 */

/* System headers */
#include <mbstring.h>
#include <stdlib.h>
#include <string.h>

/* Functions */
unsigned char *mbsdup (const unsigned char *string)
{
    unsigned char *new;

    /* メモリを割り当てる */
    if ((new = (unsigned char *) malloc (strlen ((char *) string) + 1)) == 0)
	return 0;

    /* マルチバイト文字列をコピーする */
    return mbscpy (new, string);
}
