/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: creat.c,v 1.1.1.1 1993/04/18 16:17:08 mura Exp $
 */

/* System headers */
#include <fcntl.h>
#include <unistd.h>

/* Functions */
int creat (const char *path, mode_t mode)
{
    /* creat は次と同じ */
    return open (path, O_WRONLY | O_CREAT | O_TRUNC, mode);
}
