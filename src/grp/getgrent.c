/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getgrent.c,v 1.1.1.1 1993/04/18 16:17:28 mura Exp $
 */

/* System headers */
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/xglob.h>
#include <sys/xgrp.h>

/* Externel variables */
FILE *_grp_fp;

/* File scope variables */
static char *_grp_memary[ALIAS_MAX + 1];
static char _grp_member[ALIAS_MAX][GRNAM_MAX + 1];
static char _grp_name[GRNAM_MAX + 1];
static char _grp_passwd[PASS_MAX];
static struct group grp;

/* Functions */
struct group *getgrent (void)
{
    int cnt, last;
    char *pos;
    char buffer[256];

    /* ファイルがまだオープンされていなければ... */
    if (_grp_fp == 0) {
	setgrent ();
	if (_grp_fp == 0)
	    return 0;
    }

    /* コメントではない部分を 1 行読み込む */
    do {
	if (fgets (buffer, sizeof buffer, _grp_fp) == 0)
	    return 0;
    } while (*buffer == '#');

    /* 最後の LF は取り除いておく */
    if (buffer[last = strlen (buffer) - 1] == '\n')
	buffer[last] = '\0';

    /* 1st トークンはグループ名 */
    if ((pos = strtok2 (buffer, ";")) == 0)
	return 0;
    strcpy (_grp_name, pos);
    grp.gr_name = _grp_name;

    /* 2nd トークンはグループパスワード */
    if ((pos = strtok2 (0, ";")) == 0)
	return 0;
    strcpy (_grp_passwd, pos);
    grp.gr_passwd = _grp_passwd;

    /* 3rd トークンはグループ ID */
    if ((pos = strtok2 (0, ";")) == 0)
	return 0;
    grp.gr_gid = (gid_t) atoi (pos);

    /* 4th トークンからはグループ名の alias */
    for (cnt = 0; cnt < ALIAS_MAX; cnt++) {

	/* , で区切られた名前を取り出す */
	if ((pos = strtok2 (0, ",")) == 0)
	    break;

	/* alias buffer に登録する */
	strcpy (_grp_member[cnt], pos);
	_grp_memary[cnt] = _grp_member[cnt];

    }

    /* 最後を null ターミネート */
    _grp_memary[cnt] = 0;
    grp.gr_mem = _grp_memary;

    return &grp;
}
