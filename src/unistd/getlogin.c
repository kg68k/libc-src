/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getlogin.c,v 1.1.1.1 1993/04/18 16:39:52 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Functions */
char *getlogin (void)
{
    char *logname;
    static char username[L_cuserid];

    /*
    ** Human68k にはユーザー名という概念はないのでシェル(例えばfish)が設定
    ** した名前を利用する。また、別のユーザーへの切替えはできないので常にロ
    ** グインユーザーである。現在のところ、ログインユーザー名は環境変数 LOGNAME
    ** から取り出される。
    */
    if ((logname = getenv ("LOGNAME")) == 0) {
	if ((logname = getenv ("USER")) == 0)
	    logname = "root";
    }

    /* データは static な領域に保存される */
    return strcpy (username, logname);
}
