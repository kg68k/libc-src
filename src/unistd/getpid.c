/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getpid.c,v 1.1.1.1 1993/04/18 16:39:57 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/xstart.h>

/* Functions */
pid_t getpid (void)
{
    /*
    ** プロセス ID は通常 0 から 30000 まででサイクリックに使用されるが、
    ** もともと Human68k にはそういう概念はないので、代わりにプロセス管
    ** 理ポインタの値を利用する。そういう意味で、値の範囲が UNIX とは異
    ** なる。
    */
    return (pid_t) _procp;
}
