/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getgrgid.c,v 1.1.1.1 1993/04/18 16:17:30 mura Exp $
 */

/* System headers */
#include <grp.h>

/* Functions */
struct group *getgrgid (gid_t gid)
{
    struct group *gp, *fp;

    /* group ファイルをオープンする */
    fp = 0;
    setgrent ();

    /* 1 エントリずつ読み込んでチェックする */
    while (gp = getgrent ()) {
	if (gp->gr_gid == gid) {
	    fp = gp;
	    break;
	}
    }

    /* group ファイルをクローズする */
    endgrent ();

    return fp;
}
