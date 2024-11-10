/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _getmem_size.c,v 1.2 1994/05/02 16:54:19 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <sys/xstart.h>
#include <sys/xstdlib.h>

/*
** malloc でのヒープサイズの既定値。
** malloc の仕様に注意して変更する必要がある。
*/

/* External variables */
size_t _SX_GETMEM_SIZE = 32 * 1024;
