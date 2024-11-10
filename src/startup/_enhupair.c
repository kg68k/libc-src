/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from sa2c (NIIMI Satoshi).
 * --------------------------------------------------------------------
 * $Id: _enhupair.c,v 1.2 1994/07/27 13:48:05 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <string.h>
#include <sys/xstart.h>

/* Macros */
#define PUT(c)		\
(void) ({		\
    if (q < max)	\
	*q++ = c;	\
    else		\
	return -1;	\
})

/* HUPAIR エンコードする際、どんなクオート文字が適切か */
static __inline int decide_quote (const char *arg)
{
    int ch;

    /* 空引き数はクオート */
    if (*arg == 0)
	return '"';

    /* arg を解析する */
    while (ch = *arg++) {

	/* " があれば ' が適切 */
	if (ch == '"')
	    return '\'';

	/* ' あるいは空白があれば " が適切 */
	if (ch == '\'' || isblank (ch))
	    return '"';

    }

    /* 特に必要なし */
    return 0;
}

/* Functions */
int _enhupair (const char *argv0,
	       char *const *argv, char *cmdline, int bufsiz)
{
    int c, ret, quote;
    char *q;
    const char *arg;
    const char *max;

    /* バッファ終端を計算する */
    q = cmdline;
    max = q + bufsiz - (strlen (argv0) + 1);

    /* コマンドラインの長さ用の領域 */
    PUT ('\0');

    /* argv 配列をパース */
    while (arg = *argv++) {

	/* 適切な「最初の」クオート文字を選択 */
	quote = decide_quote (arg);

	/* クオート文字が必要ならそれを挿入 */
	if (quote)
	    PUT (quote);

	/* 引き数 n をパース */
	while (c = *arg++) {

	    /* quote 文字があらわれた場合 */
	    if (c == quote) {

		/* いったんクオートを閉じて... */
		PUT (quote);

		/* クオート文字を切り替える */
		quote = (c == '"') ? '\'' : '"';

		/* クオートを再開する */
		PUT (quote);

	    }

	    /* c を出力 */
	    PUT (c);

	}

	/* クオート文字が必要ならそれを挿入 */
	if (quote)
	    PUT (quote);

	/* 次の引き数があれば間に空白を入れる */
	if (*argv)
	    PUT (' ');

    }

    /* 最後に EOS を打つ */
    PUT ('\0');

    /* その後に argv0 を入れる */
    strcpy (q, argv0);

    /* cmdline - 8 に #HUPAIR 識別氏を */
    strcpy (cmdline - 8, "#HUPAIR");

    /* コマンドラインの長さを計算 */
    ret = q - 2 - cmdline;

    /* 最大 255 までしか設定できない */
    *cmdline = (ret > 255) ? 255 : ret;

    /* バイト数を返す */
    return ret;
}
