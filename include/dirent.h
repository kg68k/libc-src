/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: dirent.h,v 1.6 1994/05/02 16:05:50 mura Exp $
 */

#ifndef __dirent_h__
#define __dirent_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __limits_h__
#include <limits.h>
#endif

#ifndef __sys_types_h__
#include <sys/types.h>
#endif

#ifndef __sys_dos_h__
#include <sys/dos.h>
#endif

#define MAXNAMLEN PATH_MAX

struct dirent {
    ino_t d_ino;
    int_ d_reclen;
    int_ d_namlen;
    off_t d_size;
    mode_t d_mode;
    time_t d_time;
    char d_name[NAME_MAX + 1];
};

struct _dirdesc {
    struct _filbuf filesbuf;
    long loc;
    long filemax;
    struct dirent *dp;
};

typedef struct _dirdesc DIR;

#define rewinddir(p) seekdir ((p), 0)

_EXTERN (DIR *opendir (const char *));
_EXTERN (int_ seekdir (DIR *, long));
_EXTERN (long telldir (DIR *));
_EXTERN (struct dirent *readdir (DIR *));
_EXTERN (void closedir (DIR *));

#endif
