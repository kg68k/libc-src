/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from Seirios.
 * --------------------------------------------------------------------
 * $Id: drand.c,v 1.1.1.1 1993/04/18 16:24:11 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <limits.h>

/* Functions */
double drand (void)
{
    return (double) ((1.0 / (1.0 + (double) ULONG_MAX)) * random ());
}
