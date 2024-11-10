/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: tzset.c,v 1.1.1.1 1993/04/18 16:38:38 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/xtime.h>

/* External variables */
char *tzname[2];
int daylight;
long timezone;
long timezone_dst;
long timezone_std;

/* File scope functions */
static int daydigit_get (char *, int);
static int julian_get (int, int, int);
static int monthsday_get (int, int);
static int timezone_set (int);
static int weekofmonths (int, int);
static int zonetime_set (long *);
static struct tm *safe_gmtime (time_t *);
static time_t zonetime_sub (void);

/* File scope variables */
static char *envptr;

/*
** 地方時間に関する情報を環境変数 TZ が取得し、グローバル変数にセット
*/
void tzset (void)
{
    int dstflag = 0;

#define ERROR_CHECK() if (*envptr == '\0') goto bailout

    /*
    ** 環境変数 TZ を取り込みます
    */
    if ((envptr = getenv ("TZ")) == 0) {
	daylight = 0;
	tzname[0] = "JST";
	tzname[1] = "   ";
	timezone_std = timezone_dst = timezone = -9 * 60 * 60;
	return;
    }

    /*
    ** まずタイムゾーンを初期化
    */
    daylight = 0;
    timezone = timezone_dst = timezone_std = 0;

    /*
    ** 最初のフィールド「地域時間帯の名称」を取り出します
    */
    ERROR_CHECK ();
    envptr += timezone_set (0);

    /*
    ** 第２フィールドの「標準時と地方時の差 (単位・時分秒)」を取り出します
    */
    ERROR_CHECK ();
    envptr += zonetime_set (&timezone_std);
    timezone_dst = timezone_std;

    /*
    ** 第３のフィールド「地域時間帯の夏時間帯の名称」を取り出します
    */
    ERROR_CHECK ();
    envptr += timezone_set (1);

    /*
    ** 第４フィールドの「標準時と夏時間の差 (単位・時分秒)」を取り出します
    */
    ERROR_CHECK ();
    envptr += zonetime_set (&timezone_dst);

    /*
    ** 夏時間の開始日時
    */
    ERROR_CHECK ();
    if (*envptr == 'M')
	dstflag = monthsday_get (dstflag, 1);
    else if (*envptr == 'J')
	dstflag = julian_get (dstflag, 1, 1);
    else
	dstflag = julian_get (dstflag, 1, 0);

    /* セパレータチェック */
    ERROR_CHECK ();
    if (*envptr == ',')
	envptr++;

    /*
    ** 夏時間の終了日時
    */
    ERROR_CHECK ();
    if (dstflag == 1) {
	if (*envptr == 'M')
	    dstflag = monthsday_get (dstflag, 0);
	else if (*envptr == 'J')
	    dstflag = julian_get (dstflag, 0, 1);
	else
	    dstflag = julian_get (dstflag, 0, 0);
    }

  bailout:

    /* timezone 設定 */
    timezone = (dstflag) ? timezone_dst : timezone_std;

    /* 夏時間設定 */
    daylight = dstflag;
}

/*
** 静的領域の tm 構造体を破壊しない安全な gmtime
*/
struct tm *safe_gmtime (time_t *timeptr)
{
    struct tm savetm;
    static struct tm localtm;

    /* tm 構造体を保存する */
    savetm = _gmtm;

    /* gmtime を実行する */
    localtm = *gmtime (timeptr);

    /* 保存した tm 構造体を戻す */
    _gmtm = savetm;

    /* コピーしたものを返す */
    return &localtm;
}

