/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: wait.c,v 1.1 1993/05/23 10:29:49 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <sys/wait.h>
#include <sys/dos.h>
#include <sys/types.h>
#include <sys/xglob.h>

/* Functions */
pid_t wait (int *stat_loc)
{
    int rc;

    /* 終了コードを得る */
    if ((rc = _dos_wait ()) < 0) {
	errno = _errcnv (rc);
	return (pid_t) -1;
    }

    /* 終了コードを格納する */
    *stat_loc = rc;

    /* 終了プロセスのプロセス ID を返す */
    return (pid_t) 0;
}
