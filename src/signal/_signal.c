/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _signal.c,v 1.3 1993/11/13 06:34:16 mura Exp $
 */

/* System headers */
#include <signal.h>
#include <string.h>
#include <sys/xsignal.h>

/* Functions */
int _signal (einfo_t *info)
{
    int sig;
    void (*function) (int);

    /* エラー種別によって選別 */
    switch (info->code) {

    case ERR_DIVISION_BY_ZERO:
    case ERR_CHK_EXECUTION:
    case ERR_TRAPV_EXECUTION:
    case ERR_USERSIG_FPE:
	sig = SIGFPE;
	break;

    case ERR_ILLEGAL_INSTRUCTION:
    case ERR_PRIVINTR_VIOLATION:
    case ERR_USERSIG_ILL:
	sig = SIGILL;
	break;

    case ERR_UNDEFINED_INTERRUPT:
    case ERR_UNDEFINED_IOCSCALL:
    case ERR_UNDEFINED_LINE_F:
    case ERR_UNDEFINED_DOSCALL:
    case ERR_USERSIG_EMT:
	sig = SIGEMT;
	break;

    case ERR_BUS_ERROR:
    case ERR_USERSIG_SEGV:
	sig = SIGSEGV;
	break;

    case ERR_NMI:
    case ERR_USERSIG_KILL:
	sig = SIGKILL;
	break;

    case ERR_ADDRESS_ERROR:
    case ERR_USERSIG_BUS:
	sig = SIGBUS;
	break;

    case ERR_USERSIG_ABRT:
	sig = SIGABRT;
	break;

    case ERR_USERSIG_TERM:
	sig = SIGTERM;
	break;

    case ERR_USERSIG_INT:
	sig = SIGINT;
	break;

    case ERR_USERSIG_ALRM:
	sig = SIGALRM;
	break;

    case ERR_USERSIG_STOP:
	sig = SIGSTOP;
	break;

    case ERR_USERSIG_USR1:
	sig = SIGUSR1;
	break;

    case ERR_USERSIG_USR2:
	sig = SIGUSR2;
	break;

    case ERR_INVALID_UNIT:
    case ERR_DRIVE_NOT_READY:
    case ERR_INVALID_DEVICE_COMMAND:
    case ERR_CRC_ERROR:
    case ERR_BROKEN_FAT:
    case ERR_SEEK_ERROR:
    case ERR_INVALID_MEDIA:
    case ERR_SECTOR_NOT_FOUND:
    case ERR_PRINTER_OFFLINE:
    case ERR_WRITE_ERROR:
    case ERR_READ_ERROR:
    case ERR_UNKNOWN_ERROR:
    case ERR_WRITE_PROTECT_FIXED:
    case ERR_WRITE_PROTECT:

	/* ハンドラが設定されていなければ元のベクタへ */
	if(_harderr_handler == 0)
	    return _TE_OLDVEC;

	/* ハードエラーハンドラを呼び出す */
	(*_harderr_handler) (info->mode, info->code, info->must);

	/* ハードエラーハンドラから return されたら DOS に戻る */
	return _TE_ABORT;

    default:

	/* それ以外は -1 */
	return -1;

    }

    /* 処理関数のアドレスを求める */
    function = _sigactions[sig].sa_handler;

    /* SIG_IGN ならば無視 */
    if (function == SIG_IGN)
	return _TE_RETRY;

    /* SIG_DOS ならば Human68k 内部の処理ルーチンに進む */
    if (function == SIG_DOS)
	return _TE_OLDVEC;

    /* シグナルを保留する */
    _sigpendingset |= (1 << sig);

    /* エラー情報を保存する */
    _sigpendinginfo[sig] = *info;

    /* シグナルを dispatch する */
    while (_sigdispatch () >= 0);

    /* 再実行 */
    return _TE_RETRY;
}
