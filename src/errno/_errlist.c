/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _errlist.c,v 1.5 1994/07/27 13:47:13 mura Exp $
 */

/* System headers */
#include <errno.h>

/* External variables */
__common char *sys_errlist[] = {
    "Unknown error",				/* ERROR */
    "No error",					/* 0 */
    "Domain error",				/* EDOM */
    "Result too large",				/* ERANGE */
    "Arg list too long",			/* E2BIG */
    "Permission denied",			/* EACCES */
    "Resource temporarily unavailable",		/* EAGAIN */
    "Bad file descriptor",			/* EBADF */
    "Resource busy",				/* EBUSY */
    "No child process",				/* ECHILD */
    "Resource deadlock would occur",		/* EDEADLK */
    "File exists",				/* EEXIST */
    "Invalid address",				/* EFAULT */
    "File too large",				/* EFBIG */
    "Interrupted function call",		/* EINTR */
    "Invalid argument",				/* EINVAL */
    "Input/output error",			/* EIO */
    "Is a directory",				/* EISDIR */
    "Too many symbolic links",			/* ELOOP */
    "Too many open files",			/* EMFILE */
    "Too many links",				/* EMLINK */
    "Filename too long",			/* ENAMETOOLONG */
    "Too many files open in system",		/* ENFILE */
    "No such device",				/* ENODEV */
    "No such file or directory",		/* ENOENT */
    "Exec format error",			/* ENOEXEC */
    "No locks available",			/* ENOLCK */
    "Not enough space",				/* ENOMEM */
    "No space left on a device",		/* ENOSPC */
    "Block device required",			/* ENOTBLK */
    "Function not implemented",			/* ENOSYS */
    "Not a directory",				/* ENOTDIR */
    "Directory not empty",			/* ENOTEMPTY */
    "Inappropriate I/O control",		/* ENOTTY */
    "No such device or address",		/* ENXIO */
    "Operation not permitted",			/* EPERM */
    "Broken pipe",				/* EPIPE */
    "Read only file system",			/* EROFS */
    "Invalid seek",				/* ESPIPE */
    "No such process",				/* ESRCH */
    "Text file busy",				/* ETXTBSY */
    "Improper link",				/* EXDEV */
    "Read only device file system",		/* EDEVFS */
};

/* External variables */
__common int sys_nerr = sizeof (sys_errlist) / sizeof (char *);

/* External variables */
__common int errno;
