/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sigparse.c,v 1.1.1.1 1993/04/18 16:20:53 mura Exp $
 */

/* System headers */
#include <sys/dos.h>
#include <sys/xsignal.h>

/* File scope functions */
static int parse_doserror (einfo_t *info)
{
    /* DOSエラーでもなければもう、何が何やら分からない */
    if ((info->code & 0xff00) <= 0 || (info->code & 0xff00) >= 0x8000)
	return -1;

    /* info 構造体を設定 */
    info->mode = TYPE_DOS;
    info->must = info->code >> 12;
    info->pc = 0;
    info->sr = 0;

    /* エラー種別を選択 */
    switch (info->code & 0xff) {

    case S_INVALID_UNIT:
	info->code = ERR_INVALID_UNIT;
	break;
    case S_DRIVE_NOT_READY:
	info->code = ERR_DRIVE_NOT_READY;
	break;
    case S_INVALID_DEVICE_CMD:
	info->code = ERR_INVALID_DEVICE_COMMAND;
	break;
    case S_CRC_ERROR:
	info->code = ERR_CRC_ERROR;
	break;
    case S_BROKEN_FAT:
	info->code = ERR_BROKEN_FAT;
	break;
    case S_SEEK_ERROR:
	info->code = ERR_SEEK_ERROR;
	break;
    case S_INVALID_MEDIA:
	info->code = ERR_INVALID_MEDIA;
	break;
    case S_SECTOR_NOT_FOUND:
	info->code = ERR_SECTOR_NOT_FOUND;
	break;
    case S_PRINTER_OFFLINE:
	info->code = ERR_PRINTER_OFFLINE;
	break;
    case S_WRITE_ERROR:
	info->code = ERR_WRITE_ERROR;
	break;
    case S_READ_ERROR:
	info->code = ERR_READ_ERROR;
	break;
    case S_UNKNOWN_ERROR:
	info->code = ERR_UNKNOWN_ERROR;
	break;
    case S_WRITE_PROTECT_FIXED:
	info->code = ERR_WRITE_PROTECT_FIXED;
	break;
    case S_WRITE_PROTECT:
	info->code = ERR_WRITE_PROTECT;
	break;
    default:
	/* unknown error */
	return -1;
    }

    return 0;
}

/* File scope functions */
static int parse_undeferror (einfo_t *info)
{
    /* info 構造体を設定 */
    info->mode = TYPE_UNDEFINT;
    info->must = 1;

    /* エラー種別を選択 */
    switch (info->code & 0xff00) {

    case S_UNDEFINED_INTERRUPT:
	info->code = ERR_UNDEFINED_INTERRUPT;
	break;
    case S_UNDEFINED_IOCSCALL:
	info->code = ERR_UNDEFINED_IOCSCALL;
	break;
    case S_UNDEFINED_LINE_F:
	info->code = ERR_UNDEFINED_LINE_F;
	break;
    case S_UNDEFINED_DOSCALL:
	info->code = ERR_UNDEFINED_DOSCALL;
	break;
    default:
	/* check dos error trap */
	return parse_doserror (info);
    }

    return 0;
}

/* File scope functions */
static int parse_usererror (einfo_t *info)
{
    /* info 構造体を設定 */
    info->mode = TYPE_SIG;
    info->must = 3;

    /* エラー種別を選択 */
    switch (info->code) {

    case S_ABRT:
	info->code = ERR_USERSIG_ABRT;
	break;
    case S_FPE:
	info->code = ERR_USERSIG_FPE;
	break;
    case S_ILL:
	info->code = ERR_USERSIG_ILL;
	break;
    case S_INT:
	info->code = ERR_USERSIG_INT;
	break;
    case S_SEGV:
	info->code = ERR_USERSIG_SEGV;
	break;
    case S_TERM:
	info->code = ERR_USERSIG_TERM;
	break;
    case S_ALRM:
	info->code = ERR_USERSIG_ALRM;
	break;
    case S_KILL:
	info->code = ERR_USERSIG_KILL;
	break;
    case S_BUS:
	info->code = ERR_USERSIG_BUS;
	break;
    case S_STOP:
	info->code = ERR_USERSIG_STOP;
	break;
    case S_EMT:
	info->code = ERR_USERSIG_EMT;
	break;
    case S_USR1:
	info->code = ERR_USERSIG_USR1;
	break;
    case S_USR2:
	info->code = ERR_USERSIG_USR2;
	break;
    default:
	/* check undefined trap */
	return parse_undeferror (info);
    }

    return 0;
}

/* Functions */
int _sigparse (einfo_t *info)
{
    /* info 構造体を設定 */
    info->mode = TYPE_SYS;
    info->must = 7;

    /* エラー種別を選択 */
    switch (info->code) {

    case S_NMI1:
    case S_NMI2:
	info->mode = TYPE_NMI;
	info->code = ERR_NMI;
	break;

    case S_BUS_ERROR:
	info->code = ERR_BUS_ERROR;
	break;
    case S_ADDRESS_ERROR:
	info->code = ERR_ADDRESS_ERROR;
	break;
    case S_ILLEGAL_INSTRUCTION:
	info->code = ERR_ILLEGAL_INSTRUCTION;
	break;
    case S_DIVISION_BY_ZERO:
	info->code = ERR_DIVISION_BY_ZERO;
	break;
    case S_CHK_EXECUTION:
	info->code = ERR_CHK_EXECUTION;
	break;
    case S_TRAPV_EXECUTION:
	info->code = ERR_TRAPV_EXECUTION;
	break;
    case S_PRIVINTR_VIOLATION:
	info->code = ERR_PRIVINTR_VIOLATION;
	break;
    default:
	/* check user signal trap */
	return parse_usererror (info);
    }

    return 0;
}
