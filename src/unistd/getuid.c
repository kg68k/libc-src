/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getuid.c,v 1.1.1.1 1993/04/18 16:40:00 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <stdlib.h>

/* Functions */
uid_t getuid (void)
{
    char *uid;

    /* 環境変数 UID から取り出す */
    return (uid = getenv ("UID")) ? atoi (uid) : 0;
}
