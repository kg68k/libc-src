/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from Mariko.
 * --------------------------------------------------------------------
 * $Id: _fncprof.c,v 1.1.1.1 1993/04/18 16:21:43 mura Exp $
 */

/* System headers */
#include <sys/xprof.h>

/* External varibles */
int _fpuse;

/* Functions */
void __display_function_profile (void)
{
    /* 通常はダミー関数で、実体は libprof.a にある */
}
