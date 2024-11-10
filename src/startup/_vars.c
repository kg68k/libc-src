/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _vars.c,v 1.1 1993/06/22 07:19:12 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <limits.h>
#include <sys/xstart.h>
#include <sys/xunistd.h>
#include <sys/xstdio.h>

/* External variables */
char *_comline;					/* コマンドライン */
char **_argv;					/* 引数配列 */
char **_envp;					/* 環境配列 */
char **environ;					/* 現在の環境配列 */
int _argc;					/* 引数の数 */
int _pause;					/* ポーズフラグ */

/* External variables */
struct _handles _fddb[OPEN_MAX];		/* 低水準ファイルハンドル */
struct _stdbuf _iob[FOPEN_MAX];			/* 高水準ファイルポインタ */
