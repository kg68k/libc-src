/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: cuserid.c,v 1.1.1.1 1993/04/18 16:39:20 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
** この関数は POSIX 1003.1a で削除されたが、SVR4 との互換性のために存在する
*/

/* Functions */
char *cuserid (char *buff)
{
    char *logname;
    static char userid[L_cuserid];

    /*
    ** Human68k にはユーザー名という概念はないのでシェル(例えばfish)が設定
    ** した名前を利用する。また、別のユーザーへの切替えはできないので常にロ
    ** グインユーザーである。現在のところ、ログインユーザー名は環境変数 LOGNAME
    ** から取り出される。
    */
    if ((logname = getenv ("LOGNAME")) == 0) {
	if ((logname = getenv ("USER")) == 0) {

	    /* buff が null ポインターならば null を返す */
	    if (buff == 0)
		return 0;
	    else {
		buff[0] = '\0';
		return buff;
	    }

	}
    }

    return strcpy (buff ? buff : userid, logname);
}
