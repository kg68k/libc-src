/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: chdrive.c,v 1.2 1993/05/21 14:11:15 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <unistd.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int chdrive (int drive)
{
    int rc;

    /* drive チェンジ */
    if ((rc = _dos_chgdrv (drive - 1)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    return 0;
}
