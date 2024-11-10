/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: chown.c,v 1.1.1.1 1993/04/18 16:39:10 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int chown (const char *path, uid_t owner, gid_t group)
{
    char pathname[PATH_MAX + 1];

    /* パス名の最後に含まれる / を取り除く */
    _dellastsep (strcpy (pathname, path));

    /* ファイルの存在チェック */
    if (_dos_chmod (pathname, -1) < 0)
	return -1;

    /*
    ** Human68k ではファイルに所有者を設定することができない。そこで、ここでは
    ** すべてのユーザーは root であるとみなし、すべての chown 要求は成功するこ
    ** ととする。
    */
    return 0;
}
