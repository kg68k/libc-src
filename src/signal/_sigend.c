/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sigend.c,v 1.1.1.1 1993/04/18 16:20:46 mura Exp $
 */

/* System headers */
#include <interrupt.h>
#include <sys/dos.h>
#include <sys/xsignal.h>

/* Functions */
void _sigend (void)
{
    int ssp, level;
    efunc_t *vector;

    /* Supervisor モードへ */
    ssp = _dos_super (0);

    /* 割り込みをすべてマスクする */
    level = intlevel (7);

    /* Alarm clock をもとに戻す */
    _sigrtcsave (-1);

    /* Alarm 割り込みエッジをもとに戻す */
    MFP->aer.alarm = _oldmfp.aer;

    /* Alarm 割り込みイネーブルをもとに戻す */
    MFP->ierb.alarm = _oldmfp.ierb;

    /* Alarm 割り込みマスクをもとに戻す */
    MFP->imrb.alarm = _oldmfp.imrb;

    /* 割り込み処理アドレスをもとに戻す */
    vector = (efunc_t *) ((MFP->vr & 0xf0) * sizeof (efunc_t));
    *vector = _oldrtc;

    /* スプリアス割り込みを戻す */
    if ((int) _oldspr > 0)
	_dos_intvcs (SPURIO_VECTORNO, (void *) _oldspr);

    /* kill_pr ベクタのフックを戻す */
    if ((int) _oldkpr > 0)
	_dos_intvcs (KILLPR_VECTORNO, (void *) _oldkpr);

    /* trap14ベクターを元に戻す */
    if ((int) _olderr > 0)
	_dos_intvcs (TRAP14_VECTORNO, (void *) _olderr);

    /* _dos_ctlabort ベクターを元に戻す */
    if ((int) _oldctl > 0)
	_dos_intvcs (CTLABT_VECTORNO, (void *) _oldctl);

    /* _dos_errabort ベクターを元に戻す */
    if ((int) _oldabt > 0)
	_dos_intvcs (ERRABT_VECTORNO, (void *) _oldabt);

    /* _iocs_abortjob ベクターを設定する */
    if ((int) _oldabj > 0)
	_dos_intvcs (ABRTJB_VECTORNO, (void *) _oldabj);

    /* _dos_exit2 ベクターを設定する */
    if ((int) _oldex2 > 0)
	_dos_intvcs (DEXIT2_VECTORNO, (void *) _oldex2);

    /* dos のブレークチェックを元に戻す */
    _dos_breakck (_oldbrk);

    /* 割り込みマスクレベルをもとに戻す */
    intlevel (level);

    /* Usermdoe へ */
    if (ssp > 0)
	_dos_super (ssp);
}
