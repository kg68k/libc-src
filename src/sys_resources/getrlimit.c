/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getrlimit.c,v 1.1.1.1 1993/04/18 16:36:51 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <sys/resource.h>
#include <sys/xresource.h>

/* Functions */
int getrlimit (int restype, struct rlimit *rlp)
{
    /* restype のチェック */
    if (restype < 0 && restype >= RLIM_NLIMITS) {
	errno = EINVAL;
	return -1;
    }

    /* rlp にデータをコピーする */
    *rlp = _limits[restype];

    /* 成功 */
    return 0;
}
