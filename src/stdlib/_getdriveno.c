/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _getdriveno.c,v 1.2 1993/06/06 06:09:51 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <ctype.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xstdlib.h>

/* Functions */
int _getdriveno (const char *path)
{
    int drv;
    struct _namestbuf nsbuf;

    /* ドライブ名があった場合は ... */
    if (path[1] == ':')
	drv = toupper (path[0]) - 'A';

    /* 無かった場合は NAMESTS */
    else {
	_dos_namests (path, &nsbuf);
	drv = (int) nsbuf.drive;
    }

    /* ドライブ番号を返す */
    return drv;
}
