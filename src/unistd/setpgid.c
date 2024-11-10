/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setpgid.c,v 1.1.1.1 1993/04/18 16:40:21 mura Exp $
 */

/* System headers */
#include <unistd.h>

/* Functions */
int setpgid (pid_t pid, pid_t pgid)
{
    /* 常に成功するが、変化は起こさない */
    return 0;
}
