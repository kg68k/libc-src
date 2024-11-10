/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbstring.h,v 1.3 1993/10/06 16:44:29 mura Exp $
 */

#ifndef __mbstring_h__
#define __mbstring_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __mbctype_h__
#include <mbctype.h>
#endif

#ifndef __size_t_defined__
#define __size_t_defined__
typedef unsigned int_ size_t;
#endif

#ifndef NULL
#define NULL ((void *) 0)
#endif

#define _MBC_SINGLE   0
#define _MBC_LEAD     1
#define _MBC_TRAIL    2
#define _MBC_ILLEGAL -1

#define _MBIS16(c) ((c) & 0xff00)

_EXTERN (int_ __const mbbtombc (int_));
_EXTERN (int_ __const mbbtype (unsigned char, int_));
_EXTERN (int_ __const mbcjistojms (int_));
_EXTERN (int_ __const mbcjmstojis (int_));
_EXTERN (int_ __const mbctombb (int_));
_EXTERN (int_ mbsbtype (const unsigned char *, size_t));
_EXTERN (int_ mbscmp (const unsigned char *, const unsigned char *));
_EXTERN (int_ mbsicmp (const unsigned char *, const unsigned char *));
_EXTERN (int_ mbsncmp (const unsigned char *, const unsigned char *, size_t));
_EXTERN (int_ mbsnextc (const unsigned char *));
_EXTERN (int_ mbsnicmp (const unsigned char *, const unsigned char *, size_t));
_EXTERN (size_t mbscspn (const unsigned char *, const unsigned char *));
_EXTERN (size_t mbslen (const unsigned char *));
_EXTERN (size_t mbsnbcnt (const unsigned char *, size_t));
_EXTERN (size_t mbsnccnt (const unsigned char *, size_t));
_EXTERN (size_t mbsspn (const unsigned char *, const unsigned char *));
_EXTERN (unsigned char *mbscat (unsigned char *, const unsigned char *));
_EXTERN (unsigned char *mbschr (const unsigned char *, int_));
_EXTERN (unsigned char *mbscpy (unsigned char *, const unsigned char *));
_EXTERN (unsigned char *mbsdec (const unsigned char *, unsigned char *));
_EXTERN (unsigned char *mbsdup (const unsigned char *));
_EXTERN (unsigned char *mbsinc (unsigned char *));
_EXTERN (unsigned char *mbslwr (unsigned char *));
_EXTERN (unsigned char *mbsncat (unsigned char *, const unsigned char *, size_t));
_EXTERN (unsigned char *mbsncpy (unsigned char *, const unsigned char *, size_t));
_EXTERN (unsigned char *mbsninc (const unsigned char *, size_t));
_EXTERN (unsigned char *mbsnset (unsigned char *, int_, size_t));
_EXTERN (unsigned char *mbspbrk (const unsigned char *, const unsigned char *));
_EXTERN (unsigned char *mbsrchr (const unsigned char *, int_));
_EXTERN (unsigned char *mbsrev (unsigned char *));
_EXTERN (unsigned char *mbsset (unsigned char *, int_));
_EXTERN (unsigned char *mbsspnp (const unsigned char *, const unsigned char *));
_EXTERN (unsigned char *mbsstr (const unsigned char *, const unsigned char *));
_EXTERN (unsigned char *mbstok (unsigned char *, const unsigned char *));
_EXTERN (unsigned char *mbsupr (unsigned char *));

#endif
