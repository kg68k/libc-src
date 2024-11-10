/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sigrtcsave.c,v 1.3 1993/11/13 06:34:19 mura Exp $
 */

/* System headers */
#include <sys/xsignal.h>

/* Functions */
void _sigrtcsave (int flag)
{
    /* flag が負なら 1Hz (Human68K の Default 値) に設定する */
    if (flag < 0)
	RTC_RESET_CTRL = 0x04;

    /* さもなくばクロックを停止する */
    else
	RTC_RESET_CTRL = 0x0c;
}