/*
** Julian 日付を得る
** 夏時間設定日付時間フィールドの J フォーマットの解析
*/
static int julian_get (int dst, int mode, int julian)
{
    int wk, yday;
    struct tm *timeptr;
    time_t timebuf1, timebuf2;
    char tims[3] = {0, 0, 0};

    /* J をスキップ */
    if (julian)
	envptr++;

    /* Julian 日付を取得 */
    yday = 0;
    while (isdigit (*envptr)) {
	yday = yday * 10 + (*envptr - '0');
	envptr++;
    }

    /* 範囲チェック */
    if (yday < julian || yday > 365)
	return 0;

    /* ポインタ調整 */
    envptr++;

    /* 時間を取得 */
    wk = daydigit_get (tims, 1);

    /* 失敗か? */
    if (wk != 2) {
	tims[0] = 2;
	tims[1] = 0;
	tims[2] = 0;
    }

    /* 現在の地域時間を求める... (固定的である...よくない) */
    timezone = _TZADJUST;
    timebuf1 = time (0) - timezone;
    timeptr = safe_gmtime (&timebuf1);

    /* February 29 の特例処理 */
    if (julian && _isleap (2, timeptr->tm_year + 1970))
	timeptr->tm_yday--;

    /* Julian 日付の時間部分を秒数に... */
    timebuf1 = tims[0] * 3600 + tims[1] * 60 + tims[2];

    /* 地域時間の時間部分を秒数... */
    timebuf2 = timeptr->tm_hour * 3600 + timeptr->tm_min * 60 + timeptr->tm_sec;

    /* 夏時間チェック */
    if ((timeptr->tm_yday > yday) ||
	(timeptr->tm_yday == yday && timebuf2 >= timebuf1))
	return mode;
    else
	return dst;
}

/*
** 夏時間設定日付時間フィールドの M フォーマットの解析
*/
static int monthsday_get (int dst, int mode)
{
    int wk, dstflag;
    struct tm *timeptr;
    time_t timebuf1, timebuf2;
    char days[3] = {0, 0, 0};
    char tims[3] = {0, 0, 0};

    /* M をスキップ */
    envptr++;

    /* 日付を取得 */
    wk = daydigit_get (days, 0);

    /* dstflag の初期値 */
    dstflag = dst;

    /* フィールド数が 2? */
    if (wk == 2) {

	/* スキップして... */
	envptr++;

	/* 時間を取得 */
	wk = daydigit_get (tims, 1);

	/* エラーか? */
	if (wk != 2) {
	    tims[0] = 2;
	    tims[1] = 0;
	    tims[2] = 0;
	}

	/* エラーでなければ... */
	if (days[0] >= 1 && days[0] <= 12 &&
	    days[1] >= 1 && days[1] <= 5 &&
	    days[2] >= 0 && days[2] <= 6) {

	    /* 現在の地域時間を得る */
	    timezone = -32400;
	    timebuf1 = time (0) - timezone;
	    timeptr = safe_gmtime (&timebuf1);

	    /* M 日付の時間部分を秒数に ... */
	    timebuf1 = tims[0] * 3600 + tims[1] * 60 + tims[2];

	    /* 地域時間の時間部分を秒数に ... */
	    timebuf2 = timeptr->tm_hour * 3600 + timeptr->tm_min * 60 + timeptr->tm_sec;

	    /* 指定月を越えている? */
	    if (timeptr->tm_mon > (days[0] - 1))
		dstflag = mode;

	    /* 同じ月? */
	    else if (timeptr->tm_mon == (days[0] - 1)) {

		/* すでに指定週を越えている? */
		if (weekofmonths (timeptr->tm_mday, timeptr->tm_wday) > days[1])
		    dstflag = mode;

		/* 同じ週? */
		else if (weekofmonths (timeptr->tm_mday, timeptr->tm_wday) == days[1]) {

		    /* すでに指定曜日を越えている? */
		    if (timeptr->tm_wday > days[2])
			dstflag = mode;

		    /* 指定時間を越えている? */
		    else if ((timeptr->tm_wday == days[2]) && (timebuf2 >= timebuf1))
			dstflag = mode;

		}

	    }
	}
    }

    /* 夏時間フラグを返す */
    return dstflag;
}

/*
** その月の第何週かを返す (第 1 週からカウント)
*/
static int weekofmonths (int md, int wd)
{
    int temp;

    /* 週を計算 */
    temp = md - wd - 1;
    return (md < wd) ? 1 : (temp / 7) + ((temp % 7) ? 2 : 1);
}

