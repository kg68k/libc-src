/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _doprnt.c,v 1.6 1994/11/27 13:04:32 mura Exp $
 */

/* System headers */
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
#define DEFAULT_PRECISION 6	/* デフォルトの表示精度 */
#define TMPBUFSIZ 512		/* デフォルトの変換バッファのサイズ */

/* Macros */
#define UPPER_CHARSET "0123456789ABCDEF" /* 大文字 */
#define LOWER_CHARSET "0123456789abcdef" /* 小文字 */

/* Macros */
#define _P_SHRTINT  0x001	/* short integer モード */
#define _P_LONGINT  0x002	/* long integer モード */
#define _P_LLNGINT  0x004	/* long long integer モード */
#define _P_LONGDBL  0x008	/* long double モード */
#define _P_SHARPEXT 0x010	/* # 拡張フォーマットのモード */
#define _P_RUGLEFT  0x020	/* 左詰めモード */
#define _P_ZEROPAD  0x040	/* ゼロ詰めモード */
#define _P_LHEXPFIX 0x080	/* 小文字の16進プレフィクス */
#define _P_UHEXPFIX 0x100	/* 大文字の16進プレフィクス */
#define _P_OCTAPFIX 0x200	/* 8進プレフィクス */
#define _P_BINAPFIX 0x400	/* 2進プレフィクス */

/* Macros */
#define DEDIGIT(x) ((x) - '0')
#define ENDIGIT(x) ((x) + '0')

/* File scope functions */
static char *format_L (unsigned long long uval, int flag,
		       int precision, int base, int *size, char *charset)
{
    char *ptr;
    unsigned int shift, mask;
    unsigned long long udiv;
    static char buffer[64];

    /* 変換用バッファの最後にポインタを移動する */
    ptr = buffer + sizeof buffer;

    /* 基数チェック */
    switch (base) {
    case 2:
	shift = 1;
	mask = 1;
	break;
    case 8:
	shift = 3;
	mask = 7;
	break;
    case 16:
	shift = 4;
	mask = 15;
	break;
    default:
	shift = 0;
	mask = 0;
	break;
    }

    /* 整数を文字列に変換 */
    if (precision != 0) {

	/* 倍精度整数か */
	if (flag & _P_LLNGINT) {

	    /* シフトで計算可能か */
	    if (shift > 0) {
		do {
		    *--ptr = charset[uval & mask];
		    uval = uval >> shift;
		} while (uval > 0ULL);
	    }

	    /* シフトでは計算できない */
	    else {
		do {
		    udiv = uval / base;
		    *--ptr = charset[uval - udiv * base];
		    uval = udiv;
		} while (uval > 0ULL);
	    }

	}

	/* 単精度整数 */
	else {

	    unsigned long udivs;
	    unsigned long uvals;

	    /* 単精度に変換 */
	    uvals = (unsigned long) uval;

	    /* シフトで計算可能か */
	    if (shift > 0) {
		do {
		    *--ptr = charset[uvals & mask];
		    uvals = uvals >> shift;
		} while (uvals > 0UL);
	    }

	    /* シフトでは計算できない */
	    else {
		do {
		    udivs = uvals / base;
		    *--ptr = charset[uvals - udivs * base];
		    uvals = udivs;
		} while (uvals > 0UL);
	    }

	}

    }

    /* 変換後のサイズを設定 */
    *size = buffer + sizeof buffer - ptr;

    /* 文字列の先頭アドレスを返す */
    return ptr;
}

static char *format_F (double dval, int precision,
		       int flag, int *gmode, int *size, char *buffer)
{
    char *t, *p;
    int sign, decimal;
    int dot;

    /* デフォルトの精度を採用 */
    if (precision == -1)
	precision = DEFAULT_PRECISION;

    /* fcvt を用いて文字列に変換する */
    t = buffer;
    p = fcvt (dval, precision, &decimal, &sign);
    dot = 0;

    /* 整数部をコピーする */
    if (decimal > 0) {
	while (decimal-- > 0)
	    *t++ = *p++;
	decimal++;
    }
    else {
	*t++ = '0';
    }

    /* 精度指定があるか # 拡張モードならば小数点を表示する */
    if (precision > 0 || (flag & _P_SHARPEXT)) {
	*t++ = '.';
	dot = 1;
    }

    /* 小数部をコピーする */
    while (precision-- > 0) {
	if ((*t++ = *p++) == 0) {
	    precision++;
	    break;
	}
    }

    /* 精度調整 */
    while (precision-- > 0)
	*t++ = '0';

    /* g-format で # 拡張モードでなければ最後のゼロは取り除く */
    if (dot && gmode && (flag & _P_SHARPEXT) == 0) {
	for (*gmode = 0; t > buffer && *--t == '0'; (*gmode)++);
	if (*t == '.') t--;
	t++;
    }

    /* サイズを計算する */
    *size = t - buffer;

    /* 変換された文字列へのポインタを返す */
    return buffer;
}

