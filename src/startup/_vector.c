/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _vector.c,v 1.2 1993/05/23 10:28:32 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <sys/wait.h>
#include <sys/dos.h>

/* Macros */
#define VECT(x) ((unsigned int *) (0x1800 + ((x) - 0xff00) * 4))

/* Functions */
void _vectormove (void)
{
    int ssp, version;
    unsigned int *vector;
    union wait r;

    /* Human のバージョンチェック */
    version = _dos_vernum () & 0xffff;

    /* バージョン 2.00 以下は使えない */
    if (version <= 0x200) {
	r.w_status = 0;
	r.w_liberror = 1;
	r.w_retcode = ENOSYS;
	_dos_print ("libc: this version of human68k is not supported.\r\n");
	_dos_exit2 (r.w_status);
    }

    /* バージョン 3.00 未満なら dos call ベクタを移動する */
    if (version < 0x300) {

	/* スーパーバイザへ */
	ssp = _dos_super (0);

	/* dos call $ff50～$ff7f */
	for (vector = VECT (0xff50); vector < VECT (0xff80); vector++) {

	    /* 新しいベクタに単純コピー */
	    *(vector + 0x30) = *vector;

	}

	/* 元に戻る */
	if (ssp > 0)
	    _dos_super (ssp);

    }
}
