/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getegid.c,v 1.1.1.1 1993/04/18 16:39:46 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <stdlib.h>

/* Functions */
gid_t getegid (void)
{
    char *egid;

    /* 環境変数 EGID から取り出す */
    return (egid = getenv ("EGID")) ? atoi (egid) : getgid ();
}
