/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _close.c,v 1.1.1.1 1993/04/18 16:38:43 mura Exp $
 */

/* System headers */
#include <string.h>
#include <sys/dos.h>
#include <sys/xunistd.h>

/* Functions */
int _close (int fd)
{
    struct _handles *lp = &_fddb[fd];

    /* もとのデバイスモードに戻す */
    _dos_ioctrlst (fd, lp->iomd);

    /* unlink フラグが立っていればファイルを削除する */
    if (lp->unlink == 1)
	_dos_delete (lp->abspath);

    /* handles 構造体をもとに戻す */
    memset (lp, 0, sizeof (struct _handles));

    /* 戻る */
    return 0;
}
