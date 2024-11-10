/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from Seirios.
 * --------------------------------------------------------------------
 * $Id: srand.c,v 1.1.1.1 1993/04/18 16:24:47 mura Exp $
 */

/* System headers */
#include <stdlib.h>

/* Functions */
void srand (unsigned int seed)
{
    srandom ((unsigned int) seed);
}