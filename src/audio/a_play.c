/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from AOI (MAKI aoi).
 * --------------------------------------------------------------------
 * $Id: a_play.c,v 1.1 1993/06/06 06:04:57 mura Exp $
 */

/* System headers */
#include <audio.h>
#include <errno.h>
#include <sys/iocs.h>

/* Functions */
void a_play (const void *buffer, int size, int freq, int mode, int length)
{
    /* 有効バイト数が設定されていれば、それが優先 */
    if (length != 'NASI' && length < size)
	size = length;

    /* 値チェック */
    if (size <= 0 || freq < 0 || freq > 4 || mode < 0 || mode > 3) {
	errno = EINVAL;
	return;
    }

    /* 実際に出力する */
    _iocs_adpcmout (buffer, (freq << 8) | mode, size);
}
