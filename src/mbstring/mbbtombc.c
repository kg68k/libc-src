/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbbtombc.c,v 1.1 1993/11/13 06:33:49 mura Exp $
 */

/* System headers */
#include <ctype.h>
#include <mbstring.h>

/* File scope variables */
static unsigned char ankcnv[] =
    "　！”＃＄％＆’（）＊＋，－．／０１２３４５６７８９：；＜＝＞？"  /* 20-3f */
    "＠ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺ［￥］＾＿"  /* 40-5f */
    "｀ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ｛｜｝～";   /* 60-7e */

static unsigned char katacnv[] =
    "。「」、・ヲァィゥェォャュョッーアイウエオカキクケコサシスセソ"    /* a1-bf */
    "タチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワン゛゜"; /* c0-df */

static unsigned char hiracnv[] =
    "。「」、・をぁぃぅぇぉゃゅょっーあいうえおかきくけこさしすせそ"    /* a1-bf */
    "たちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわん゛゜"; /* c0-df */

/* Functions */
int mbbtombc (int c)
{
    int flag = 0;

    /* ひらがな変換を行うか? */
    if (c & 0x10000) {
	c &= 0xffff;
	flag = 1;
    }

    /* ANK 部分を変換する */
    if (c >= 0x20 && c <= 0x7e) {

	/* インデックスを計算 */
	c = (c - 0x20) << 1;

	/* テーブル変換 */
	c = (ankcnv[c] << 8) + ankcnv[c + 1];

    }

    /* それ以外を変換する */
    else if (c >= 0xa1 && c <= 0xdf) {

	/* インデックスを計算 */
	c = (c - 0xa1) << 1;

	/* テーブル変換 */
	if (flag)
	    c = (hiracnv[c] << 8) + hiracnv[c + 1];
	else
	    c = (katacnv[c] << 8) + katacnv[c + 1];

    }

    /* 変換したコードを返す */
    return c;
}
