/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _pconf.c,v 1.1.1.1 1993/04/18 16:38:52 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <limits.h>
#include <errno.h>

/* File scope functions */
long _pathconf (int name)
{
    /* name を解析する */
    switch (name) {

    case _PC_NAME_MAX:
	return NAME_MAX;
    case _PC_PATH_MAX:
	return PATH_MAX;
    case _PC_CHOWN_RESTRICTED:
	return _POSIX_CHOWN_RESTRICTED;
    case _PC_NO_TRUNC:
	return _POSIX_NO_TRUNC;

    /*
    ** 以下の値は参考値であり、実際にインプリメントされていないので
    ** EINVAL を返すようにする
    */

    /*
    case _PC_LINK_MAX:
	return LINK_MAX;
    case _PC_MAX_CANON:
	return MAX_CANON;
    case _PC_MAX_INPUT:
	return MAX_INPUT;
    case _PC_PIPE_BUF:
	return PIPE_BUF;
    case _PC_VDISABLE:
	return _POSIX_VDISABLE;
    */

    }

    /* それ以外はエラー */
    errno = EINVAL;
    return -1;
}
