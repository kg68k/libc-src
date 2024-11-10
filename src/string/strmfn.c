/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution by TomY.
 * --------------------------------------------------------------------
 * $Id: strmfn.c,v 1.2 1993/09/07 16:22:03 mura Exp $
 */

/* System headers */
#include <stdlib.h>

/* Functions */
void strmfn (char *path, const char *drive, const char *dir,
	     const char *fname, const char *ext)
{
    /* _makepath と同値 */
    _makepath (path, drive, dir, fname, ext);
}
