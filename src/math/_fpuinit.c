/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _fpuinit.c,v 1.3 1993/06/24 17:29:28 mura Exp $
 */

/* System headers */
#include <sys/dos.h>

/* Functions */
void _fpuinit (void)
{
    int ssp;

    /* スーパーバイザーへ */
    ssp = _dos_super (0);

    /* finit 実行 */
    asm volatile ("finit");

    /* 元に戻る */
    if(ssp > 0)
	_dos_super (ssp);
}
