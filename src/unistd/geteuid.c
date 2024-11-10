/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: geteuid.c,v 1.1.1.1 1993/04/18 16:39:48 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <stdlib.h>

/* Functions */
uid_t geteuid (void)
{
    char *euid;

    /* 環境変数 EUID から取り出す */
    return (euid = getenv ("EUID")) ? atoi (euid) : getuid ();
}