/* File scope functions */
static char *format_E (double dval, int precision,
		       int flag, int *gmode, int *size, int fmtch, char *buffer)
{
    char *t, *p;
    char *ptr;
    int dsize, exponent;
    int sign, decimal;

    /* デフォルトの精度を採用 */
    if (precision == -1)
	precision = DEFAULT_PRECISION;

    /* ecvt を用いて文字列に変換する */
    t = buffer;
    p = ecvt (dval, precision + 1, &decimal, &sign);
    exponent = decimal - 1;

    /* 整数部をコピーする */
    *t++ = *p++;

    /* 精度指定があるか # 拡張モードならば小数点をコピーする */
    if (precision > 0 || (flag & _P_SHARPEXT))
      *t++ = '.';

    /* 小数部をコピーする */
    while (precision-- > 0) {
	if ((*t++ = *p++) == 0) {
	    precision++;
	    break;
	}
    }

    /* 精度調整 */
    while (precision-- > 0)
	*t++ = '0';

    /* g-format で # 拡張モードでなければ最後のゼロは取り除く */
    if (gmode && (flag & _P_SHARPEXT) == 0) {
	for (*gmode = 0; t > buffer && *--t == '0'; (*gmode)++);
	if (*t == '.') t--;
	t++;
    }

    /* 指数マークを設定する */
    *t++ = fmtch;

    /* 指数部の符号を設定する */
    if (exponent < 0) {
	exponent = -exponent;
	*t++ = '-';
    }
    else {
	*t++ = '+';
    }

    /* 指数部の絶対値が 10 未満ならばゼロを先頭に加える */
    if (exponent < 10)
	*t++ = '0';

    /* 指数文字列を生成する */
    ptr = format_L (exponent, flag, -1, 10, &dsize, LOWER_CHARSET);

    /* 連結する */
    while (dsize-- > 0)
	*t++ = *ptr++;

    /* 最終的なサイズを計算する */
    *size = t - buffer;

    /* 変換した文字列へのアドレスを返す */
    return buffer;
}

/* File scope functions */
static char *format_G (double dval, int *precisionp,
		       int flag, int *size, int fmtch, char *buffer)
{
    char *p;
    char *ptr;
    int exponent;
    int sign, decimal;
    int precision = *precisionp;
    int zerosup = 0;

    /* デフォルトの精度を採用 */
    if (precision == -1)
	precision = DEFAULT_PRECISION;

    /* 指数部を求める */
    p = ecvt (dval, precision, &decimal, &sign);
    exponent = decimal - 1;

    /* f-format と e-format のどちらにするか選択する */
    if ((exponent >= -4 && exponent < precision) || precision == 0) {
	if (precision != 0)
	    precision -= exponent + 1;
	ptr = format_F (dval, precision, flag, &zerosup, size, buffer);
    }
    else {
	if (precision >= 1) precision--;
	fmtch -= 2;
	ptr = format_E (dval, precision, flag, &zerosup, size, fmtch, buffer);
    }

    /* ゼロサプレスによって精度を下げた場合の変化を反映する */
    if (zerosup > 0)
	*precisionp -= zerosup;

    /* 変換した文字列へのアドレスを返す */
    return buffer;
}

/* File scope functions */
static int format_last (FILE *fp, char *ptr, int flag,
			int sign, int width, int precision, int bodysize)
{
    int n, real_size;
    int string_size;

    /* 文字列の長さを調整する */
    string_size = (bodysize
		   + ((sign) ? 1 : 0)
		   + ((flag & _P_OCTAPFIX) ? 1 : 0)
		   + ((flag & (_P_LHEXPFIX | _P_UHEXPFIX)) ? 2 : 0));

    /* 精度を加味して長さを調整する */
    real_size = (precision > string_size) ? precision : string_size;

    /* 1. 右詰めのための空白を出力する */
    if ((flag & (_P_RUGLEFT | _P_ZEROPAD)) == 0)
	for (n = real_size; n < width; n++)
	    fputc (' ', fp);

    /* 2. 符号を出す */
    if (sign)
	fputc (sign, fp);

    /* 2. あるいは2進8進16進プレフィクス */
    else if (flag & (_P_OCTAPFIX | _P_LHEXPFIX | _P_UHEXPFIX)) {
	fputc ('0', fp);
	if (flag & _P_LHEXPFIX)
	    fputc ('x', fp);
	else if (flag & _P_UHEXPFIX)
	    fputc ('X', fp);
	else if (flag & _P_BINAPFIX)
	    fputc ('b', fp);
    }

    /* 3. 右詰めのためにゼロ詰めを行なう */
    if ((flag & (_P_RUGLEFT | _P_ZEROPAD)) == _P_ZEROPAD)
	for (n = real_size; n < width; n++)
	    fputc ('0', fp);

    /* 4. 精度調整用のゼロ詰めを行なう */
    for (n = string_size; n < precision; n++)
	fputc ('0', fp);

    /* 5. 数値、あるいは文字列本体を出力する */
    for (n = bodysize; n-- > 0; )
	fputc (*ptr++, fp);

    /* 6. 左詰め用の空白調整を行なう */
    if (flag & _P_RUGLEFT)
	for (n = real_size; n < width; n++)
	    fputc (' ', fp);

    /* 出力文字数を返す */
    return (width > real_size) ? width : real_size;
}

