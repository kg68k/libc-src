/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbctombb.c,v 1.1 1993/11/13 06:33:53 mura Exp $
 */

/* System headers */
#include <mbctype.h>
#include <mbstring.h>

/* Macros */
#define D(c) ((c) + 0x30) /* 濁点 */
#define H(c) ((c) - 0x30) /* 半濁点 */

/* Macros */
#define MBC_HIRA_LOW  0x829f
#define MBC_HIRA_HIGH 0x82f1
#define MBC_KATA_LOW  0x8340
#define MBC_KATA_HIGH 0x8396
#define MBC_UPPER_LOW 0x8260
#define MBC_LOWER_LOW 0x8281
#define MBC_DIGIT_LOW 0x824f
#define MBC_PUNC_LOW  0x8140
#define MBC_PUNC_HIGH 0x8197

/* File scope variables */
static unsigned char punccnv[] = {
    ' ', '､', '｡', ',', '.', '･', ':', ';', '?', '!',   0,   0,   0, '`',
      0, '^',   0, '_',   0,   0,   0,   0,   0,   0,   0,   0,   0, 'ｰ',
      0,   0, '/',   0, '~',   0, '|',   0,   0,   0,'\'',   0,'\"', '(',
    ')',   0,   0, '[', ']', '{', '}',   0,   0,   0,   0, '｢', '｣',   0,
      0,   0,   0, '+', '-',   0,   0,   0, '=',   0, '<', '>',   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0, '\\','$',   0,   0, '%', '#',
    '&', '*', '@'
};

static unsigned char kanacnv[] = {
       'ｧ',    'ｱ',    'ｨ',    'ｲ',    'ｩ',    'ｳ',    'ｪ',    'ｴ',    'ｫ',    'ｵ',
       'ｶ', D('ｶ'),    'ｷ', D('ｷ'),    'ｸ', D('ｸ'),    'ｹ', D('ｹ'),    'ｺ', D('ｺ'),
       'ｻ', D('ｻ'),    'ｼ', D('ｼ'),    'ｽ', D('ｽ'),    'ｾ', D('ｾ'),    'ｿ', D('ｿ'),
       'ﾀ', D('ﾀ'),    'ﾁ', D('ﾁ'),    'ｯ',    'ﾂ', D('ﾂ'),    'ﾃ', D('ﾃ'),    'ﾄ',
    D('ﾄ'),    'ﾅ',    'ﾆ',    'ﾇ',    'ﾈ',    'ﾉ',    'ﾊ', D('ﾊ'), H('ﾊ'),    'ﾋ',
    D('ﾋ'), H('ﾋ'),    'ﾌ', D('ﾌ'), H('ﾌ'),    'ﾍ', D('ﾍ'), H('ﾍ'),    'ﾎ', D('ﾎ'),
    H('ﾎ'),    'ﾏ',    'ﾐ',    'ﾑ',    'ﾒ',    'ﾓ',    'ｬ',    'ﾔ',    'ｭ',    'ﾕ',
       'ｮ',    'ﾖ',    'ﾗ',    'ﾘ',    'ﾙ',    'ﾚ',    'ﾛ',      0,    'ﾜ',      0,
         0,    'ｦ',    'ﾝ', D('ｳ'),      0,      0
};

/* Functions */
int mbctombb (int c)
{
    int code;

    /* ひらがなか? */
    if (ismbchira (c)) {

	/* 変換可能ならば変換する */
	if (code = kanacnv[c - MBC_HIRA_LOW])
	    c = code;

    }

    /* かたかなか? */
    else if (ismbckata (c)) {

	/* 変換可能ならば変換する */
	if (code = kanacnv[c - MBC_KATA_LOW - (c > 0x837f ? 1 : 0)])
	    c = code;

    }

    /* 記号か? */
    else if (MBC_PUNC_LOW <= c && c <= MBC_PUNC_HIGH && c != 0x817f) {

	/* 変換可能ならば変換する */
	if (code = punccnv[c - MBC_PUNC_LOW - (c > 0x817f ? 1 : 0)])
	    c = code;

    }

    /* 英大文字か? */
    else if (ismbcupper (c))
	c -= MBC_UPPER_LOW - 'A';

    /* 英小文字か? */
    else if (ismbclower (c))
	c -= MBC_LOWER_LOW - 'a';

    /* 数字か? */
    else if (ismbcdigit (c))
	c -= MBC_DIGIT_LOW - '0';

    /* 濁点、反濁点処理が必要か? */
    if (c >= 0x80) {

	/* 反濁点処理 */
	if (c < 0xa0)
	    c += ('ﾟ' << 8) + 0x30;

	/* 濁点処理 */
	else if (0xdf < c && c < 0xff)
	    c += ('ﾞ' << 8) - 0x30;

    }

    /* 変換したコードを返す */
    return c;
}
