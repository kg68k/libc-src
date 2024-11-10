/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: wctype.h,v 1.4 1993/10/06 16:45:34 mura Exp $
 */

#ifndef __wctype_h__
#define __wctype_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __ctype_h__
#include <ctype.h>
#endif

#ifndef __wchar_t_defined__
#define __wchar_t_defined__
typedef int_ wchar_t;
#endif

#ifndef __wint_t_defined__
#define __wint_t_defined__
typedef int_ wint_t;
#endif

typedef struct {
    wchar_t tmin;	  /* minimum type code */
    wchar_t tmax;	  /* maximum type code */
    unsigned char *index; /* class index */
    unsigned int_ *type;  /* class type */
    wchar_t cmin;	  /* minimum conversion code */
    wchar_t cmax;	  /* maximum conversion code */
    wchar_t *code;	  /* conversion code */
} wctype_t;

#define _ISASCII(x) (((x) & ~0x7f) == 0)
#define _ISISO(x)   (((x) & ~0xff) == 0)

_EXTERN (int_ __const iswalnum (wint_t));
_EXTERN (int_ __const iswalpha (wint_t));
_EXTERN (int_ __const iswascii (wint_t));
_EXTERN (int_ __const iswcntrl (wint_t));
_EXTERN (int_ __const iswdigit (wint_t));
_EXTERN (int_ __const iswgraph (wint_t));
_EXTERN (int_ __const iswlower (wint_t));
_EXTERN (int_ __const iswprint (wint_t));
_EXTERN (int_ __const iswpunct (wint_t));
_EXTERN (int_ __const iswspace (wint_t));
_EXTERN (int_ __const iswupper (wint_t));
_EXTERN (int_ __const iswxdigit (wint_t));
_EXTERN (int_ iswctype (wint_t, wctype_t));
_EXTERN (wctype_t wctype (const char *));
_EXTERN (wint_t __const towlower (wint_t));
_EXTERN (wint_t __const towupper (wint_t));

#ifndef __NO_CTYPE_INLINE__

#define iswalnum(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISALNUM) : 0)
#define iswalpha(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISALPHA) : 0)
#define iswcntrl(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISCNTRL) : 0)
#define iswdigit(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISDIGIT) : 0)
#define iswgraph(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISGRAPH) : 0)
#define iswlower(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISLOWER) : 0)
#define iswprint(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISPRINT) : 0)
#define iswpunct(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISPUNCT) : 0)
#define iswspace(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISSPACE) : 0)
#define iswupper(c)  ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISUPPER) : 0)
#define iswxdigit(c) ((int_) _ISASCII (c) ? (_ctype[(unsigned char) (c)] & _ISXDIGT) : 0)
#define iswascii(c)  ((int_) _ISASCII (c))
#define towlower(c)  ((int_) _ISASCII (c) ? _ctype_lower[(unsigned char) (c)] : (c))
#define towupper(c)  ((int_) _ISASCII (c) ? _ctype_upper[(unsigned char) (c)] : (c))

#endif

#endif