/* Functions */
int _doprnt (const char *format, va_list ap, FILE *fp)
{
    char buf;					/* %c 用バッファ */
    char *ptr, *tmp;				/* テンポラリのポインタ */
    int ch;					/* テンポラリの文字 */
    int count;					/* 出力文字数 */
    int flag;					/* 表示モードフラグ */
    int n;					/* テンポラリの数値 */
    int precision;				/* 表示精度 */
    int sign;					/* 符号 */
    int size;					/* 文字列の長さ */
    int width;					/* フィールド幅 */
    double dval;				/* 浮動小数点の値 */
    long long lval;				/* 整数の値 */
    unsigned long long uval;			/* 正の整数の値 */
    const char *fmt;				/* フォーマット解析用 */
    char tmpbuf[TMPBUFSIZ];			/* 文字列処理バッファ */

#define GETARG() \
    ((flag & _P_LLNGINT) ? va_arg (ap, long long) : \
     (flag & _P_SHRTINT) ? va_arg (ap, short) : va_arg (ap, int))

#define UGETARG() \
    ((flag & _P_LLNGINT) ? va_arg (ap, unsigned long long) : \
     (flag & _P_SHRTINT) ? va_arg (ap, unsigned short) : va_arg (ap, unsigned int))

    /* フォーマット文字列を解析する */
    for (fmt = format, count = 0;; fmt++) {

	/* 普通の文字はバイパスする */
	while ((ch = *fmt++) && (ch != '%')) {
	    fputc (ch, fp);
	    count++;
	}

	/* 調整 */
	fmt--;

	/* null に到達したなら、終り */
	if (ch == '\0')
	    return feof (fp) ? EOF : count;

	/* parser 用のフラグを初期化 */
	flag = 0;
	width = 0;
	precision = -1;
	sign = '\0';

    loop:

	/* 次の文字を取り出す */
	switch (*++fmt) {

	case '\0':
	    return feof (fp) ? EOF : count;

	/*
	 * 次のフォーマット文字は、表示モードを指定する....
	 */

	case ' ':
	    /* space モードは + モードを override できない */
	    if (sign == '\0') sign = ' ';
	    goto loop;
	case '#':
	    /* # 拡張表示モード */
	    flag |= _P_SHARPEXT;
	    goto loop;
	case '-':
	    /* 左詰めモード */
	    flag |= _P_RUGLEFT;
	    goto loop;
	case '+':
	    /* + モードは space モードを override できる */
	    sign = '+';
	    goto loop;
	case '0':
	    /* ゼロ詰めモード */
	    if (sign != '-' && precision <= 0) flag |= _P_ZEROPAD;
	    goto loop;
	case 'h':
	    /* 引数は short integer である */
	    flag |= _P_SHRTINT;
	    goto loop;
	case 'l':
	    /* 引数は long int である */
	    flag |= _P_LONGINT;
	    goto loop;
	case 'L':
	    /* 引数は long long int あるいは long double である */
	    flag |= _P_LLNGINT | _P_LONGDBL;
	    goto loop;

	/*
	 * 次のフォーマット文字は精度指定である....
	 */

	case '.':
	    if (*++fmt == '*') {
		n = va_arg (ap, int);
	    }
	    else {
		n = 0;
		while (isdigit (*fmt)) {
		    n = 10 * n + DEDIGIT (*fmt++);
		}
		fmt--;
	    }
	    precision = n;
	    goto loop;

	/*
	 * 次のフォーマット文字はフィールド幅の指定である....
	 */

	case '*':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	    if (*fmt == '*') {
		if ((width = va_arg (ap, int)) < 0) {
		    width = -width;
		    flag |= _P_RUGLEFT;
		}
	    }
	    else {
		n = 0;
		do {
		    n = 10 * n + DEDIGIT (*fmt);
		} while (isdigit (*++fmt));
		width = n;
		fmt--;
	    }
	    goto loop;

	/*
	 * 次のフォーマット文字は値を取り出すためのものである
	 */

	case 'n':
	    if (flag & _P_LONGINT)
		*va_arg (ap, long *) = (long) count;
	    else if (flag & _P_SHRTINT)
		*va_arg (ap, short *) = (short) count;
	    else
		*va_arg (ap, int *) = (int) count;
	    break;

	/*
	 * 16進、8進表示... 及びポインタ形式
	 */

	case 'X':
	    uval = UGETARG ();
	    if ((flag & _P_SHARPEXT) && uval != 0) flag |= _P_UHEXPFIX;
	    ptr = format_L (uval, flag, precision, 16, &size, UPPER_CHARSET);
	    count += format_last (fp, ptr, flag, '\0', width, precision, size);
	    break;

	case 'p':
	    if (precision == -1)
		precision = 8;

	case 'x':
	    uval = UGETARG ();
	    if ((flag & _P_SHARPEXT) && uval != 0) flag |= _P_LHEXPFIX;
	    ptr = format_L (uval, flag, precision, 16, &size, LOWER_CHARSET);
	    count += format_last (fp, ptr, flag, '\0', width, precision, size);
	    break;

	case 'o':
	    uval = UGETARG ();
	    if ((flag & _P_SHARPEXT) && uval != 0) flag |= _P_OCTAPFIX;
	    ptr = format_L (uval, flag, precision, 8, &size, LOWER_CHARSET);
	    count += format_last (fp, ptr, flag, '\0', width, precision, size);
	    break;

	case 'b':
	    uval = UGETARG ();
	    if ((flag & _P_SHARPEXT) && uval != 0) flag |= _P_BINAPFIX;
	    ptr = format_L (uval, flag, precision, 2, &size, LOWER_CHARSET);
	    count += format_last (fp, ptr, flag, '\0', width, precision, size);
	    break;

	/*
	 * 文字表示....
	 */

	case 'c':
	    buf = (char) va_arg (ap, int);
	    count += format_last (fp, &buf, flag, '\0', width, precision, 1);
	    break;

	/*
	 * 整数表示....
	 */

	case 'Z':
	case 'U':
	    flag |= _P_LONGINT;
	case 'u':
	    uval = UGETARG ();
	    ptr = format_L (uval, flag, precision, 10, &size, LOWER_CHARSET);
	    count += format_last (fp, ptr, flag, '\0', width, precision, size);
	    break;

	case 'D':
	case 'I':
	    flag |= _P_LONGINT;
	case 'd':
	case 'i':
	    if ((lval = GETARG ()) < 0) {
		lval = -lval;
		sign = '-';
	    }
	    ptr = format_L (lval, flag, precision, 10, &size, LOWER_CHARSET);
	    count += format_last (fp, ptr, flag, sign, width, precision, size);
	    break;

	/*
	 * 文字列表示....
	 */

	case 's':
	    /* ヌルポインタチェック */
	    if ((ptr = va_arg (ap, char *)) == 0)
		ptr = "(null)";

	strout:
	    /* 表示精度、サイズ調整 */
	    size = (precision < 0) ? strlen (ptr) :
		(tmp = memchr (ptr, '\0', precision)) ? tmp - ptr : precision;

	    /* 出力 */
	    count += format_last (fp, ptr, flag, '\0', width, size, size);
	    break;

	/*
	 * 浮動小数点表示....
	 */

	case 'f':
	case 'g':
	case 'G':
	case 'e':
	case 'E':

	    /* 引数を取り出す */
	    if ((dval = va_arg (ap, double)) < 0.0) {
		dval = -dval;
		sign = '-';
	    }

	    /* 非数 (NaN) 無限大 (inf) チェック */
	    if (isnan (dval)) {
		ptr = "(NaN)";
		precision = -1;
		goto strout;
	    }
	    if (isinf (dval)) {
		ptr = "(Infinity)";
		precision = -1;
		goto strout;
	    }

	    /* 文字列に変換 */
	    if (*fmt == 'f')
		ptr = format_F (dval, precision, flag, 0, &size, tmpbuf);
	    else if (*fmt == 'e' || *fmt == 'E')
		ptr = format_E (dval, precision, flag, 0, &size, *fmt, tmpbuf);
	    else
		ptr = format_G (dval, &precision, flag, &size, *fmt, tmpbuf);

	    /* 出力 */
	    count += format_last (fp, ptr, flag, sign, width, precision, size);
	    break;

	/*
	 * それ以外....
	 */

	default:
	    fputc (*fmt, fp);
	    count++;
	    break;
	}
    }
}
