/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _getleaps.c,v 1.1.1.1 1993/04/18 16:38:14 mura Exp $
 */

/* System headers */
#include <time.h>
#include <sys/xtime.h>

/* Functions */
int _getleaps (int year)
{
    int y1, y2, y3;

    /* 前年までの値を求める */
    year--;

    /*
    ** 1970 年より以前の閏年だった年より何年経過したかを求める。
    ** 1968 年は 4 年に 1 回の閏年。
    */
    y1 = year - 1968;

    /* 1900 年は 100 年に 1 回の閏年でない年 */
    y2 = year - 1900;

    /* 1600 年は 400 年に 1 回の閏年 */
    y3 = year - 1600;

    /* それぞれ、何回あったかを計算する */
    return (y1 / 4 - y2 / 100 + y3 / 400);
}
