/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _sx_rinit.c,v 1.1 1993/10/06 16:51:56 mura Exp $
 */

/* System headers */
#include <string.h>
#include <sys/xstart.h>

/* Functions */
void **_sx_rinit (void)
{
    char **databuf_top_h;
    char *databuf_top;
    size_t rdata_sz, rbss_sz, rldata_sz, rlbss_sz;
    size_t rdata_top, rbss_top, rldata_top, rlbss_top;
    size_t databuf_sz;

    /* サイズ計算 */
    rdata_sz = __size_info.rdata;
    rbss_sz = __size_info.rbss + __size_info.rcomm + __size_info.rstack;
    rldata_sz = __size_info.rldata;
    rlbss_sz = __size_info.rlbss + __size_info.rlcomm + __size_info.rlstack;

    /* オフセット計算 */
    rdata_top = 0;
    rbss_top = rdata_top + rdata_sz;
    rldata_top = rbss_top + rbss_sz;
    rlbss_top = rldata_top + rldata_sz;

    /* データエリアを確保 */
    databuf_sz = rdata_sz + rbss_sz + rldata_sz + rlbss_sz;
    if ((databuf_top_h = (char **) MMChHdlNew (databuf_sz)) == 0)
	return 0;

    /* ??? */
    MMHdlLock ((void **) databuf_top_h);

    /* ??? */
    databuf_top = *databuf_top_h;

    {
	char *data_top;
	unsigned int i, offset;
	unsigned int *offset_table;

	/* rdata の先頭を計算 */
	data_top = (char *) &__size_info + __size_info.data;

	/* task 毎の rdata_sec に、rdata から rdata_sz 分だけ転送 */
	memcpy (databuf_top + rdata_top, data_top, rdata_sz);

	/* task 毎の rbss_sec を、rbss_sz 分だけクリア */
	bzero (databuf_top + rbss_top, rbss_sz);

	/* task 毎の rldata_sec に、rldata から rldata_sz 分だけ転送 */
	memcpy (databuf_top + rldata_top, data_top + rdata_sz, rldata_sz);

	/* task 毎の rbss_sec を、rbss_sz 分だけクリア */
	bzero (databuf_top + rlbss_top, rlbss_sz);

	/* offset を実アドレスに調整 */
	offset = (unsigned int) databuf_top + 0x8000;

	/* ??? */
	offset_table = (unsigned int *) (data_top + rdata_sz + rldata_sz);
	for (i = __size_info.roffset / 4; i > 0; i--)
	    *(unsigned int *) (databuf_top + *offset_table++) += offset;
    }

    /* ポインタを返す */
    return (void **) databuf_top_h;
}
