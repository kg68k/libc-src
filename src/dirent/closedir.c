/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: closedir.c,v 1.3 1993/09/07 16:18:44 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

/* Functions */
void closedir (DIR *dirp)
{
    /* メモリを解放する */
    if (dirp->dp)
	free (dirp->dp);

    /* メモリを解放する */
    free (dirp);
}
