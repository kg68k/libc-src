/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sigpending.c,v 1.1.1.1 1993/04/18 16:21:15 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <sys/xsignal.h>

/* Functions */
int sigpending (sigset_t *setp)
{
    /* pending されている sigset を返す */
    *setp = _sigpendingset;
    return 0;
}