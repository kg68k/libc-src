/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _md2u.c,v 1.2 1993/09/07 16:23:53 mura Exp $
 */

/* System headers */
#include <sys/stat.h>
#include <sys/dos.h>
#include <sys/xunistd.h>

/* Functions */
mode_t _mode2unix (dosmode_t attr)
{
    mode_t mode;

    /* ビット属性を変換する */
    mode = (((attr & _DOS_IRDONLY) ? (S_IREAD | S_IRDONLY) : (S_IREAD | S_IWRITE)) |
	    ((attr & _DOS_IEXEC) ? S_IEXEC | S_IEXBIT : 0) |
	    ((attr & _DOS_IFVOL) ? S_IFVOL : 0) |
	    ((attr & _DOS_ISYS) ? S_ISYS : 0) |
	    ((attr & _DOS_IHIDDEN) ? S_IHIDDEN : 0));

    /* シンボリックリンク属性を変換する */
    if ((attr & _DOS_IFMT) == _DOS_IFLNK)
	mode |= S_IFLNK | S_IEXEC;

    /* ディレクトリ属性を変換する */
    else if (attr & _DOS_IFDIR)
	mode |= S_IFDIR | S_IEXEC;

    /* 通常ファイル属性を変換する */
    else
	mode |= S_IFREG;

    return mode;
}
