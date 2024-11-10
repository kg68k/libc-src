/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Passwd,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getpwnam.c,v 1.1.1.1 1993/04/18 16:20:21 mura Exp $
 */

/* System headers */
#include <pwd.h>
#include <string.h>

/* Functions */
struct passwd *getpwnam (const char *name)
{
    struct passwd *pp, *fp;

    /* passwd ファイルをオープンする */
    fp = 0;
    setpwent ();

    /* 1 エントリずつ読み込んでチェックする */
    while (pp = getpwent ()) {
	if (strcmp (pp->pw_name, name) == 0) {
	    fp = pp;
	    break;
	}
    }

    /* passwd ファイルをクローズする */
    endpwent ();

    return fp;
}
