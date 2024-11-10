/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from AOI (MAKI aoi).
 * --------------------------------------------------------------------
 * $Id: a_stat.c,v 1.1 1993/06/06 06:05:04 mura Exp $
 */

/* System headers */
#include <audio.h>
#include <sys/iocs.h>

/* Functions */
int a_stat (void)
{
    /* 状態をセンス */
    return _iocs_adpcmsns ();
}
