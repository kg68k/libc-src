/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: endgrent.c,v 1.1.1.1 1993/04/18 16:17:27 mura Exp $
 */

/* System headers */
#include <grp.h>
#include <stdio.h>
#include <sys/xglob.h>
#include <sys/xgrp.h>

/* Functions */
void endgrent (void)
{
    /* group ファイルがオープンされていれば close する */
    if (_grp_fp) {
	fclose (_grp_fp);
	_grp_fp = 0;
    }
}
