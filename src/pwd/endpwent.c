/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Passwd,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: endpwent.c,v 1.1.1.1 1993/04/18 16:20:18 mura Exp $
 */

/* System headers */
#include <pwd.h>
#include <stdio.h>
#include <limits.h>
#include <sys/xpwd.h>

/* Functions */
void endpwent (void)
{
    /* passwd ファイルがオープンされていれば close する */
    if (_pwd_fp) {
	fclose (_pwd_fp);
	_pwd_fp = 0;
    }
}
