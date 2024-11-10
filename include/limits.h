/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: limits.h,v 1.4 1993/06/22 07:12:09 mura Exp $
 */

#ifndef __limits_h__
#define __limits_h__

#define CHAR_BIT	   8
#define SCHAR_MAX	   127
#define SCHAR_MIN	   (-SCHAR_MAX - 1)
#define UCHAR_MAX	   255U

#ifdef __CHAR_UNSIGNED__
#define CHAR_MAX	   UCHAR_MAX
#define CHAR_MIN	   0
#else
#define CHAR_MAX	   SCHAR_MAX
#define CHAR_MIN	   SCHAR_MIN
#endif

#define WORD_BIT	   16
#define SHRT_MAX	   32767
#define SHRT_MIN	   (-SHRT_MAX - 1)
#define USHRT_MAX	   65535U

#define LONG_BIT	   32
#define LONG_MAX	   2147483647L
#define LONG_MIN	   (-LONG_MAX - 1)
#define ULONG_MAX	   4294967295UL

#define INT_MAX 	   2147483647
#define INT_MIN 	   (-INT_MAX - 1)
#define UINT_MAX	   4294967295U

#define LONGLONG_BIT	   64
#define LONGLONG_MAX	   9223372036854775807LL
#define LONGLONG_MIN	   (-LONGLONG_MAX - 1)
#define ULONGLONG_MAX	   18446744073709551615ULL

#define MB_LEN_MAX	   2
#define PASS_MAX	   16
#define NZERO		   20

#define _POSIX_ARG_MAX	   4096
#define _POSIX_CHILD_MAX   6
#define _POSIX_LINK_MAX    1
#define _POSIX_MAX_CANON   255
#define _POSIX_MAX_INPUT   255
#define _POSIX_NAME_MAX    22
#define _POSIX_NGROUPS_MAX 0
#define _POSIX_OPEN_MAX    96
#define _POSIX_PATH_MAX    127
#define _POSIX_PIPE_BUF    512

#define ALIAS_MAX	   8
#define GRNAM_MAX	   32
#define PWNAM_MAX	   32
#define GECOS_MAX	   128

#define ATEXIT_MAX	   32
#define ONEXIT_MAX	   8
#define PAGE_SIZE	   4096
#define ARG_MAX 	   _POSIX_ARG_MAX
#define CHILD_MAX	   _POSIX_CHILD_MAX
#define OPEN_MAX	   _POSIX_OPEN_MAX

/* The followings are runtime variable (increasable), but fixed */

#define NGROUPS_MAX	   _POSIX_NGROUPS_MAX
#define LINK_MAX	   _POSIX_LINK_MAX
#define MAX_CANON	   _POSIX_MAX_CANON
#define MAX_INPUT	   _POSIX_MAX_INPUT
#define NAME_MAX	   _POSIX_NAME_MAX
#define PATH_MAX	   _POSIX_PATH_MAX
#define PIPE_BUF	   _POSIX_PIPE_BUF

#endif
