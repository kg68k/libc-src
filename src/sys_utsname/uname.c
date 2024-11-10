/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: uname.c,v 1.3 1993/04/25 12:26:25 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/iocs.h>
#include <sys/utsname.h>
#include <sys/xmath.h>

/* Functions */
int uname (struct utsname *name)
{
    char *ptr;
    char temp[10];
    unsigned long vernum;
    int release, version;
    static char mach_name[] = "X68000";

    /* OS は Human68k */
    name->sysname = "Human68k";

    /* ホスト名を求める */
    name->nodename = getenv ("HOST") ? : "unknown";

    /* OS のバージョンを調べる */
    vernum = _dos_vernum ();
    release = ((vernum & 0x0000ff00) >> 8);
    version = ((vernum & 0x000000ff));

    /* リリース番号を文字列にする */
    sprintf (temp, "%d", release);
    if ((ptr = strdup (temp)) == 0)
	return -1;
    name->release = ptr;

    /* バージョンを文字列にする */
    sprintf (temp, "%d", version);
    if ((ptr = strdup (temp)) == 0)
	return -1;
    name->version = ptr;

    /* ハードウェア名称 */
    mach_name[4] = '0' + _iocs_b_bpeek ((void *) 0xcbc);
    name->machine = mach_name;

    return 0;
}
