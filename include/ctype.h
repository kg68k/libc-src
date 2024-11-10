/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: ctype.h,v 1.6 1994/05/02 16:34:01 mura Exp $
 */

#ifndef __ctype_h__
#define __ctype_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define _ISUPPER 0x001
#define _ISLOWER 0x002
#define _ISDIGIT 0x004
#define _ISSPACE 0x008
#define _ISPUNCT 0x010
#define _ISCNTRL 0x020
#define _ISXDIGT 0x040
#define _ISBLANK 0x080

#define _ISALNUM (_ISDIGIT | _ISUPPER | _ISLOWER)
#define _ISALPHA (_ISUPPER | _ISLOWER)
#define _ISGRAPH (_ISDIGIT | _ISLOWER | _ISPUNCT | _ISUPPER)
#define _ISPRINT (_ISBLANK | _ISDIGIT | _ISLOWER | _ISUPPER | _ISPUNCT)

#define _tolower(c) ((int_) _ctype_lower[(unsigned char) (c)])
#define _toupper(c) ((int_) _ctype_upper[(unsigned char) (c)])

extern __common const unsigned char *_ctype_lower;
extern __common const unsigned char *_ctype_upper;
extern __common const unsigned char *_ctype;

_EXTERN (int_ __const isalnum (int_));
_EXTERN (int_ __const isalpha (int_));
_EXTERN (int_ __const isascii (int_));
_EXTERN (int_ __const isblank (int_));
_EXTERN (int_ __const iscntrl (int_));
_EXTERN (int_ __const iscsym (int_));
_EXTERN (int_ __const iscsymf (int_));
_EXTERN (int_ __const isdigit (int_));
_EXTERN (int_ __const isgraph (int_));
_EXTERN (int_ __const isiso (int_));
_EXTERN (int_ __const islower (int_));
_EXTERN (int_ __const isodigit (int_));
_EXTERN (int_ __const isprint (int_));
_EXTERN (int_ __const ispunct (int_));
_EXTERN (int_ __const isspace (int_));
_EXTERN (int_ __const isupper (int_));
_EXTERN (int_ __const isxdigit (int_));
_EXTERN (int_ __const toascii (int_));
_EXTERN (int_ __const toiso (int_));
_EXTERN (int_ __const tolower (int_));
_EXTERN (int_ __const toupper (int_));

#ifndef __NO_CTYPE_INLINE__

#define isalnum(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISALNUM))
#define isalpha(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISALPHA))
#define iscntrl(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISCNTRL))
#define isdigit(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISDIGIT))
#define isgraph(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISGRAPH))
#define islower(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISLOWER))
#define isprint(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISPRINT))
#define ispunct(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISPUNCT))
#define isspace(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISSPACE))
#define isupper(c)  ((int_) (_ctype[(unsigned char) (c)] & _ISUPPER))
#define isxdigit(c) ((int_) (_ctype[(unsigned char) (c)] & _ISXDIGT))

#define isascii(c)  ((int_) ((unsigned char) (c) <= 0x7fU))
#define isiso(c)    ((int_) ((unsigned char) (c) <= 0xffU))

#define iscsym(c)   ((int_) ((_ctype[(unsigned char) (c)] & _ISALNUM) || (c) == '_'))
#define iscsymf(c)  ((int_) ((_ctype[(unsigned char) (c)] & _ISALPHA) || (c) == '_'))
#define isblank(c)  ((int_) ((c) == ' ' || (c) == '\t'))
#define isodigit(c) ((int_) ((c) >= '0' && (c) <= '7'))

#define toascii(c)  ((int_) ((c) & 0x7f))
#define toiso(c)    ((int_) ((c) & 0xff))
#define tolower(c)  ((int_) _ctype_lower[(unsigned char) (c)])
#define toupper(c)  ((int_) _ctype_upper[(unsigned char) (c)])

#endif

#endif
