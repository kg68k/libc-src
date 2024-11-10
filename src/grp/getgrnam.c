/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getgrnam.c,v 1.1.1.1 1993/04/18 16:17:32 mura Exp $
 */

/* System headers */
#include <grp.h>
#include <string.h>

/* Functions */
struct group *getgrnam (const char *name)
{
    struct group *gp, *fp;

    /* group ファイルをオープンする */
    fp = 0;
    setgrent ();

    /* 1 エントリずつ読み込んでチェックする */
    while (gp = getgrent ()) {
	if (strcmp (gp->gr_name, name) == 0) {
	    fp = gp;
	    break;
	}
    }

    /* group ファイルをクローズする */
    endgrent ();

    return fp;
}
