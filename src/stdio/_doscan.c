/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _doscan.c,v 1.7 1994/05/02 16:49:23 mura Exp $
 */

/* System headers */
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/xstdio.h>

/*
** 本関数は全て C locale を前提としてプログラミングされている。現在
** の仕様ではそれ以外のロケールに対応させる事はかなり難しいものにな
** ると思われる。
*/

/*
** 仕様 --- 現在のところ、gcc は long double をサポートしていないので
**	    libc の内部でも一切これについては考慮していない。
*/

/* Macros */
#define _P_SHRTINT  0x001	/* short integer モード */
#define _P_LONGINT  0x002	/* long integer モード */
#define _P_LLNGINT  0x004	/* long long integer モード */
#define _P_NDOUBLE  0x008	/* double モード */
#define _P_LONGDBL  0x010	/* long double モード */
#define _P_UNSIGND  0x020	/* unsigned モード */
#define _P_NOSTORE  0x040	/* 値を取り込まない */

/*
** 以下で失敗時の EOF チェックをあまりおこなっていないが、結果的に失敗する
** ので大丈夫だと思う。
*/

/* Macros */
#define DEDIGIT(x) ((x) - '0')
#define ENDIGIT(x) ((x) + '0')

/* Functions */
static int scanchr (unsigned char *pat, int c, size_t rest)
{
    int p, q;					/* パタン文字 (p は先頭、q は末尾) */

    /* パターン長分だけ回す */
    while (rest--) {

	/* パタン文字列から一文字取り出す */
	p = *pat++;

	/* 最後尾までまだ 2 文字以上あり、かつ次の文字が `-' であるなら文 */
	/* 字の範囲を指定している */
	if (rest >= 2 && *pat == '-') {

	    /* 範囲の終端を取り出す */
	    q = pat[1];

	    /* 念のため、昇順かどうか調べ、範囲をチェックする */
	    if (p < q) {
		if (p <= c && c <= q)
		    return 1;
	    }

	    /* その逆ならば.. */
	    else {
		if (q <= c && c <= p)
		    return 1;
	    }

	    /* マッチしなかったので、ポインタを進めてチェックを継続する */
	    pat += 2;
	    rest -= 2;

	}
	else {

	    /* 通常の場合で、一致していれば 1 を返す */
	    if (p == c)
		return 1;

	}

    }

    /* 文字がパタンにマッチしなかった */
    return 0;
}

