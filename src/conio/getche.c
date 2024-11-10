/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getche.c,v 1.3 1994/05/02 16:26:49 mura Exp $
 */

/* System headers */
#include <conio.h>
#include <sys/dos.h>

/* Functions */
int getche (void)
{
    int c;
    extern int _con_pback;

    /* pushback があればそれを使う */
    if (c = _con_pback) {
	_con_pback = 0;
	return c;
    }

    /* キー入力待ち */
    while (_dos_k_keysns () == 0);

    /* コンソールから入力する */
    if ((c = _dos_k_keyinp ()) == 0x03) {

	/* ^C ならばアボート */
	_dos_ctlabort ();

    }

    /* エコーバックする */
    _dos_c_putc (c);

    /* c を返す */
    return c;
}
