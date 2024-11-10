/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getdrive.c,v 1.1.1.1 1993/04/18 16:39:45 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int getdrive (void)
{
    int drv;

    /* drive を調べる */
    if ((drv = _dos_curdrv ()) < 0) {
	errno = _errcnv (drv);
	return -1;
    }

    return drv + 1;
}
