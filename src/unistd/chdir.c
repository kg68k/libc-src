/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: chdir.c,v 1.1.1.1 1993/04/18 16:39:07 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int chdir (const char *path)
{
    int rc, drive;
    char dir[PATH_MAX + 1];

    /* path の最後の / を取り除く */
    _dellastsep (strcpy (dir, path));

    /* ドライブ名がついていたら change drive する */
    if (dir[0] && dir[1] == ':') {

	/* ドライブ名を取り出す */
	drive = toupper (dir[0]) - 'A';

	/* ドライブ名 (A: - Z:) チェック */
	if (drive < 0 || drive > 25) {
	    errno = ENODEV;
	    return -1;
	}

	/* カレントドライブを変更する */
	if ((rc = _dos_chgdrv (drive)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

    }

    /* カレントディレクトリを変更する */
    if ((rc = _dos_chdir (dir)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    return 0;
}
