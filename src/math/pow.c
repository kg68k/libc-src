/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: pow.c,v 1.1.1.1 1993/04/18 16:18:32 mura Exp $
 */

/* System headers */
#include <math.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xmath.h>

/* Functions */
double pow (double x, double y)
{
    /* FLOAT で計算する */
    return FPACK2 (__POWER, x, y);
}