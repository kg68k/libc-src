/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _enargv.c,v 1.1 1993/10/06 16:51:12 mura Exp $
 */

/* System headers */
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/xstart.h>
#include <sys/xglob.h>

/* Functions */
int _enargv (int argc, char **argv, const char *com)
{
    int n = 0;
    int i, last;
    task tdb;
    static char program_name[PATH_MAX + 1];

    /* タスク管理テーブルを取得する */
    TSGetTdb (&tdb, -1);

    /* 管理テーブルから名前を取り出す */
    strcpy (program_name, tdb.name);

    /* program_name の最後が . ならそれを取り除く */
    last = strlen (program_name) - 1;
    if (program_name[last] == '.')
	program_name[last] = '\0';

    /* ARGV[0] に記録する */
    argv[n++] = program_name;

    /* ARGV 配列を生成する */
    for (i = 0; i < argc; i++) {

	/* オプション指定か */
	if (com[0] == '-' && com[1] == '+' && com[2] == '-') {
	    if (com[3] == 'h' && com[4] == ':') {
		_heapsize = atoi (com + 5);
		goto skipit;
	    }
	    else if (com[3] == 's' && com[4] == ':') {
		_stacksize = atoi (com + 5);
		goto skipit;
	    }
	    else if (com[3] == 'p') {
		_superman |= _SUPER_GO;
		goto skipit;
	    }
	    else if (com[3] == 'f') {
		_superman |= _SUPER_FLOAT;
		goto skipit;
	    }
	    else if (com[3] == 'g') {
		_cplusplus = 1;
		goto skipit;
	    }
	}

	/* ARGV 設定 */
	argv[n++] = (char *) com;

    skipit:

	/* 次の引数の先頭までスキップする */
	while (*com++);

    }

    /* 最後は 0 で打ち止める */
    argv[n] = 0;

    /* 引数の数を返す */
    return n;
}
