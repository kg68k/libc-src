/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: clearenv.c,v 1.1.1.1 1993/04/18 16:24:08 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <stdlib.h>
#include <sys/xstart.h>

/* Functions */
int clearenv (void)
{
    char **newenv;

    /* 新しい領域を確保する */
    if ((newenv = (char **) malloc (sizeof (char *))) == 0)
	return -1;

    /* environ == _fsta ならば固定領域、さもなくばヒープ領域を指す */
    if (environ != _fsta)
	free (environ);

    /* 全てを初期化する */
    newenv[0] = 0;
    environ = newenv;

    return 0;
}
