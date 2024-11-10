/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _loadrlm.c,v 1.1.1.1 1993/04/18 16:36:50 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <limits.h>
#include <sys/resource.h>
#include <sys/xstart.h>
#include <sys/xresource.h>

/* External variables */
struct rlimit _limits[RLIM_NLIMITS];

/* File scope functions */
static inline int _import (const char *env)
{
    char *ptr;

    /* 環境変数から数値を取り出す */
    return (ptr = getenv (env)) ? atoi (ptr) : 0;
}

/* Functions */
void _loadrlimits (void)
{
    int i;

    /*
    ** RLIMIT_FSIZE は Human が認識し得る最大パーティションサイズが
    ** 16 GByte であり、クラスタサイズが 256k まで大きくできたとして、
    ** 計算上は 16774144 KByte。
    */

    /* RLIMIT の設定 */
    _limits[RLIMIT_CPU   ].rlim_max = RLIM_INFINITY;
    _limits[RLIMIT_FSIZE ].rlim_max = 16774144 * 1024;
    _limits[RLIMIT_DATA  ].rlim_max = _mmax - _hsta;
    _limits[RLIMIT_STACK ].rlim_max = _stacksize;
    _limits[RLIMIT_CORE  ].rlim_max = _import ("limit_core");
    _limits[RLIMIT_RSS   ].rlim_max = _mmax - (void *) _memcp;
    _limits[RLIMIT_NOFILE].rlim_max = OPEN_MAX;

    /* rlim_cur の初期値は rlim_max の複製 */
    for (i = 0; i < RLIM_NLIMITS; i++)
	_limits[i].rlim_cur = _limits[i].rlim_max;
}
