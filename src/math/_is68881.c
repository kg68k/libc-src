/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _is68881.c,v 1.2 1993/06/24 17:29:33 mura Exp $
 */

/* System headers */
#include <sys/dos.h>
#include <sys/iocs.h>
#include <sys/xmath.h>

/*
** X68030 Human system work area (super visor)
*/

/* Macros */
#define CPUTYPE() _iocs_b_bpeek ((void *) 0xcbc) /* CPU type */
#define FPUFLAG() _iocs_b_bpeek ((void *) 0xcbd) /* FPU type */
#define MMUFLAG() _iocs_b_bpeek ((void *) 0xcbe) /* MMU type */

/* External functions */
double _f_is68881 (void);
double _fpu_is68881 (void);

/* Functions */
int _is68881 (void)
{
    int ssp;
    double value;
    unsigned short buf;

    /* X68030 か判定 (プロトタイプ 020 機も含む)*/
    if (CPUTYPE () == 0x00) {

	/* Co-Processor I/O がアクセス可能か FPU RESPONSE CIR(R) */
	if(_dos_memcpy ((void *) _FPU_IO, &buf, 2) != 0)
	    return -1;

	/* スーパーバイザーモードへ */
	ssp = _dos_super (0);

	/* 68881 チェック */
	value = _fpu_is68881 ();

	/* ユーザーモードへ */
	if (ssp > 0)
	    _dos_super (ssp);

    }
    else {

	/* フラグチェック */
	if (FPUFLAG () == 0)
	    return -1;

	/* 68881 チェック */
	value = _f_is68881 ();

    }

    /* 戻る */
    return (value == 0.0) ? 1 : 0;
}
