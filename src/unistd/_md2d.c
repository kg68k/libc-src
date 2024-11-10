/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _md2d.c,v 1.2 1993/05/21 14:11:10 mura Exp $
 */

/* System headers */
#include <sys/stat.h>
#include <sys/dos.h>
#include <sys/xunistd.h>

/* Functions */
dosmode_t _mode2dos (const mode_t mode)
{
    dosmode_t attr;

    /* 属性を変換する */
    attr = (((mode & S_IRDONLY) ? _DOS_IRDONLY : 0) |
	    ((mode & S_IWRITE) ? 0 : _DOS_IRDONLY) |
	    ((mode & S_IHIDDEN) ? _DOS_IHIDDEN : 0) |
	    ((mode & S_ISYS) ? _DOS_ISYS : 0) |
	    ((mode & S_IFVOL) ? _DOS_IFVOL : 0) |
	    ((mode & (S_IEXBIT | S_IEXEC)) ? _DOS_IEXEC : 0) |
	    (S_ISLNK (mode) ? _DOS_IFLNK : 0) |
	    (S_ISDIR (mode) ? _DOS_IFDIR : 0) |
	    (S_ISREG (mode) ? _DOS_IFREG : 0));

    return attr;
}
