/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: cgets.c,v 1.2 1993/06/22 10:41:21 mura Exp $
 */

/* System headers */
#include <conio.h>
#include <string.h>
#include <sys/dos.h>

/* Functions */
char *cgets (char *buffer)
{
    struct _inpptr in;
    extern int _con_pback;

    /* 入力枠設定 */
    in.max = buffer[0];

    /* コンソール入力 */
    _dos_gets (&in);

    /* ungetch されていればそれも */
    if (_con_pback) {
	buffer[1] = in.length + 1;
	buffer[2] = _con_pback;
	strcpy (buffer + 3, in.buffer);
    }

    /* buffer へ転送 */
    else {
	buffer[1] = in.length;
	strcpy (buffer + 2, in.buffer);
    }

    /* buffer を返す */
    return &buffer[2];
}
