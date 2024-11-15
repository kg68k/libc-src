/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _dtos18.c,v 1.2 1994/11/27 13:05:20 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <sys/xstdlib.h>

/*
** 本関数は浮動小数点を倍精度整数に変換してから文字列にするため、精度的には
** 倍精度整数に格納できる桁数までしか扱うことができない。したがって最高精度
** は18桁である。
*/

/* File scope variables */
static double _pos1[32] = {
    1.0e+17,					/* + 0 */
    1.0e+18,					/* + 1 */
    1.0e+19,					/* + 2 */
    1.0e+20,					/* + 3 */
    1.0e+21,					/* + 4 */
    1.0e+22,					/* + 5 */
    1.0e+23,					/* + 6 */
    1.0e+24,					/* + 7 */
    1.0e+25,					/* + 8 */
    1.0e+26,					/* + 9 */
    1.0e+27,					/* +10 */
    1.0e+28,					/* +11 */
    1.0e+29,					/* +12 */
    1.0e+30,					/* +13 */
    1.0e+31,					/* +14 */
    1.0e+32,					/* +15 */
    1.0e+33,					/* +16 */
    1.0e+34,					/* +17 */
    1.0e+35,					/* +18 */
    1.0e+36,					/* +19 */
    1.0e+37,					/* +20 */
    1.0e+38,					/* +21 */
    1.0e+39,					/* +22 */
    1.0e+40,					/* +23 */
    1.0e+41,					/* +24 */
    1.0e+42,					/* +25 */
    1.0e+43,					/* +26 */
    1.0e+44,					/* +27 */
    1.0e+45,					/* +28 */
    1.0e+46,					/* +29 */
    1.0e+47,					/* +30 */
    1.0e+48,					/* +31 */
};

/* File scope variables */
static double _neg1[32] = {
    1.0e+17,					/* - 0 */
    1.0e+16,					/* - 1 */
    1.0e+15,					/* - 2 */
    1.0e+14,					/* - 3 */
    1.0e+13,					/* - 4 */
    1.0e+12,					/* - 5 */
    1.0e+11,					/* - 6 */
    1.0e+10,					/* - 7 */
    1.0e+9,					/* - 8 */
    1.0e+8,					/* - 9 */
    1.0e+7,					/* -10 */
    1.0e+6,					/* -11 */
    1.0e+5,					/* -12 */
    1.0e+4,					/* -13 */
    1.0e+3,					/* -14 */
    1.0e+2,					/* -15 */
    1.0e+1,					/* -16 */
    1.0e+0,					/* -17 */
    1.0e-1,					/* -18 */
    1.0e-2,					/* -19 */
    1.0e-3,					/* -20 */
    1.0e-4,					/* -21 */
    1.0e-5,					/* -22 */
    1.0e-6,					/* -23 */
    1.0e-7,					/* -24 */
    1.0e-8,					/* -25 */
    1.0e-9,					/* -26 */
    1.0e-10,					/* -27 */
    1.0e-11,					/* -28 */
    1.0e-12,					/* -29 */
    1.0e-13,					/* -30 */
    1.0e-14,					/* -31 */
};

/* File scope variables */
static double _pos2[8] = {
    1.0e+0,					/* 000 */
    1.0e+32,					/* 001 */
    1.0e+64,					/* 010 */
    1.0e+96,					/* 011 */
    1.0e+128,					/* 100 */
    1.0e+160,					/* 101 */
    1.0e+192,					/* 110 */
    1.0e+224,					/* 111 */
};

/* File scope variables */
static double _neg2[8] = {
    1.0e-0,					/* 000 */
    1.0e-32,					/* 001 */
    1.0e-64,					/* 010 */
    1.0e-96,					/* 011 */
    1.0e-128,					/* 100 */
    1.0e-160,					/* 101 */
    1.0e-192,					/* 110 */
    1.0e-224,					/* 111 */
};

/* File scope functions */
static int _cmpd (double x, double y)
{
    unsigned long vx, vy, rc;
    unsigned long *x_ptr = (unsigned long *) &x;
    unsigned long *y_ptr = (unsigned long *) &y;

    /* xの指数ビットを取り出す */
    vx = x_ptr[0] & 0x7FF00000;

    /* yの指数ビットを取り出す */
    vy = y_ptr[0] & 0x7FF00000;

    /* 指数ビットだけで判断する */
    if ((rc = vy - vx) != 0)
	return rc;

    /* xの有効数字の上位ビットを取り出す */
    vx = x_ptr[0] & 0x000FFFFF;

    /* yの有効数字の上位ビットを取り出す */
    vy = y_ptr[0] & 0x000FFFFF;

    /* 上位ビットだけで判断する */
    if ((rc = vy - vx) != 0)
	return rc;

    /* xの有効数字の下位ビットを取り出す */
    vx = x_ptr[1];

    /* yの有効数字の下位ビットを取り出す */
    vy = y_ptr[1];

    /* 最終判断 */
    return vy - vx;
}

/* Functions */
void _dtos18 (double x, int *decpt, int *sign, char *buffer)
{
    short e2;
    int e, n;

    /* 基数2の指数を求める(バイアスなしの状態) */
    e2 = (((unsigned short *) &x)[0] & 0x7FF0U) >> 4;

    /* 指数が0の場合は±0.0チェック */
    if (e2 == 0) {

	unsigned long hi = ((unsigned long *) &x)[0] & 0xFFFFF;
	unsigned long lo = ((unsigned long *) &x)[1];

	/* 有効数字が全部0かどうか */
	if (hi == 0 && lo == 0) {

	    /* 文字列を設定 */
	    buffer[0] = '0';

	    /* NULを設定 */
	    buffer[1] = '\0';

	    /* 小数点位置を計算 */
	    *decpt = 1;

	    /* 符号を計算 */
	    *sign = hi & 0x80000000UL;

	    /* 確定 */
	    return;

	}

    }

    /* 2の指数にバイアスをかけてから10の指数を概算 (approx. log10(2)) */
    e = ((int) ((e2 - 1023) * 77)) >> 8;

    /* 指数が正の場合 */
    if (e >= 0) {

	/* 指数が32より小さい場合はテーブル1から */
	if (e < 32)
	    x *= _neg1[e];

	/* 指数が32より大きい場合はテーブル1,2から */
	else
	    x *= _neg1[e & 31] * _neg2[e >> 5];

    }

    /* 指数が負の場合 */
    else {

	/* 絶対値を計算 */
	n = -e;

	/* 絶対値が32より小さい場合はテーブル1から */
	if (n < 32)
	    x *= _pos1[n];

	/* 絶対値が32より大きい場合はテーブル1,2から */
	else
	    x *= _pos1[n & 31] * _pos2[n >> 5];

    }

    /* スケーリングしすぎた場合は戻す */
    if (_cmpd (1.0e+18, x) >= 0) {
	e++;
	x *= 1.0e-1;
    }

    /* スケーリングし足りない場合は追加 */
    else if (_cmpd (1.0e+17, x) < 0) {
	e--;
	x *= 1.0e+1;
    }

    /* 小数点位置を計算 */
    *decpt = e + 1;

    /* 符号を計算 */
    *sign = ((unsigned char *) &x)[0] & 0x80U;

    /* 文字列に変換 */
    _ulltoa ((unsigned long long) x, buffer);
}
