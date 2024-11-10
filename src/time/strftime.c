/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: strftime.c,v 1.2 1994/11/26 15:08:10 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

/*
** ロケールをサポートするようになればこれらの文字列も置換することになる
** だろう
*/

/* File scope variables */
static char *days[] =
{
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

/* File scope variables */
static char *months[] =
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

/* File scope variables */
static int count;
static char *strptr;

/* File scope functions */
static void form (const char *format, ...)
{
    int c, val;
    char *ptr;
    struct tm *tm;
    va_list ap;

#define STORE(c) if (count-- > 0) *strptr++ = (c); else return

    /* 可変長引数取り出し開始 */
    va_start (ap, format);

    /* フォーマット解析 */
    while (c = *format++) {

	/* % かどうか */
	if (c == '%') {

	    /* フォーマット文字で分類 */
	    switch (*format++) {

	    case '%':				/* % */
		STORE ('%');
		break;

	    case 's':				/* 文字列 */
		ptr = va_arg (ap, char *);
	    strout:
		while (count-- > 0 && (*strptr++ = *ptr++));
		count++;
		strptr--;
		break;

	    case 'z':				/* タイムゾーン */
		tm = va_arg (ap, struct tm *);
		ptr = tm->tm_zone;
		goto strout;

	    case 'n':				/* 先頭 3 文字 */
		ptr = va_arg (ap, char *);
		STORE (ptr[0]);
		STORE (ptr[1]);
		STORE (ptr[2]);
		break;

	    case 't':				/* AM/PM */
		tm = va_arg (ap, struct tm *);
		STORE (tm->tm_hour < 12 ? 'A' : 'P');
		STORE ('M');
		break;

	    case 'c':				/* 1 文字 */
		val = va_arg (ap, int);
		STORE (val);
		break;

	    case 'a':				/* 12 時間制 2 桁 */
		val = va_arg (ap, int);
		if (val == 0) val = 12;
		if (val > 12) val -= 12;
		goto two;

	    case '2':				/* 2 桁 */
		val = va_arg (ap, int);
		goto two;

	    case '3':				/* 3 桁 */
		val = va_arg (ap, int);
		goto three;

	    case '4':				/* 4 桁 */
		val = va_arg (ap, int);
		STORE (val / 1000 + '0');
		val %= 1000;
	    three:
		STORE (val / 100 + '0');
		val %= 100;
	    two:
		STORE (val / 10 + '0');
		STORE (val % 10 + '0');
		break;

	    case 'w':				/* 第何週 (月曜が 0) */
		tm = va_arg (ap, struct tm *);
		val = tm->tm_wday - 1;
		if (val < 0) val = 6;
		goto week;

	    case 'u':				/* 第何週 (日曜が 0) */
		tm = va_arg (ap, struct tm *);
		val = tm->tm_wday;
	    week:
		val = tm->tm_yday - val;
		val = (val <= 0) ? 0 : (val / 7 + ((val % 7) != 0));
		goto two;

	    }
	}

	/* それ以外はそのまま出す */
	else {
	    STORE (c);
	}

    }

    /* 可変長引数取り出し終わり */
    va_end (ap);
}

/* Functions */
size_t strftime (char *string, size_t maximum, const char *format, const struct tm *tm)
{
    /* 長さ 1 未満の場合の処理 */
    if (maximum < 1)
	return 0;

    /* タイムゾーン再計算 */
    tzset ();

    /* ポインタ、カウンタ初期化 */
    strptr = string;
    count = maximum;

    /* 全て処理するまでループ */
    do {

	/* % かどうか */
	if (*format != '%') {

	    /* その文字を出力する */
	    form ("%c", *format);

	}
	else {

	    /* フォーマット文字で分類 */
	    switch (*++format) {

	    case '\0':
	    case '%':
		form ("%%");
		break;

	    case 'n':
		form ("\n");
		break;

	    case 't':
		form ("\t");
		break;

	    case 'H':
		form ("%2", tm->tm_hour);
		break;

	    case 'I':
		form ("%a", tm->tm_hour);
		break;

	    case 'M':
		form ("%2", tm->tm_min);
		break;

	    case 'r':
		form ("%a:%2:%2 %t", tm->tm_hour, tm->tm_min, tm->tm_sec, tm);
		break;

	    case 'p':
		form ("%t", tm);
		break;

	    case 'S':
		form ("%2", tm->tm_sec);
		break;

	    case 'T':
	    case 'X':
		form ("%2:%2:%2", tm->tm_hour, tm->tm_min, tm->tm_sec);
		break;

	    case 'Z':
		form ("%z", tm);
		break;

	    case 'a':
		form ("%n", days[tm->tm_wday]);
		break;

	    case 'A':
		form (days[tm->tm_wday]);
		break;

	    case 'b':
	    case 'h':
		form ("%n", months[tm->tm_mon]);
		break;

	    case 'B':
		form (months[tm->tm_mon]);
		break;

	    case 'c':
		form ("%n %n %2 %2:%2:%2 %z %4",
		      days[tm->tm_wday], months[tm->tm_mon],
		      tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec,
		      tm, tm->tm_year + 1900);
		break;

	    case 'd':
		form ("%2", tm->tm_mday);
		break;

	    case 'D':
		form ("%2/%2/%2", tm->tm_year % 100, tm->tm_mon + 1, tm->tm_mday);
		break;

	    case 'x':
		form ("%2/%2/%2", tm->tm_mon + 1, tm->tm_mday, tm->tm_year % 100);
		break;

	    case 'j':
		form ("%3", tm->tm_yday + 1);
		break;

	    case 'm':
		form ("%2", tm->tm_mon + 1);
		break;

	    case 'U':
		form ("%u", tm);
		break;

	    case 'w':
		form ("%c", tm->tm_wday + '0');
		break;

	    case 'W':
		form ("%w", tm);
		break;

	    case 'y':
		form ("%2", tm->tm_year % 100);
		break;

	    case 'Y':
		form ("%4", tm->tm_year + 1900);
		break;

	    default:
		form ("%c", *format);
		break;
	    }

	}

    } while (*++format && count > 0);

    /* バッファが足りない */
    if (count <= 0)
	return 0;

    /* 最後に null を入れる */
    *strptr = '\0';

    /* バイト数を返す */
    return maximum - count;
}
