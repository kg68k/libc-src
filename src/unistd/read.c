/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: read.c,v 1.7 1994/11/26 15:11:28 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xunistd.h>

/* Functions */
static int raw_keyboard (int fileno, char *buffer, unsigned int bytes)
{
    int n, rc, md;
    char *p;

    /* モードを取り出す */
    md = _fddb[fileno].oflag;

    /* テキストモードで EOF ならこれにて終わり */
    if ((md & O_TEXT) && (md & O_TXTEOF))
	return 0;

    /* 読めるだけ読む */
    if ((rc = _dos_read (fileno, buffer, bytes)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    /* バイナリモードなら何もしない */
    if (md & O_BINARY)
	return rc;

    /* CR -> LF 変換, ^Z -> EOF 処理 */
    for (n = rc, p = buffer; n--; p++) {

	/* EOF(^Z) にであったら... */
	if (*p == 0x1a) {

	    /* TEXTEOF フラグを設定 */
	    _fddb[fileno].oflag |= O_TXTEOF;
	    break;

	}

	/* CR にであったら... */
	else if (*p == '\r')
	    *p = '\n';

    }

    /* バイト数を求める */
    return p - buffer;
}

/* Functions */
static int cooked_keyboard (int fileno, char *buffer, unsigned int bytes)
{
    int n, rc, md;
    char ch, *rp, *wp;

    /* モードを取り出す */
    md = _fddb[fileno].oflag;

    /* テキストモードで EOF ならこれにて終わり */
    if ((md & O_TEXT) && (md & O_TXTEOF))
	return 0;

    /* 読めるだけ読む */
    if ((rc = _dos_read (fileno, buffer, bytes)) < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    /* バイナリモードなら何もしない */
    if (md & O_BINARY)
	return rc;

    /* 変換用の変数を初期化 */
    n = rc;
    wp = rp = buffer;

    /* CR/LF -> LF 変換, ^Z -> EOF 処理 */
    while (n--) {

	/* EOF(^Z) にであったら... */
	if ((ch = *rp++) == 0x1a) {

	    /* TEXTEOF フラグを設定 */
	    _fddb[fileno].oflag |= O_TXTEOF;
	    break;

	}

	/* CR にであったら... cooked だから必ず CR,LF と続く */
	if (ch == '\r') {

	    /* バッファが空になったら LF を読み出す */
	    if (n == 0) {
		if ((rc = _dos_read (fileno, &ch, 1)) < 0) {
		    errno = _errcnv (rc);
		    return -1;
		}
	    }
	    else {
		ch = *rp++;
		n--;
	    }
	}

	/* データ転送 */
	*wp++ = ch;

    }

    /* バイト数を求める */
    return wp - buffer;

}

/* Functions */
int read (int fileno, char *buffer, unsigned int bytes)
{
    int n, rc;
    int count;
    long position;
    char ch, got;
    char *rp, *wp;

#ifdef EBADF_CHECKER
    /* 不正なファイルハンドルチェック */
    if (_usedfd (fileno) < 0) {
	errno = EBADF;
	return -1;
    }
#endif

    /* 0 バイトなら何も行わない */
    if (bytes <= 0)
	return 0;

    /* キーボードからの読み込み... */
    if (isatty (fileno)) {

	/* cooked/raw の確認 */
	if ((rc = _dos_ioctrlgt (fileno)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

	/* raw デバイス */
	else if (rc & _DEV_RAW)
	    return raw_keyboard (fileno, buffer, bytes);

	/* cooked デバイス */
	else
	    return cooked_keyboard (fileno, buffer, bytes);
    }

    /* バイナリモード時の処理 */
    if (_fddb[fileno].oflag & O_BINARY) {

	/* バイナリモードではただ読むだけ */
	if ((count = _dos_read (fileno, buffer, bytes)) < 0) {
	    errno = _errcnv (count);
	    return -1;
	}

    }
    else {

	/* EOF ならこれにて終わり */
	if (_fddb[fileno].oflag & O_TXTEOF)
	    return 0;

	/* 読めるだけ読む */
	if ((rc = _dos_read (fileno, buffer, bytes)) < 0) {
	    errno = _errcnv (rc);
	    return -1;
	}

	/* 変換用の変数を初期化 */
	n = rc;
	wp = rp = buffer;
	count = 0;

	/* CR/LF -> LF 変換 */
	while (n--) {

	    /* EOF(^Z) にであったら... */
	    if ((ch = *rp++) == 0x1a) {

		/* TEXTEOF フラグを設定 */
		_fddb[fileno].oflag |= O_TXTEOF;
		break;

	    }

	    /* CR にであったら... */
	    if (ch == '\r') {

		/* バッファに余りデータがあるか? */
		if (n) {

		    /* 次が LF であれば CR を抜く */
		    if (*rp == '\n') {
			ch = *rp++;
			n--;
		    }

		}

		/* 余りがなければさらに 1 バイトを読み出して調べる */
		else {

		    /* まず現在位置を記憶 */
		    position = _dos_seek (fileno, 0, 1);

		    /* 1 バイト読みだし */
		    if ((rc = _dos_read (fileno, &got, 1)) < 0) {
			errno = _errcnv (rc);
			return -1;
		    }

		    /* 次が LF ならば CR を抜かす */
		    if (got == '\n')
			ch = got;

		    /* LF じゃなければファイルポインタを戻す */
		    else
			_dos_seek (fileno, position, 0);

		}

	    }

	    /* データ転送 */
	    *wp++ = ch;

	}

	/* バイト数を求める */
	count = wp - buffer;

    }

    /* 戻る */
    return count;
}