/*
** timezone の設定 ::
**	envptr をサーチし、tzname[mode] にコピーする。設定が無効の
**	場合はデフォルトをセット
*/
static int timezone_set (int mode)
{
    int cnt, len;
    char *mallocptr;

    /* ゾーン名の長さを調べる */
    cnt = 0;
    while (!isdigit (envptr[cnt]) && envptr[cnt] != '-' &&
	   envptr[cnt] != '+' && envptr[cnt] != ',' && envptr[cnt] != ':')
	cnt++;

    /* 0 文字ならば終わり */
    if (cnt == 0)
	return 0;

    /* 31 文字より長くてもそこまで */
    if ((len = cnt) > 31)
	len = 31;

    /* 領域確保 */
    if (tzname[mode] == 0) {
	if ((mallocptr = (char *) malloc (len + 1)) != 0) {
	    strncpy (mallocptr, envptr, len);
	    tzname[mode] = mallocptr;
	    tzname[mode][len] = '\0';
	}
    }

    /* すでにあるバッファにコピー */
    else {
	strncpy (tzname[mode], envptr, len);
	tzname[mode][len] = '\0';
    }

    /* 最後の "," ":" をスキップする */
    if (envptr[cnt] == ',' || envptr[cnt] == ':')
	cnt++;

    /* 進んだバイト数を返す */
    return cnt;
}

/*
** 地域時間と UTC の差を求める ::
**	結果は、zonetime に格納する。
*/
static int zonetime_set (long *zonetime)
{
    int cnt;
    long zone;
    time_t hour, min;
    time_t sec, sign;

    /* カウンタ/符号初期化 */
    cnt = 0;
    sign = 0;

    /* 正負記号を処理 */
    if (*envptr == '-') {
	sign = 1;
	envptr++;
    }
    else if (*envptr == '+') {
	envptr++;
	sign = 0;
    }

    /* 時:分:秒を取得 */
    hour = zonetime_sub ();
    min = (isdigit (*envptr)) ? zonetime_sub (): 0;
    sec = (isdigit (*envptr)) ? zonetime_sub (): 0;

    /* 時差を計算 */
    zone  = (hour < 24 && hour > -24) ? hour * 60 * 60 : -9 * 60 * 60;
    zone += (min < 60 && min > 0) ? min * 60 : 0;
    zone += (sec < 60 && sec > 0) ? sec : 0;
    *zonetime = sign ? -zone : zone;

    /* 最後の "," ":" をスキップする */
    if (*envptr == ',' || *envptr == ':')
	cnt++;

    /* 進んだバイト数を返す (sub で処理した分は除く) */
    return cnt;
}

/*
** 時間フィールドのを変換 ::
**	envptr をサーチし、timeptr の指すアドレスへセットする。
*/
static time_t zonetime_sub (void)
{
    int cnt;
    time_t timeret;
    char temp[5];

    /* 数値の数を計算 */
    cnt = 0;
    while (isdigit (envptr[cnt]))
	cnt++;

    /* 長さが 0 なら終わり */
    if (cnt == 0)
	return 0;

    /* 数値部分をコピー */
    strncpy (temp, envptr, cnt);
    temp[cnt] = '\0';

    /* 整数に変換 */
    timeret = atoi (temp);

    /* ポインタを進める */
    envptr += cnt;

    /* ':' をスキップ */
    if (*envptr == ':')
	envptr++;

    /* 変換結果を返す */
    return timeret;
}

/*
** 日付フィールドを得る ::
**	envptr をサーチし、array 配列にセットする。日付、時間の
**	区別は mode == 0 で日付、mode != 0 で時間
*/
static int daydigit_get (char *array, int mode)
{
    int wk, sep;

    /* セパレータを得る */
    wk = 0;
    sep = (mode == 0) ? '.' : ':';

    /* envptr を調べる */
    while (*envptr) {

	/* 数値を取得 */
	if (isdigit (*envptr))
	    array[wk] = array[wk] * 10 + (*envptr - '0');
	else if (*envptr == sep)
	    wk++;
	else
	    break;

	/* 次の文字へ... */
	envptr++;

    }

    /* フィールド数を返す */
    return wk;
}
