/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Passwd,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: getpwent.c,v 1.1.1.1 1993/04/18 16:20:19 mura Exp $
 */

/* System headers */
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/xpwd.h>

/* Externel variables */
FILE *_pwd_fp;

/* File scope variables */
static char _pwd_dir[PATH_MAX + 1];
static char _pwd_gecos[GECOS_MAX + 1];
static char _pwd_name[PWNAM_MAX + 1];
static char _pwd_passwd[PASS_MAX + 1];
static char _pwd_shell[PATH_MAX + 1];
static struct passwd pwd;

/* Functions */
struct passwd *getpwent (void)
{
    int last;
    char *pos;
    char buffer[256];

    /* ファイルがまだオープンされていなければ... */
    if (_pwd_fp == 0) {
	setpwent ();
	if (_pwd_fp == 0)
	    return 0;
    }

    /* コメントではない部分を 1 行読み込む */
    do {
	if (fgets (buffer, sizeof buffer, _pwd_fp) == 0)
	    return 0;
    } while (*buffer == '#');

    /* 最後の LF は取り除いておく */
    if (buffer[last = strlen (buffer) - 1] == '\n')
	buffer[last] = '\0';

    /* 1st トークンはユーザー名 */
    if ((pos = strtok2 (buffer, ";")) == 0)
	return 0;
    strcpy (_pwd_name, pos);
    pwd.pw_name = _pwd_name;

    /* 2nd トークンはユーザーパスワード */
    if ((pos = strtok2 (0, ";")) == 0)
	return 0;
    strcpy (_pwd_passwd, pos);
    pwd.pw_passwd = _pwd_passwd;

    /* 3rd トークンはユーザー ID */
    if ((pos = strtok2 (0, ";")) == 0)
	return 0;
    pwd.pw_uid = (uid_t) atoi (pos);

    /* 4th トークンはグループ ID */
    if ((pos = strtok2 (0, ";")) == 0)
	return 0;
    pwd.pw_gid = (gid_t) atoi (pos);

    /* 5th トークンは gecos フィールド */
    if ((pos = strtok2 (0, ";")) == 0)
	return 0;
    strcpy (_pwd_gecos, pos);
    pwd.pw_gecos = _pwd_gecos;

    /* 6th トークンはログインディレクトリ */
    if ((pos = strtok2 (0, ";")) == 0)
	return 0;
    strcpy (_pwd_dir, pos);
    pwd.pw_dir = _pwd_dir;

    /* 7th トークンはログインシェル */
    if ((pos = strtok2 (0, ";")) == 0)
	return 0;
    strcpy (_pwd_shell, pos);
    pwd.pw_shell = _pwd_shell;

    return &pwd;
}
