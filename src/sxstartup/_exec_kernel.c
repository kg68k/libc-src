/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _exec_kernel.c,v 1.3 1994/07/27 13:51:01 mura Exp $
 */

/* System headers */
#include <string.h>
#include <sys/dos.h>
#include <sys/wait.h>
#include <errno.h>

/* External variables */
extern __common char _sxkernelcomm[];

/* Functions */
void exec_kernel (void)
{
    int result;
    union wait r;
    char execpath[90];
    char cmdline[256];

    /* カーネルのパスを取得する */
    strcpy (execpath, _sxkernelcomm);

    /* パス名のチェックし、成功したらロードして実行 */
    if (_dos_pathchk (execpath, cmdline, 0) >= 0)
	if ((result = _dos_loadexec (execpath, cmdline, 0)) >= 0)
	    _dos_loadexec (execpath, cmdline, 0);

    /* エラー情報を設定 */
    r.w_status = 0;
    r.w_liberror = 1;
    r.w_retcode = ENOENT;

    /* エラーメッセージ表示 */
    _dos_print ("libc: cannot execute kernel.\r\n");

    /* 終了する */
    _dos_exit2 (r.w_status);
}
