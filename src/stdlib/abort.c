/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: abort.c,v 1.4 1993/08/16 13:36:10 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/xglob.h>
#include <sys/xstart.h>

/* Functions */
void abort (void)
{
    union wait r;

    /* メッセージ表示 */
    _print ("Abnormal program termination\r\n");

    /* 終了コード設定 */
    r.w_status = 0;
    r.w_liberror = 1;
    r.w_retcode = 255;

    /* プログラムを exit する */
    _exit (r.w_status);
}
