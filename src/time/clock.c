/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: clock.c,v 1.1.1.1 1993/04/18 16:38:21 mura Exp $
 */

/* System headers */
#include <time.h>
#include <sys/iocs.h>
#include <sys/xtime.h>

/* External variables */
clock_t _inclock;

/* Functions */
clock_t clock (void)
{
    clock_t past;

    /* 現在時刻と起動開始時刻との差を求める */
    past = (clock_t) _iocs_ontime () - _inclock;

    /* 負であれば 8640000 を加算する */
    return (past < 0) ? (past + 8640000) : past;
}
