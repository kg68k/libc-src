/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: remove.c,v 1.1.1.1 1993/04/18 16:23:06 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

/* Functions */
int remove (const char *fname)
{
    int rc;

    /* fname を削除する */
    rc = unlink (fname);

    /* ディレクトリなので削除できない場合はさらに rmdir する */
    if (rc < 0 && errno == EISDIR)
	rc = rmdir (fname);

    /* 戻る */
    return rc;
}
