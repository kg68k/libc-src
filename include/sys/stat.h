/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: stat.h,v 1.4 1994/05/02 16:09:53 mura Exp $
 */

#ifndef __sys_stat_h__
#define __sys_stat_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_types_h__
#include <sys/types.h>
#endif

#define S_IXOTH   0001
#define S_IWOTH   0002
#define S_IROTH   0004
#define S_IRWXO   0007
#define S_IXGRP   0010
#define S_IWGRP   0020
#define S_IRGRP   0040
#define S_IRWXG   0070
#define S_IXUSR   0100
#define S_IWUSR   0200
#define S_IRUSR   0400
#define S_IRWXU   0700

#define S_IEXEC   (S_IXOTH | S_IXGRP | S_IXUSR)
#define S_IWRITE  (S_IWOTH | S_IWGRP | S_IWUSR)
#define S_IREAD   (S_IROTH | S_IRGRP | S_IRUSR)

#define S_ISVTX   01000 /* for compatibility */
#define S_ISGID   02000 /* for compatibility */
#define S_ISUID   04000 /* for compatibility */

#define S_IFCHR   0020000
#define S_IFDIR   0040000
#define S_IFBLK   0060000
#define S_IFREG   0100000
#define S_IFLNK   0120000

#if 0
#define S_IFIFO   0010000 /* for compatibility */
#define S_IFSOCK  0140000 /* for compatibility */
#endif

#define S_IRDONLY 00200000 /* extension */
#define S_IFVOL   00400000 /* extension */
#define S_ISYS    01000000 /* extension */
#define S_IHIDDEN 02000000 /* extension */
#define S_IEXBIT  04000000 /* extension */

#define S_IFMT    00170000

#define S_ISBLK(m)    (((m) & S_IFMT) == S_IFBLK)
#define S_ISCHR(m)    (((m) & S_IFMT) == S_IFCHR)
#define S_ISDIR(m)    (((m) & S_IFMT) == S_IFDIR)
#define S_ISLNK(m)    (((m) & S_IFMT) == S_IFLNK)
#define S_ISREG(m)    (((m) & S_IFMT) == S_IFREG)

#if 0
#define S_ISFIFO(m)   (((m) & S_IFMT) == S_IFIFO)
#define S_ISSOCK(m)   (((m) & S_IFMT) == S_IFSOCK)
#endif

#define S_ISEXBIT(m)  ((m) & S_IEXBIT)
#define S_ISHIDDEN(m) ((m) & S_IHIDDEN)
#define S_ISSYS(m)    ((m) & S_ISYS)
#define S_ISVOL(m)    ((m) & S_IFVOL)

struct stat {
    dev_t st_dev;
    ino_t st_ino;
    mode_t st_mode;
    nlink_t st_nlink;
    size_t st_blksize;
    uid_t st_uid;
    gid_t st_gid;
    dev_t st_rdev;
    off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
};

_EXTERN (int_ chmod (const char *, mode_t));
_EXTERN (int_ fchmod (int_, mode_t));
_EXTERN (int_ fstat (int_, struct stat *));
_EXTERN (int_ lstat (const char *, struct stat *));
_EXTERN (int_ mkdir (const char *, mode_t));
_EXTERN (int_ stat (const char *, struct stat *));
_EXTERN (mode_t umask (mode_t));

#endif
