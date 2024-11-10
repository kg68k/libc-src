/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from Seirios.
 * --------------------------------------------------------------------
 * $Id: random.c,v 1.1.1.1 1993/04/18 16:24:40 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <limits.h>

/* Macros */
#define _EXTENDBASE 16
#define _INDEX      55
#define _MID_INDEX  24
#define _SUB_INDEX  (_INDEX - _MID_INDEX)

/* File scope variables */
int randcnt = -1;
unsigned long randtable[_INDEX];
unsigned long randextend[_EXTENDBASE];

/* File scope functions */
void subtractive_method (void)
{
    int n;

    /* subtractive method の演算 */
    for (n = 0; n <= _SUB_INDEX; n++)
	randtable[n] = randtable[n] - randtable[n + _SUB_INDEX];
    for (n = _INDEX - 30; n <= _INDEX; n++)
	randtable[n] = randtable[n] - randtable[n - _MID_INDEX];
}

/* Functions */
unsigned int random (void)
{
    unsigned int i, j;

    /* カウンタが未初期化ならば srandom (1) を発行する */
    if (randcnt < 0)
	srandom (1);

    /* 乱数テーブルの再演算 */
    if (++randcnt >= _INDEX) {
	subtractive_method ();
	randcnt = 0;
    }

    /* pool テーブルからのデータ取り出し */
    j = randtable[randcnt] % _EXTENDBASE;
    i = randextend[j];

    /* 乱数テーブルの再演算 */
    if (++randcnt >= _INDEX) {
	subtractive_method ();
	randcnt = 0;
    }

    /* pool の変更 */
    randextend[j] = randtable[randcnt];

    return i;
}

/* Functions */
unsigned int srandom (unsigned int seed)
{
    int n, index;
    unsigned int temp;
    unsigned int old_seed;
    static unsigned long internal_seed;

    /* シードを保存する */
    old_seed = internal_seed;

    /* テーブルを完全にクリア */
    for (n = 0; n < _INDEX; n++)
	randtable[n] = 0;
    for (n = 0; n < _EXTENDBASE; n++)
	randextend[n] = 0;

    /* シードを設定する */
    randtable[_INDEX - 1] = internal_seed = seed;

    /* 初期設定 */
    temp = 1;

    /* 乱数テーブルの初期化を行なう */
    for (n = 0; n < _INDEX - 1; n++) {
	index = ((_SUB_INDEX * (n + 1)) % _INDEX) - 1;
	randtable[index] = temp;
	temp = seed - temp;
	seed = randtable[index];
    }

    /* subtractive method 適用 */
    for (n = 0; n < 4; n++)
	subtractive_method ();

    /* pool カウンタの初期化 */
    randcnt = _INDEX;

    /* 乱数 pool の初期化 */
    for (n = 0; n < _EXTENDBASE; n++) {
	randextend[n] = randtable[randcnt];
	if (++randcnt > _INDEX) {
	    subtractive_method ();
	    randcnt = 0;
	}
    }

    return old_seed;
}
