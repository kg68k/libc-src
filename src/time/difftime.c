/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: difftime.c,v 1.1.1.1 1993/04/18 16:38:24 mura Exp $
 */

/* System headers */
#include <time.h>

/* Functions */
double difftime (time_t newtime, time_t oldtime)
{
    return (double) (newtime - oldtime);
}
