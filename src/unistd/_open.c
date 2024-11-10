/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _open.c,v 1.5 1994/11/26 15:09:27 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
int _open (const char *fname, int fd, int mode)
{
    int ssp;
    struct _handles *lp = &_fddb[fd];

    /* 構造体の内容をクリアする */
    memset (lp, '\0', sizeof (struct _handles));

    /* 現在のデバイスのモードを保存 */
    lp->iomd = _dos_ioctrlgt (fd);

    /* スーパーバイザーになって FCB をコピーする */
    ssp = _dos_super (0);
    memcpy (&lp->fcb, _dos_getfcb (fd), sizeof (union _fcb));
    if (ssp > 0) _dos_super (ssp);

    /* handles 構造体を作成する */
    lp->inuse = _FD_APPLICATION;
    lp->unlink = 0;
    lp->oflag = mode;
    lp->cdev = lp->iomd & _DEV_CDEV;

    /* 絶対パス名を記憶 */
    strcpy (lp->abspath, fname);

    /* 戻る */
    return 0;
}
