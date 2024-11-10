/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xunistd.h,v 1.6 1994/11/26 14:49:49 mura Exp $
 */

#ifndef __sys_xunistd_h__
#define __sys_xunistd_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

/*
** shoule be defined when EBADF checker is really needed (normally undefined
** because it's too expensive to check every time.
*/
#undef EBADF_CHECKER

#ifndef __unistd_h__
#include <unistd.h>
#endif

#ifndef __limits_h__
#include <limits.h>
#endif

#ifndef __sys_dos_h__
#include <sys/dos.h>
#endif

#define _FD_NOTUSED     0	/* free file handles */
#define _FD_IMPORTED    1	/* imported file handles */
#define _FD_APPLICATION 2	/* application opened file handles */

struct _handles {		/* exactly 256bytes */
    int_ inuse;
    int_ unlink;
    int_ oflag;
    int_ cdev;
    int_ iomd;
    union _fcb fcb;
    char abspath[PATH_MAX + 1];
    char reserved[12];
};

extern struct _handles _fddb[];

_EXTERN (dosmode_t _mode2dos (mode_t));
_EXTERN (int_ _appfd (int_));
_EXTERN (int_ _close (int_));
_EXTERN (int_ _exec (int_, long, long, long, void *));
_EXTERN (int_ _open (const char *, int_, int_));
_EXTERN (int_ _seekeof (int_, int_));
_EXTERN (int_ _spawn (int_, const char *, char *const argv[], char *const envp[], int_));
_EXTERN (int_ _usedfd (int_));
_EXTERN (int_ _writable (int_));
_EXTERN (long _pathconf (int_));
_EXTERN (mode_t _mode2unix (dosmode_t));
_EXTERN (unsigned int_ _tsleep (unsigned int_));
_EXTERN (void _finit (void_));
_EXTERN (void _noexec_return (void *));

#endif
