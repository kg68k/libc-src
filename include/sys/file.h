/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: file.h,v 1.2 1993/06/06 06:03:56 mura Exp $
 */

/* for compatibility only */

#ifndef __sys_file_h__
#define __sys_file_h__

#ifndef __fcntl_h__
#include <fcntl.h>
#endif

#define L_SET  0 /* SEEK_SET */
#define L_INCR 1 /* SEEK_CUR */
#define L_XTND 2 /* SEEK_END */

#endif
