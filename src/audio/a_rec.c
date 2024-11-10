/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from AOI (MAKI aoi).
 * --------------------------------------------------------------------
 * $Id: a_rec.c,v 1.1 1993/06/06 06:05:00 mura Exp $
 */

/* System headers */
#include <audio.h>
#include <errno.h>
#include <sys/iocs.h>

/* Functions */
void a_rec (void *buffer, int size, int freq, int length)
{
    /* 有効バイト数が指定されていれば、それが優先 */
    if (length != 'NASI' && length < size)
	size = length;

    /* 値チェック */
    if (size <= 0 || freq < 0 || freq > 4) {
	errno = EINVAL;
	return;
    }

    /* 実際に入力する */
    _iocs_adpcminp (buffer, (freq << 8) | 3, size);

    /* 入力が終了するまで待機 */
    while (_iocs_adpcmsns () != 0);
}
