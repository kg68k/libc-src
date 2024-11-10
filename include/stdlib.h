/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: stdlib.h,v 1.10 1994/11/27 13:01:22 mura Exp $
 */

#ifndef __stdlib_h__
#define __stdlib_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __size_t_defined__
#define __size_t_defined__
typedef unsigned int_ size_t;
#endif

#ifndef __wchar_t_defined__
#define __wchar_t_defined__
typedef int_ wchar_t;
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define RAND_MAX     32767
#define MB_CUR_MAX   2

#define _MAX_DRVNO   26
#define _MAX_DRIVE   3
#define _MAX_PATH    64
#define _MAX_FNAME   19
#define _MAX_EXT     19

#define max(a, b) (((a) >= (b)) ? (a) : (b))
#define min(a, b) (((a) <= (b)) ? (a) : (b))

typedef struct {
    int_ quot;
    int_ rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;

typedef void (*onexit_t) (void_);

extern char *optarg;
extern int_ _getopt_no_ordering;
extern int_ optind;
extern int_ opterr;

#define uitoa ultoa

_EXTERN (char *_fullentry (char *, const char *, size_t));
_EXTERN (char *_fullpath (char *, const char *, size_t));
_EXTERN (char *econvert (double, int_, int_ *, int_ *, char *));
_EXTERN (char *ecvt (double, int_, int_ *, int_ *));
_EXTERN (char *fconvert (double, int_, int_ *, int_ *, char *));
_EXTERN (char *fcvt (double, int_, int_ *, int_ *));
_EXTERN (char *gcvt (double, int_, char *));
_EXTERN (char *getenv (const char *));
_EXTERN (char *getpass (const char *));
_EXTERN (char *itoa (int_, char *, int_));
_EXTERN (char *ltoa (long, char *, int_));
_EXTERN (char *mktemp (char *));
_EXTERN (char *ultoa (unsigned long, char *, int_));
_EXTERN (div_t __const div (int_, int_));
_EXTERN (double atof (const char *));
_EXTERN (double drand (void_));
_EXTERN (double drand48 (void_));
_EXTERN (double erand48 (unsigned short[3]));
_EXTERN (double strtod (const char *, char **));
_EXTERN (int_ abs (int_));
_EXTERN (int_ atexit (void (*) (void_)));
_EXTERN (int_ atoi (const char *));
_EXTERN (int_ brk (void *));
_EXTERN (int_ clearenv (void_));
_EXTERN (int_ getopt (int_, char *[], const char *));
_EXTERN (int_ mblen (const char *, size_t));
_EXTERN (int_ mbtowc (wchar_t *, const char *, size_t));
_EXTERN (int_ mkstemp (char *));
_EXTERN (int_ putenv (const char *));
_EXTERN (int_ rand (void_));
_EXTERN (int_ setenv (const char *, const char *, int_));
_EXTERN (int_ system (const char *));
_EXTERN (int_ wctomb (char *, wchar_t));
_EXTERN (ldiv_t __const ldiv (long, long));
_EXTERN (long atol (const char *));
_EXTERN (long jrand48 (unsigned short[3]));
_EXTERN (long labs (long));
_EXTERN (long lrand48 (void_));
_EXTERN (long mrand48 (void_));
_EXTERN (long nrand48 (unsigned short[3]));
_EXTERN (long strtol (const char *, char **, int_));
_EXTERN (onexit_t onexit (onexit_t));
_EXTERN (short atow (const char *));
_EXTERN (short wabs (short));
_EXTERN (size_t chkml (void_));
_EXTERN (size_t sizmem (void_));
_EXTERN (size_t mbstowcs (wchar_t *, const char *, size_t));
_EXTERN (size_t wcstombs (char *, const wchar_t *, size_t));
_EXTERN (unsigned int_ random (void_));
_EXTERN (unsigned int_ srandom (unsigned int_));
_EXTERN (unsigned long strtoul (const char *, char **, int_));
_EXTERN (unsigned short *seed48 (unsigned short[3]));
_EXTERN (void *bsearch (const void *, const void *, size_t, size_t, int_ (*) (const void *, const void *)));
_EXTERN (void *calloc (size_t, size_t));
_EXTERN (void *malloc (size_t));
_EXTERN (void *memalign (size_t, size_t));
_EXTERN (void *realloc (void *, size_t));
_EXTERN (void *sbrk (int));
_EXTERN (void *valloc (size_t));
_EXTERN (void __volatile abort (void_));
_EXTERN (void __volatile exit (int_));
_EXTERN (void _makepath (char *, const char *, const char *, const char *, const char *));
_EXTERN (void _splitpath (const char *, char *, char *, char *, char *));
_EXTERN (void free (void *));
_EXTERN (void lcong48 (unsigned short [7]));
_EXTERN (void mallocmap (void));
_EXTERN (void qsort (void *, size_t, size_t, int_ (*) (const void *, const void *)));
_EXTERN (void rbrk (void_));
_EXTERN (void srand (unsigned int_));
_EXTERN (void srand48 (long));
_EXTERN (void unsetenv (const char *));

#ifndef __NO_STDLIB_INLINE__

#define abs(x)  ((x) >= 0 ? (int_) (x) : (int_) -(x))
#define labs(x) ((x) >= 0 ? (long) (x) : (long) -(x))
#define wabs(x) ((x) >= 0 ? (short) (x) : (short) -(x))

#endif

#endif
