/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setsid.c,v 1.1.1.1 1993/04/18 16:40:23 mura Exp $
 */

/* System headers */
#include <unistd.h>

/* Functions */
pid_t setsid (void)
{
    /* 常に返す値は 1 (init のプロセス番号とする) */
    return 1;
}
