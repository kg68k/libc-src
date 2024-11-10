/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getppid.c,v 1.1.1.1 1993/04/18 16:39:58 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/dos.h>
#include <sys/xstart.h>

/* Functions */
pid_t getppid (void)
{
    /*
    ** プロセス ID は通常 0 から 30000 まででサイクリックに使用されるが、
    ** もともと Human68k にはそういう概念はないので、代わりにプロセス管理
    ** メモリポインタの値をID として利用する。また、親プロセスの代わりに
    ** 親プロセス管理ポインタの値を利用する。
    */
    return (pid_t) (_memcp->parent_mp + 0x10);
}
