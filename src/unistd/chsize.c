/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: chsize.c,v 1.1.1.1 1993/04/18 16:39:12 mura Exp $
 */

/* System headers */
#include <unistd.h>

/* Functions */
int chsize (int fd, int size)
{
    /* truncate と chsize は同じ */
    return ftruncate (fd, (off_t) size);
}
