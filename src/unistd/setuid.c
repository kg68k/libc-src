/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: setuid.c,v 1.1.1.1 1993/04/18 16:40:24 mura Exp $
 */

/* System headers */
#include <unistd.h>

/* Functions */
int setuid (uid_t new)
{
    /* 常に成功するが、変化は起こさない */
    return 0;
}
