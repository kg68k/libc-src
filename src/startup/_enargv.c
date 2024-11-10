/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _enargv.c,v 1.6 1994/07/27 13:47:59 mura Exp $
 */

/* System headers */
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/dos.h>
#include <sys/xstart.h>
#include <sys/xglob.h>

/* Functions */
int _enargv (const struct _psp *proc, int argc, char **argv, const char *com)
{
    int n = 0;
    int i, last;
    static char program_name[PATH_MAX + 1];

    /* HUPAIR による起動か? */
    if (_hupair) {

	/* argv[0] を作成する */
	strcpy (program_name, _comline + strlen (_comline) + 1);

    }

    /* 通常の起動 */
    else {

	/* argv[0] を作成する */
	strcpy (program_name, proc->exe_path);
	strcat (program_name, proc->exe_name);

	/* program_name の最後が . ならそれを取り除く */
	last = strlen (program_name) - 1;
	if (program_name[last] == '.')
	    program_name[last] = '\0';

    }

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
