/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _print.c,v 1.3 1993/11/13 06:33:11 mura Exp $
 */

/*
** この関数は stdio や _fmtout などができるまでの当面のつなぎとして
** 使用するにとどめること。基本的な printf の仕様はサポートしている
** が、桁数等の指定、不動小数点の扱いはできない。あしからず。
**
** 使用できるフォーマット　： %d %s %x %c
*/

/* System headers */
#include <string.h>
#include <stdarg.h>
#include <sys/dos.h>
#include <sys/xglob.h>

/* File scope functions */
static void output (const char *ptr, size_t size)
{
    /* 出力すべき物が残っている限りループ */
    while (size-- > 0)
	_dos_c_putc (*ptr++);
}

/* File scope functions */
static size_t dec (char *buffer, int val, int radix)
{
    int minus = 0;
    char *ptr, temp[256];
    static const char digits[16] = "0123456789abcdef";

    /* ptr の初期化 */
    ptr = temp + sizeof temp;

    /* 最後の EOS を打つ */
    *--ptr = '\0';

    /* 符号を取り出して絶対値に */
    if (val < 0) {
	val = -val;
	minus = 1;
    }

    /* val が正である以上続く */
    do {
	*--ptr = digits[val % radix];
	val /= radix;
    } while (val > 0);

    /* 符号を書き込む */
    if (minus)
	*--ptr = '-';

    /* buffer にコピーする */
    strcpy (buffer, ptr);

    return (size_t) (temp + sizeof temp - 1 - ptr);
}

/* Functions */
void _print (const char *format, ...)
{
    size_t size;
    va_list ap;
    char ch, dat, *p;
    char temp[256];

    /* 引数へのポインタを取り出す */
    va_start (ap, format);

    /* フォーマットを解析する */
    while (ch = *format) {

	/* %～ならばフォーマット出力指定 */
	if (ch == '%') {
	    switch (*++format) {
	    case 'd':
		size = dec (temp, va_arg (ap, int), 10);
		output (temp, size);
		format++;
		break;
	    case 'x':
		size = dec (temp, va_arg (ap, int), 16);
		output (temp, size);
		format++;
		break;
	    case 'c':
		dat = (char) va_arg (ap, int);
		output (&dat, 1);
		format++;
		break;
	    case 's':
		size = strlen (p = va_arg (ap, char *));
		output (p, size);
		format++;
		break;
	    default:
		output (format++, 1);
		break;
	    }
	}
	else {
	    output (format++, 1);
	}

    }

    /* 引数へのポインタを消す */
    va_end (ap);
}
