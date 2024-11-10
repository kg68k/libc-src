/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _siginit.c,v 1.3 1993/06/22 07:13:49 mura Exp $
 */

/* System headers */
#include <interrupt.h>
#include <sys/dos.h>
#include <sys/xsignal.h>
#include <sys/xstart.h>

/* Externel variables */
efunc_t _oldabj;
efunc_t _oldabt;
efunc_t _oldctl;
efunc_t _olderr;
efunc_t _oldex2;
efunc_t _oldkpr;
efunc_t _oldspr;
efunc_t _oldrtc;

/* Externel variables */
int _oldbrk;
mfpsave_t _oldmfp;

/* Functions */
void _siginit (void)
{
    int ssp, level;
    efunc_t *vector;

    /* dos のブレークチェック保存する */
    _oldbrk = _dos_breakck (-1);

    /* dos のブレークチェックを全てありにする */
    _dos_breakck (1);

    /* _dos_exit2 ベクターを設定する */
    _oldex2 = _dos_intvcs (DEXIT2_VECTORNO, (void *) _exit);

    /* _iocs_abortjob ベクターを設定する */
    _oldabj = _dos_intvcs (ABRTJB_VECTORNO, (void *) _intabt);

    /* _dos_errabort ベクターを設定する */
    _oldabt = _dos_intvcs (ERRABT_VECTORNO, (void *) _intabt);

    /* _dos_ctlabort ベクターを設定する */
    _oldctl = _dos_intvcs (CTLABT_VECTORNO, (void *) _intctl);

    /* trap14ベクターを設定する */
    _olderr = _dos_intvcs (TRAP14_VECTORNO, (void *) _interr);

    /* _dos_kill_pr ベクタのフックを設定する */
    _oldkpr = _dos_intvcs (KILLPR_VECTORNO, (void *) _intabt);

    /* スプリアス割り込みを無効化する */
    _oldspr = _dos_intvcs (SPURIO_VECTORNO, (void *) _intrte);

    /* Supervisor モードへ */
    ssp = _dos_super (0);

    /* 割り込みをすべてマスクする */
    level = intlevel (7);

    /* Alarm clock を保存 */
    _sigrtcsave (0);

    /* MFP CH0 (GPIP0) 割り込み処理アドレス設定 */
    vector = (efunc_t *) ((MFP->vr & 0xf0) * sizeof (efunc_t));
    _oldrtc = *vector;
    *vector = (efunc_t) _intrtc;

    /* Alarm 割り込みエッジを立ち上がりに設定 */
    _oldmfp.aer = MFP->aer.alarm;
    MFP->aer.alarm = 0;

    /* Alarm 割り込みマスク OFF */
    _oldmfp.imrb = MFP->imrb.alarm;
    MFP->imrb.alarm = 1;

    /* Alarm 割り込みイネーブル ON */
    _oldmfp.ierb = MFP->ierb.alarm;
    MFP->ierb.alarm = 1;

    /* 割り込みマスクレベルをもとに戻す */
    intlevel (level);

    /* Usermode へ */
    if (ssp > 0)
	_dos_super (ssp);
}
