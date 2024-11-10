/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sigemptyset.c,v 1.1.1.1 1993/04/18 16:21:08 mura Exp $
 */

/* System headers */
#include <signal.h>
#undef sigemptyset

/* Functions */
int sigemptyset (sigset_t *setp)
{
    /* sigset を全部クリアする */
    return *setp = 0;
}
