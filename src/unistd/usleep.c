/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: usleep.c,v 1.2 1993/11/13 06:37:28 mura Exp $
 */

/* System headers */
#include <unistd.h>
#include <sys/xunistd.h>

/* Functions */
unsigned int usleep (unsigned int useconds)
{
    /* 一度に 500 ミリ秒まで */
    for (; useconds > 500000; useconds -= 500000)
	usleep (500000);

    /* 実際にスリープする */
    return _tsleep (useconds / 10000) * 10000;
}
