/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: open.c,v 1.1.1.1 1993/04/18 16:17:11 mura Exp $
 */

/* System headers */
#include <sys/dos.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* External variables */
int _fmode = O_TEXT;
mode_t _umask;

/* Functions */
int open (const char *fname, int mode, ...)
{
    int fd, dosmode;
    char buf;
    char abspath[PATH_MAX + 1];
    mode_t create;
    va_list ap;

    /* APPEND, TRUNC, CREAT は少なくとも WRITE を必要とする */
    if (mode & (O_TRUNC | O_APPEND | O_CREAT)) {
	if ((mode & (O_WRONLY | O_RDWR)) == 0) {
	    mode &= ~(O_RDONLY | O_WRONLY | O_RDWR);
	    mode |= O_WRONLY;
	}
    }

    /* TEXT, BINARY の指定がない場合に _fmode をデフォルトとする */
    if ((mode & (O_TEXT | O_BINARY)) == 0)
	mode |= _fmode & (O_TEXT | O_BINARY);

    /* human に渡すオープンモード */
    dosmode = (mode & O_RDWR) ? 2 : (mode & O_WRONLY) ? 1 : 0;

    /* 実際にオープンする */
    if ((fd = _dos_open (fname, dosmode)) < 0) {

	/* CREAT じゃなければアウト */
	if ((mode & O_CREAT) == 0) {
	    errno = _errcnv (fd);
	    return -1;
	}

	/* 余分な引数 create を取り出し、アクセスモードマスクをかける */
	va_start (ap, mode);
	create = va_arg (ap, mode_t) & 0777;
	va_end (ap);

	/* umask を適用する */
	create &= ~_umask;
	create |= S_IFREG;

	/* ファイルを作成する */
	if ((fd = _dos_create (fname, _mode2dos (create))) < 0) {
	    errno = _errcnv (fd);
	    return -1;
	}

    }

    /* たとえオープンできても、CREAT & EXCL ならば失敗 */
    else if ((mode & (O_CREAT | O_EXCL)) == (O_CREAT | O_EXCL)) {
	_dos_close (fd);
	errno = EEXIST;
	return -1;
    }

    /* TRUNC ならばファイルを 0 バイトに切り詰める */
    if (mode & O_TRUNC)
	_dos_write (fd, &buf, 0);

    /* APPEND ならばファイルの最後に seek する */
    if ((mode & O_APPEND) && _seekeof (fd, mode) < 0)
	return -1;

    /* フルパスに展開する */
    if (_fullpath (abspath, fname, PATH_MAX) == 0)
	return -1;

    /* _handles 構造体を作成する */
    if (_open (abspath, fd, mode) < 0)
	return -1;

    /* fd を返す */
    return fd;
}
