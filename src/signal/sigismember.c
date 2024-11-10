/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sigismember.c,v 1.1.1.1 1993/04/18 16:21:11 mura Exp $
 */

/* System headers */
#include <signal.h>
#undef sigismember

/* Functions */
int sigismember (sigset_t *setp, int sig)
{
    /* sigset に sig が登録されているかどうかを調べる */
    return (*setp & (1 << sig)) ? 1 : 0;
}
