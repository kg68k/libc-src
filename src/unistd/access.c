/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: access.c,v 1.2 1993/09/16 15:29:08 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int access (const char *fname, int mode)
{
    int rc, result;
    struct stat st;
    char path[PATH_MAX + 1];

    /* パス名の最後の / を取り除く */
    _dellastsep (strcpy (path, fname));

    /* path を stat する */
    rc = stat (path, &st);

    /* F_OK チェックの場合とエラーの場合は終わり */
    if ((mode == F_OK) || (rc < 0))
	return rc;

    /* フラグクリア */
    result = 0;

    /* R_OK チェック */
    if (mode & R_OK)
	result += (st.st_mode & S_IREAD);

    /* W_OK チェック */
    if (mode & W_OK)
	result += (st.st_mode & S_IWRITE);

    /* X_OK チェック */
    if (mode & X_OK)
	result += (st.st_mode & S_IEXEC);

    /* アクセスチェックの結果は「ダメ」*/
    if (result == 0) {
	errno = EACCES;
	return -1;
    }

    /* 正常終了 */
    return 0;
}
