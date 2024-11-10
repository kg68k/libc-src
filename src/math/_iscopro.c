/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _iscopro.c,v 1.4 1993/11/13 06:33:30 mura Exp $
 */

/* System headers */
#include <interrupt.h>
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

/* External variables */
char _havefpu = _FLG_ILCPU;
char _ohavefpu = _FLG_ILCPU;

/* File scope variables */
static volatile int privintr_flag;

/* File scope functions */
static void privilege (void)
{
    /* 割り込みフラグを立てる */
    privintr_flag = 0;

    /* RTE で戻る */
    IRTE ();
}

/* File scope functions */
static int is_mpu68000 (void)
{
    int *old_vec;
    unsigned short sr;

    /* フラグを初期化 */
    privintr_flag = 1;

    /* 特権命令違反ベクタをフックする */
    old_vec = _dos_intvcs (_PRIV_VECTORNO, (void *) privilege);

    /* 68010 ～ 680?0 の特権命令を実行する */
    sr = 0;
    asm volatile ("move.w sr,%0" : "=g" (sr));

    /* 特権命令違反ベクタを元に戻す */
    _dos_intvcs (_PRIV_VECTORNO, old_vec);

    /* スーパーバイザーならエラー */
    if (sr & (1 << 13))
	return -1;

    /* 割り込みフラグを返す */
    return privintr_flag;
}

static int ioflag (int codechk)
{
    int result;
    unsigned short buf;

    /* CPU の種類を調べる Human Version 2.00-2.03 互換用 */
    result = codechk ? (is_mpu68000 () ? 0 : _FLG_ILCPU) : (_FLG_ILCPU);

    /* Co-Processor I/O がアクセス可能か FPU RESPONSE CIR(R) */
    if(_dos_memcpy ((void *) _FPU_IO, &buf, 2) == 0) {

	/* I/O Co-Processor 初期化 */
	_fpuinit();

	/* フラグセット */
	result |= _FLG_IOFPU;

    }

    /* 結果を返す */
    return result;
}

/* Functions */
char _iscopro (void)
{
    /* 内部情報で判定 */
    switch (CPUTYPE ()) {

    case 0 : /* MC68000 (MC68000 - MC68020 (改)) */
	_ohavefpu = ioflag (1);
	break;

    case 1 : /* MC68010 */
	_ohavefpu = ioflag (0);
	break;

    case 2 : /* MC68020 */
    case 3 : /* MC68030 */
    case 4 : /* MC68040 */

	/* FPU なら _FLG_FPU, _FLG_ILCPU を設定 */
	if (FPUFLAG () != 0)
	    _ohavefpu = _FLG_FPU | _FLG_ILCPU;

	/* FPU がないならエラー */
	else
	    _ohavefpu = _FLG_ILCPU;

	break;

    default: /* それ以外 */
	_ohavefpu = _FLG_ILCPU;
	break;

    }

    /* 結果を返す */
    return _ohavefpu;
}
