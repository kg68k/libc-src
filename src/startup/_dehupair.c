/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from sa2c (NIIMI Satoshi).
 * --------------------------------------------------------------------
 * $Id: _dehupair.c,v 1.2 1993/08/16 13:34:57 mura Exp $
 */

/* System headers */
#include <string.h>
#include <sys/dos.h>
#include <sys/xstart.h>

/* External variables */
int _hupair;

/* Functions */
int _dehupair (const char *comline, char *com)
{
    int c;
    int ret, inquote;
    char *q;
    const char *p;

    /* 変数を初期化 */
    p = comline;
    q = com;
    ret = 1;
    inquote = 0;

    /* HUPAIR エンコードされているか? */
    _hupair = (strncmp (p - 9, "#HUPAIR", 8) == 0);

    /* 最初のスペースをスキップ */
    while (*p == ' ')
	p++;

    /* コマンドライン終わり? */
    if (*p == '\0') {
	*q++ = '\0';
	*q++ = '\0';
	return 0;
    }

    /* コマンドラインを解析 ... */
    while (c = *p++) {

	/* HUPAIR じゃない場合は \～ シーケンスをチェック */
	if (!_hupair && c == '\\') {

	    /* \' や \" をエスケープする */
	    if (*p == '\'' || *p == '"') {
		*q++ = *p++;
		continue;
	    }

	}

	/* クオート中なら... */
	if (inquote) {

	    /* クオート解除? */
	    if (c == inquote)
		inquote = 0;

	    /* そのままコピー */
	    else
		*q++ = c;

	}

	/* クオート文字か? */
	else if (c == '\'' || c == '"')
	    inquote = c;

	/* 空白文字か? */
	else if (c == ' ') {

	    /* EOS を打つ */
	    *q++ = '\0';

	    /* 連続したスペースをスキップする */
	    while (*p == ' ')
		p++;

	    /* EOS なら終わり */
	    if (*p == '\0')
		goto null_char;

	    /* 引き数カウント */
	    ret++;

	}

	/* 上記以外ならコピー */
	else
	    *q++ = c;

    }

    /* 最後に EOS を打つ */
    *q++ = '\0';

  null_char:

    /* 連続して EOS を打つ */
    *q = '\0';

    /* 引き数の数を返す */
    return ret;
}
