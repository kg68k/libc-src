/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _errcnv.c,v 1.2 1993/08/16 13:34:10 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <sys/dos.h>
#include <sys/xglob.h>

/* File scope variables */
static int _doserr_conv[_DOSE_MAX + 1] = {
    0,			/*   0 エラーではない -> 0 */
    ENOENT,		/*  -1 無効なファンクション -> ENOENT */
    ENOENT,		/*  -2 ファイルが見付かりません -> ENOENT */
    ENOENT,		/*  -3 ディレクトリが見付かりません -> ENOENT */
    EMFILE,		/*  -4 オープンファイルが多すぎる -> EMFILE */
    EISDIR,		/*  -5 ディレクトリにである -> EISDIR */
    EBADF,		/*  -6 ハンドルは無効 -> EBADF */
    EFAULT,		/*  -7 メモリ管理領域破壊 -> ENOMEM */
    ENOMEM,		/*  -8 実行にメモリがたりない -> ENOMEM */
    EFAULT,		/*  -9 不正なメモリ管理ポインタ -> EFAULT */
    EFAULT,		/* -10 不正な環境 -> EFAULT */
    ENOEXEC,		/* -11 実行フォーマットエラー -> ENOEXEC */
    EINVAL,		/* -12 不正な引数 -> EINVAL */
    ENOENT,		/* -13 不正なファイル名 -> ENOENT */
    EINVAL,		/* -14 不正なパラメータ -> EINVAL */
    EXDEV,		/* -15 不正なドライブ -> EXDEV */
    ENOTEMPTY,		/* -16 カレントは削除できない -> ENOTEMPTY */
    EPERM,		/* -17 ioctlできないデバイス -> EPERM */
    ENOENT,		/* -18 これ以上見付からない -> ENOENT */
    EACCES,		/* -19 書き込みできないファイル -> EACCES */
    EEXIST,		/* -20 すでに登録されたディレクトリ -> EEXIST */
    ENOTEMPTY,		/* -21 ディレクトリが空でない -> ENOTEMPTY */
    EPERM,		/* -22 リネームできない -> EPERM */
    ENOSPC,		/* -23 ディスクが一杯 -> ENOSPC */
    ENOSPC,		/* -24 ディレクトリが一杯 -> ENOSPC */
    ESPIPE,		/* -25 シークできない -> ESPIPE */
    EPERM,		/* -26 多重 supervisor -> EPERM */
    ENOSYS,		/* -27 未定義 ..... -> ENOSYS */
    ETXTBSY,		/* -28 同名のスレッドが存在する -> ETXTBSY */
    EIO,		/* -29 メッセージが受け取れませんでした -> EIO */
    ESRCH,		/* -30 スレッド番号が異常です -> ESRCH */
    ENOSYS,		/* -31 未定義 ..... -> ENOSYS */
    ENFILE,		/* -32 シェアリングファイル数をオーバー -> ENFILE */
    ENOLCK,		/* -33 ロック違反 -> ENOLCK */
    ENOSYS,		/* -34 未定義 ..... -> ENOSYS */
    ELOOP,		/* -35 シンボリックリンクループ -> ELOOP (拡張) */
    EEXIST,		/* -36 ファイルがすでに存在する -> EEXIST (拡張) */
    ERANGE,		/* -37 バッファオーバー -> ERANGE (拡張) */
    ENOSYS,		/* -38 サポートしていない -> ENOSYS (拡張) */
    EEXIST,		/* -39 すでに存在する? -> EEXIST */
};

/* Functions */
int _errcnv (int dos_error)
{
    /* 対応するエラー番号に変換する */
    return (dos_error > 0 || dos_error < -_DOSE_MAX)
	? 0 : _doserr_conv[-dos_error];
}
