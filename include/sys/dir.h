/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: dir.h,v 1.2 1993/06/06 06:03:30 mura Exp $
 */

/* for compatibility only */

#ifndef __sys_dir_h__
#define __sys_dir_h__

#ifndef __dirent_h__
#include <dirent.h>
#endif

/*
** The structure of *direct* is different with *dirent*, but
** I think this difference will cause no problem (except some
** structure members...)
*/
#define direct dirent

#endif
