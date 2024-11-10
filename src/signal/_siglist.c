/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _siglist.c,v 1.2 1994/07/27 13:47:40 mura Exp $
 */

/* System headers */
#include <signal.h>

/* External variables */
const char *sys_siglist[SIG_MAX + 1] = {
    "Unknown signal",				/* ERROR */
    "SIG0 Inquery signal",			/* 0 */
    "SIGABRT Abnormal program termination",	/* SIGABRT */
    "SIGFPE Mathematical exception",		/* SIGFPE  */
    "SIGILL Illegal instruction",		/* SIGILL  */
    "SIGINT Interrupted",			/* SIGINT  */
    "SIGSEGV Segmentation fault",		/* SIGSEGV */
    "SIGTERM Terminated",			/* SIGTERM */
    "SIGALRM Alarm clock",			/* SIGALRM */
    "SIGKILL Killed",				/* SIGKILL */
    "SIGBUS Bus error",				/* SIGBUS  */
    "SIGSTOP Stopped",				/* SIGSTOP */
    "SIGEMT EMT Trap",				/* SIGEMT  */
    "SIGUSR1 User defined signal 1",		/* SIGUSR1 */
    "SIGUSR2 User defined signal 2",		/* SIGUSR2 */
};

/* External variables */
int sys_nsig = sizeof (sys_siglist) / sizeof (char *);
