/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: utime.c,v 1.4 1993/05/01 03:47:37 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <alloca.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <utime.h>
#include <limits.h>
#include <sys/dos.h>
#include <sys/xglob.h>

/* Structures and unions */
typedef union {
    struct {
	unsigned year:7;
	unsigned mon:4;
	unsigned day:5;
	unsigned hour:5;
	unsigned min:6;
	unsigned sec:5;
    } field;
    int dat;
} datetime_t;

/* Functions */
int utime (const char *path, struct utimbuf *times)
{
    int pos;
    int fd, status;
    int chgflag = 0;
    dosmode_t mode = 0;
    datetime_t datetime;
    struct tm *tmbuf;
    char name[PATH_MAX + 1];

    /* times が NULL なら領域を確保して現時刻を代入する */
    if (times == 0) {
	times = alloca (sizeof (struct utimbuf));
	times->modtime = time (0);
    }

    /* times が指定されている場合は値をチェックする */
    else if (times->modtime < 0) {
	errno = EINVAL;
	return -1;
    }

    /* フルパスに展開 */
    _fullentry (name, path, sizeof name);

    /* 最後の位置 */
    pos = strlen (name) - 1;

    /* 最後が . か? */
    if (name[pos] == '.') {

	/* 最後が ～/. か? */
	if (name[pos - 1] == '/')
	    name[(name[pos - 2] != ':' ? pos - 1 : pos)] = '\0';

	/* 最後が ～/.. か? */
	else if (name[pos - 1] == '.' && name[pos - 2] == '/')
	    name[(name[pos - 3] != ':' ? pos - 2 : pos - 1)] = '\0';

    }

    /* 地域時間に変換する */
    tmbuf = localtime (&times->modtime);

    /* DOS ファイル構造の時間に変換する */
    datetime.field.sec = tmbuf->tm_sec >> 1;
    datetime.field.min = tmbuf->tm_min;
    datetime.field.hour = tmbuf->tm_hour;
    datetime.field.day = tmbuf->tm_mday;
    datetime.field.mon = tmbuf->tm_mon + 1;
    datetime.field.year = tmbuf->tm_year - (1980 - 1900);

    /* オープンできなかったら... */
    if ((fd = open (name, O_WRONLY)) < 0) {

	/* ディレクトリあるいはリードオンリーファイル以外はエラー... */
	if ((mode = _dos_chmod (name, -1)) < 0 ||
	    !(_DOS_ISDIR (mode) || (_DOS_IRDONLY & mode))) {
	    errno = _errcnv (fd);
	    return -1;
	}

	/* いったん普通のファイルに */
	_dos_chmod (name, _DOS_IFREG);

	/* もう一度オープン */
	if ((fd = open (name, O_WRONLY)) < 0) {
	    _dos_chmod (name, mode);
	    errno = _errcnv (fd);
	    return -1;
	}

	/* 変更フラグ */
	chgflag = 1;

    }

    /* ファイルの日付と時間を変更する */
    status = _dos_filedate (fd, datetime.dat);

    /* クローズ */
    close (fd);

    /* 変更されていたら元の属性に戻す */
    if (chgflag) {
	_dos_chmod (name, mode);
	errno = 0;
    }

    /* エラーか */
    if (status < 0) {
	errno = _errcnv (status);
	return -1;
    }

    return 0;
}
