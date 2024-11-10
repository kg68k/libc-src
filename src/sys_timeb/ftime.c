/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ftime.c,v 1.2 1994/11/26 15:07:03 mura Exp $
 */

/* System headers */
#include <time.h>
#include <sys/timeb.h>

/* Functions */
void ftime (struct timeb *timeptr)
{
    /* タイムゾーンを再計算 */
    tzset ();

    /* 構造体を設定する */
    timeptr->time = time (0);
    timeptr->millitm = 0;
    timeptr->timezone = timezone / 60;
    timeptr->dstflag = daylight;
}
