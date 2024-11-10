/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: sleep.c,v 1.2 1993/11/13 06:37:24 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/xunistd.h>

/* Functions */
unsigned int sleep (unsigned int seconds)
{
    /* 一度に 12 時間まで */
    for (; seconds > 43200; seconds -= 43200)
	sleep (43200);

    /* 実際にスリープする */
    return _tsleep (seconds * 100) / 100;
}
