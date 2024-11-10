/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _ctors.c,v 1.1.1.1 1993/04/18 16:21:33 mura Exp $
 */

/* System headers */
#include <sys/xstart.h>

/* Macros */
#define _CTOR_LEAD  0x4afc
#define _CTOR_TRAIL 0x432b
#define _DTOR_LEAD  0x4afc
#define _DTOR_TRAIL 0x432d

/* File scope functions */
static void _srchmagic (unsigned short lead, unsigned short trail)
{
    unsigned short *ptr;
    void (*funcptr) (void);

    /* ポインタを初期化する */
    ptr = (unsigned short *) _psta;

    /* テキスト領域の終わりまで magic code を検索する */
    while (ptr < (unsigned short *) _dsta) {

	/* leading word 1 を探す */
	if (*ptr++ != lead)
	    continue;

	/* leading word 2 を探す */
	if (*ptr++ != lead)
	    continue;

	/* leading word 3 を探す */
	if (*ptr++ != lead)
	    continue;

	/* leading word 4 を探す */
	if (*ptr++ != lead)
	    continue;

	/* leading word 5 を探す */
	if (*ptr++ != lead)
	    continue;

	/* trailing word 1 を探す */
	if (*ptr++ == trail) {

	    /* funcptr を取り出す */
	    funcptr = (void (*) (void)) *((int *) ptr)++;

	    /* 関数呼び出し */
	    (*funcptr) ();

	}
    }
}

/* Functions */
void _ctors (void)
{
    /* グローバルコンストラクタ呼び出し */
    _srchmagic (_CTOR_LEAD, _CTOR_TRAIL);
}

/* Functions */
void _dtors (void)
{
    /* グローバルデストラクタ呼び出し */
    _srchmagic (_DTOR_LEAD, _DTOR_TRAIL);
}