/* Functions */
int_ _doscan (const char *format, va_list ap, FILE *fp)
{
    int ch;					/* フォーマットから取り出した文字 */
    int got;					/* ストリームから取り出した文字 */
    int nmatch;					/* マッチした項目数 */
    int exflag;					/* 取り出しフラグ */
    int fwidth;					/* フィールド幅 */
    int n;					/* テンポラリ */
    int base;					/* 基数 */
    int readed;					/* 読み込んだバイト数 */
    int cmlen;					/* チェック用インデックス */
    int gotdig;					/* 数値を得たかどうかのフラグ */
    int reverse;				/* ^ フラグ */
    int eof;					/* EOF フラグ */
    char *ptr;					/* テンポラリポインタ */
    char *stb;					/* テンポラリポインタ */
    char buffer[512];				/* 変換用バッファ */
    double dval;				/* double で受ける時 */
    long val;					/* signed で受けるとき */
    unsigned long uval;				/* unsigned で受ける時 */
    unsigned char *end;				/* [] セットの最後の位置 */
    unsigned char *scanp;			/* scanning ポインタ */
    static char m[] = "0123456789abcdefABCDEF";	/* チェック用配列 */

#define FGETC(p) \
    (readed++, fgetc (p))
#define UNGETC(c, p) \
    (readed--, ungetc ((c), (p)))

    /* カウンタをクリア */
    nmatch = 0;
    readed = 0;
    eof = 0;
    scanp = (unsigned char *) format;

    /* フォーマット文字列を解析 */
    while (ch = *scanp++) {

	/* % ならばフォーマット入力 */
	if (ch == '%') {

	    /* フラグ、フィールド幅を初期化 */
	    exflag = 0;
	    fwidth = -1;

	    /* 次の文字を取り出して調べる */
	    if ((ch = *scanp++) == '\0' || ch == '%')
		goto matchk;

	    /* "*" があるか */
	    if (ch == '*') {
		exflag |= _P_NOSTORE;
		ch = *scanp++;
	    }

	    /* フィールド幅 */
	    if (isdigit (ch)) {
		n = 0;
		do {
		    n = 10 * n + DEDIGIT (ch);
		} while (ch = *scanp++, isdigit (ch));
		fwidth = n;
	    }

	    /* hlL のサイズ指定文字 */
	    if (ch == 'h') {
		exflag |= _P_SHRTINT;
		ch = *scanp++;
	    }
	    else if (ch == 'l') {
		exflag |= _P_LONGINT | _P_NDOUBLE;
		ch = *scanp++;
	    }
	    else if (ch == 'L') {
		exflag |= _P_LLNGINT | _P_LONGDBL;
		ch = *scanp++;
	    }
	    else if (ch == '\0')
		goto bailout;

	    /* c,n,[ 以外は空白をスキップ */
	    if (ch != 'c' && ch != 'n' && ch != '[') {
		for (;;) {
		    if ((got = FGETC (fp)) == EOF) {
			eof = 1;
			break;
		    }
		    if (isspace (got) == 0) {
			UNGETC (got, fp);
			break;
		    }
		}
	    }

	    /* 1 文字で case */
	    switch (ch) {

	    /*
	    ** 数値系...
	    */
	    case 'D':
		exflag |= _P_LONGINT;
	    case 'd':
		base = 10;
		goto snumber;

	    case 'I':
		exflag |= _P_LONGINT;
	    case 'i':
		base = 0;
		goto snumber;

	    case 'o':
		base = 8;
		goto unumber;

	    case 'U':
	    case 'Z':
		exflag |= _P_LONGINT;
	    case 'u':
		base = 10;
		goto unumber;

	    case 'X':
	    case 'x':
	    case 'p':
		base = 16;

	    unumber:

		/* unsigned フラグ設定 */
		exflag |= _P_UNSIGND;

	    snumber:

		/* ポインタを初期化 */
		ptr = buffer;

		/* width が -1 ならば 512 に */
		if (fwidth < 0)
		    fwidth = sizeof (buffer);

		/* 符号を処理 */
		if ((got = FGETC (fp)) == '-' || got == '+') {
		    *ptr++ = got;
		    if (--fwidth <= 0)
			goto intconv;
		    got = FGETC (fp);
		}

		/* 基数に応じて処理 */
		if (got == '0') {
		    *ptr++ = got;
		    if (--fwidth <= 0)
			goto intconv;
		    got = FGETC (fp);
		    if ((got == 'x' || got == 'X') && (base == 0 || base == 16)) {
			base = 16;
			*ptr++ = got;
			if (--fwidth <= 0)
			    goto intconv;
			got = FGETC (fp);
		    }
		    else if (base == 0)
			base = 8;
		}
		else if (base == 0)
		    base = 10;

		/* チェック用のインデックスを求める */
		cmlen = (base == 16) ? 10 + 6 + 6 : base;

		/* 必要な数字をコピー */
		for (;;) {
		    if (got == EOF) {
			eof = 1;
			break;
		    }
		    if (memchr (m, got, cmlen) == 0) {
			UNGETC (got, fp);
			break;
		    }
		    *ptr++ = got;
		    if (--fwidth <= 0)
			break;
		    got = FGETC (fp);
		}

	    intconv:

		/* NULL ターミネート */
		*ptr = '\0';

		/* ストアしない場合はこれで終わり */
		if (exflag & _P_NOSTORE)
		    break;

		/* 空文字列ならばエラー */
		if (ptr == buffer)
		    goto bailout;

		/* unsigned 変換 */
		if (exflag & _P_UNSIGND) {

		    /* 値に変換 */
		    uval = strtoul (buffer, 0, base);

		    /* ストア */
		    if (exflag & _P_LONGINT)
			*va_arg (ap, unsigned long *) = uval;
		    else if (exflag & _P_SHRTINT)
			*va_arg (ap, unsigned short *) = uval;
		    else if (exflag & _P_LLNGINT)
			*va_arg (ap, unsigned long long *) = uval;
		    else
			*va_arg (ap, unsigned int *) = uval;

		}

		/* signed 変換 */
		else {

		    /* 値に変換 */
		    val = strtol (buffer, 0, base);

		    /* ストア */
		    if (exflag & _P_LONGINT)
			*va_arg (ap, long *) = val;
		    else if (exflag & _P_SHRTINT)
			*va_arg (ap, short *) = val;
		    else if (exflag & _P_LLNGINT)
			*va_arg (ap, long long *) = val;
		    else
			*va_arg (ap, int *) = val;

		}

		/* 終わり */
		break;

	    /*
	    ** 浮動小数点系...
	    */
	    case 'E':
	    case 'G':
	    case 'e':
	    case 'f':
	    case 'g':

		/* ポインタを初期化 */
		ptr = buffer;
		gotdig = 0;

		/* width が -1 ならば 512 に */
		if (fwidth < 0)
		    fwidth = sizeof (buffer);

		/* 符号を処理 */
		if ((got = FGETC (fp)) == '-' || got == '+') {
		    *ptr++ = got;
		    if (--fwidth <= 0)
			goto floatconv;
		    got = FGETC (fp);
		}

		/* 整数部を処理 */
		while (isdigit (got)) {
		    *ptr++ = got;
		    gotdig = 1;
		    if (--fwidth <= 0)
			goto floatconv;
		    got = FGETC (fp);
		}

		/* 小数点を処理 */
		if (got == '.') {
		    *ptr++ = got;
		    if (--fwidth <= 0)
			goto floatconv;
		    got = FGETC (fp);
		}

		/* 少数部を処理 */
		while (isdigit (got)) {
		    *ptr++ = got;
		    gotdig = 1;
		    if (--fwidth <= 0)
			goto floatconv;
		    got = FGETC (fp);
		}

		/* e,E ならば指数部も取り込む */
		if (gotdig && (got == 'e' || got == 'E')) {

		    /* 指数文字 */
		    *ptr++ = got;
		    if (--fwidth <= 0)
			goto floatconv;
		    got = FGETC (fp);

		    /* 指数符号 */
		    if (got == '+' || got == '-') {
			*ptr++ = got;
			if (--fwidth <= 0)
			    goto floatconv;
			got = FGETC (fp);
		    }

		    /* 指数部がなければエラー */
		    if (isdigit (got) == 0)
			goto bailout;

		    /* 指数部を処理 */
		    do {
			*ptr++ = got;
			if (--fwidth <= 0)
			    goto floatconv;
			got = FGETC (fp);
		    } while (isdigit (got));
		}

		/* 読みすぎた分を戻す */
		UNGETC (got, fp);

	    floatconv:

		/* NULL ターミネート */
		*ptr = '\0';

		/* 数字を得られなかった場合は終わり */
		if (gotdig == 0)
		    goto bailout;

		/* ストアしない場合はこれで終わり */
		if (exflag & _P_NOSTORE)
		    break;

		/* 値に変換 */
		dval = strtod (buffer, 0);

		if (exflag & _P_NDOUBLE)
		    *va_arg (ap, double *) = dval;
		else if (exflag & _P_LONGDBL)
		    *va_arg (ap, long double *) = dval;
		else
		    *va_arg (ap, float *) = dval;

		/* 終わり */
		break;

	    /*
	    ** 文字...
	    */
	    case 'c':

		/* width が -1 ならば 1 に */
		if (fwidth < 0)
		    fwidth = 1;

		/* 格納先のポインタを決定 */
		stb = ptr = (exflag & _P_NOSTORE) ? buffer : va_arg (ap, char *);

		/* フィールド幅分だけ読み込む */
		while (fwidth--) {
		    if ((got = FGETC (fp)) == EOF) {
			eof = 1;
			break;
		    }
		    *ptr++ = got;
		}

		/* まったく読み込まれなかった場合はエラー */
		if (fwidth >= 0 && ptr == stb)
		    goto bailout;

		/* 終わり */
		break;

	    /*
	    ** 文字列...
	    */
	    case 's':

		/* width が -1 ならば 512 に */
		if (fwidth < 0)
		    fwidth = sizeof (buffer);

		/* 格納先のポインタを決定 */
		stb = ptr = (exflag & _P_NOSTORE) ? buffer : va_arg (ap, char *);

		/* フィールド幅分だけ読み込む */
		while (fwidth--) {
		    if ((got = FGETC (fp)) == EOF) {
			eof = 1;
			break;
		    }
		    if (isspace (got)) {
			UNGETC (got, fp);
			break;
		    }
		    *ptr++ = got;
		}

		/* 成功、失敗に関わらず終端を打つ */
		*ptr = '\0';

		/* まったく読み込まれなかった場合はエラー */
		if (fwidth >= 0 && ptr == stb)
		    goto bailout;

		/* なにか読み込んだ場合は続行 */
		break;

	    /*
	    ** 文字選択セット...
	    */
	    case '[':

		/* フィールド幅 */
		if (fwidth < 0)
		    fwidth = sizeof (buffer);

		/* ポインタ取り出し */
		stb = ptr = (exflag & _P_NOSTORE)
		    ? buffer : va_arg (ap, char *);

		/* ^ 文字の処理 */
		if (*scanp == '^') {
		    scanp++;
		    reverse = 1;
		}
		else
		    reverse = 0;

		/* 直後の ] は ] とはみなさない */
		end = (unsigned char *)
		    strchr ((char *) (*scanp == ']' ? scanp + 1 : scanp), ']');
		if (end == 0)
		    goto bailout;

		/* キャラクタセットの長さを求める */
		cmlen = end - scanp;

		/* 取り込み */
		while (fwidth--) {
		    if ((got = FGETC (fp)) == EOF) {
			eof = 1;
			break;
		    }
		    if ((reverse == 0 && scanchr (scanp, got, cmlen) == 0) ||
			(reverse && scanchr (scanp, got, cmlen))) {
			UNGETC (got, fp);
			break;
		    }
		    *ptr++ = got;
		}
		*ptr = '\0';

		/* 空文字列ならば終わり */
		if (fwidth >= 0 && ptr == stb)
		    goto bailout;

		/* ] の次に移動する */
		scanp = end + 1;
		break;

	    /*
	    ** それ以外...
	    */
	    case 'n':
		if ((exflag & _P_NOSTORE) == 0)
		    *va_arg (ap, int *) = readed;
		exflag |= _P_NOSTORE;
		break;

	    /*
	    ** それ以外はその文字自体
	    */
	    default:
		goto matchk;

	    }

	    /* マッチし、かつ代入した項目数を加算 */
	    if ((exflag & _P_NOSTORE) == 0)
		nmatch++;

	}

	/* 空白文字ならばスキップ */
	else if (isspace (ch)) {

	    /* フォーマット文字の空白部分をまずスキップ */
	    while (isspace (*scanp))
		scanp++;

	    /* ストリームの空白文字を全てスキップする */
	    while ((got = FGETC (fp)) != EOF) {
		if (isspace (got) == 0) {
		    UNGETC (got, fp);
		    break;
		}
	    }

	    /* 終わりならば ... */
	    if (got == EOF)
		break;

	}

	/* それ以外ならばマッチするかどうかチェック */
	else {

	  matchk:

	    /* 1 文字取り出してチェック */
	    if ((got = FGETC (fp)) != ch) {
		UNGETC (got, fp);
		return nmatch;
	    }

	}

    }

  bailout:

    /* 項目数を返す */
    return (eof && (nmatch == 0)) ? EOF : nmatch;
}
