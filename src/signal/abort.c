/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: abort.c,v 1.1.1.1 1993/04/18 16:20:58 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <signal.h>

/* Functions */
void abort (void)
{
    /* SIGABRT を raise する */
    raise (SIGABRT);
}
