/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: string.h,v 1.10 1994/07/27 13:43:37 mura Exp $
 */

#ifndef __string_h__
#define __string_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __size_t_defined__
#define __size_t_defined__
typedef unsigned int_ size_t;
#endif

#ifndef NULL
#define NULL ((void *) 0)
#endif

#define movmem(a,b,c) memmove ((b), (a), (c))
#define movedata(a,b,c) memcpy ((b), (a), (c))
#define setmem(a,b,c) memset ((a), (c), (b))

_EXTERN (char *index (const char *, int_));
_EXTERN (char *rindex (const char *, int_));
_EXTERN (char *stpcpy (char *, const char *));
_EXTERN (char *strcat (char *, const char *));
_EXTERN (char *strchr (const char *, int_));
_EXTERN (char *strcpy (char *, const char *));
_EXTERN (char *strdup (const char *));
_EXTERN (char *strerror (int_));
_EXTERN (char *strlwr (char *));
_EXTERN (char *strncat (char *, const char *, size_t));
_EXTERN (char *strncpy (char *, const char *, size_t));
_EXTERN (char *strnset (char *, int_, size_t));
_EXTERN (char *strpbrk (const char *, const char *));
_EXTERN (char *strrchr (const char *, int_));
_EXTERN (char *strrev (char *));
_EXTERN (char *strset (char *, int_));
_EXTERN (char *strstr (const char *, const char *));
_EXTERN (char *strtok (char *, const char *));
_EXTERN (char *strtok2 (char *, const char *));
_EXTERN (char *strupr (char *));
_EXTERN (int_ __const ffs (int_));
_EXTERN (int_ bcmp (const void *, const void *, size_t));
_EXTERN (int_ bcopy (const void *, void *, size_t));
_EXTERN (int_ bzero (void *, size_t));
_EXTERN (int_ memcmp (const void *, const void *, size_t));
_EXTERN (int_ memcmpi (const void *, const void *, size_t));
_EXTERN (int_ memicmp (const void *, const void *, size_t));
_EXTERN (int_ stcgfe (char *, const char *));
_EXTERN (int_ stcgfn (char *, const char *));
_EXTERN (int_ strbpl (char **, int_, const char *));
_EXTERN (int_ strcasecmp (const char *, const char *));
_EXTERN (int_ strcmp (const char *, const char *));
_EXTERN (int_ strcmpi (const char *, const char *));
_EXTERN (int_ strcoll (const char *, const char *));
_EXTERN (int_ stricmp (const char *, const char *));
_EXTERN (int_ strncasecmp (const char *, const char *, size_t));
_EXTERN (int_ strncmp (const char *, const char *, size_t));
_EXTERN (int_ strnicmp (const char *, const char *, size_t));
_EXTERN (size_t strcspn (const char *, const char *));
_EXTERN (size_t strlen (const char *));
_EXTERN (size_t strspn (const char *, const char *));
_EXTERN (size_t strxfrm (char *, const char *, size_t));
_EXTERN (void *memccpy (void *, const void *, int_, size_t));
_EXTERN (void *memchr (const void *, int_, size_t));
_EXTERN (void *memcpy (void *, const void *, size_t));
_EXTERN (void *memmove (void *, const void *, size_t));
_EXTERN (void *memset (void *, int_, size_t));
_EXTERN (void repmem (void *, const void *, size_t, size_t));
_EXTERN (void strins (const char *, char *));
_EXTERN (void strmfe (char *, const char *, const char *));
_EXTERN (void strmfn (char *, const char *, const char *, const char *, const char *));
_EXTERN (void strmfp (char *, const char *, const char *));
_EXTERN (void strsfn (const char *, char *, char *, char *, char *));
_EXTERN (void strsrt (char **, int_));
_EXTERN (void swab (const char *, char *, size_t));
_EXTERN (void swmem (void *, void *, size_t));

#endif
