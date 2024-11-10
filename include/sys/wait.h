/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: wait.h,v 1.3 1993/10/06 16:47:03 mura Exp $
 */

#ifndef __sys_wait_h__
#define __sys_wait_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_types_h__
#include <sys/types.h>
#endif

union wait {
    int_ w_status;
    struct {
	unsigned short filler;
	unsigned char liberror:1;
	unsigned char coredump:1;
	unsigned char termsig:6;
	unsigned char retcode;
    } w_T;
};

#define w_coredump w_T.coredump
#define w_liberror w_T.liberror
#define w_retcode  w_T.retcode
#define w_termsig  w_T.termsig

#define WEXITSTATUS(s)   ((s).w_retcode)
#define WIFCOREDUMPED(s) ((s).w_coredump != 0)
#define WIFEXITED(s)     ((s).w_termsig == 0)
#define WIFLIBERROR(s)   ((s).w_liberror != 0)
#define WIFSIGNALED(s)   ((s).w_termsig != 0)
#define WTERMSIG(s)      ((s).w_termsig)

#if 0 /* currently not supported */
#define WSTOPSIG(s)
#define WIFSTOPPED(s)
#endif

_EXTERN (pid_t wait (int_ *));
_EXTERN (pid_t waitpid (pid_t, int_ *, int_));

#endif
