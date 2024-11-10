/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: mbctype.h,v 1.9 1994/07/27 13:43:21 mura Exp $
 */

#ifndef __mbctype_h__
#define __mbctype_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __ctype_h__
#include <ctype.h>
#endif

#define _MALPHA 0x01
#define _MBLANK 0x02
#define _MDIGIT 0x04
#define _MKMOJI 0x08
#define _MKPNCT 0x10
#define _MLEAD  0x20
#define _MPUNCT 0x40
#define _MTRAIL 0x80

#define _MBALNUM (_MALPHA | _MDIGIT | _MKPNCT | _MKMOJI)
#define _MBALPHA (_MALPHA | _MKPNCT | _MKMOJI)
#define _MBGRAPH (_MALPHA | _MDIGIT | _MPUNCT | _MKPNCT | _MKMOJI)
#define _MBKANA  (_MKPNCT | _MKMOJI)
#define _MBPRINT (_MALPHA | _MDIGIT | _MPUNCT | _MBLANK | _MKPNCT | _MKMOJI)
#define _MBPUNCT (_MPUNCT | _MKPNCT)

#define _MBLMASK(c) ((c) &  255)
#define _MBHMASK(c) ((c) & ~255)
#define _MBGETL(c)  ((c) &  255)
#define _MBGETH(c)  (((c) >> 8) & 255)

extern __common const unsigned char *_mbctype;

_EXTERN (int_ __const ismbbalnum (int_));
_EXTERN (int_ __const ismbbalpha (int_));
_EXTERN (int_ __const ismbbgraph (int_));
_EXTERN (int_ __const ismbbkalnum (int_));
_EXTERN (int_ __const ismbbkana (int_));
_EXTERN (int_ __const ismbbkpunct (int_));
_EXTERN (int_ __const ismbblead (int_));
_EXTERN (int_ __const ismbbprint (int_));
_EXTERN (int_ __const ismbbpunct (int_));
_EXTERN (int_ __const ismbbtrail (int_));
_EXTERN (int_ __const ismbcalpha (int_));
_EXTERN (int_ __const ismbcdigit (int_));
_EXTERN (int_ __const ismbchira (int_));
_EXTERN (int_ __const ismbckata (int_));
_EXTERN (int_ __const ismbcl0 (int_));
_EXTERN (int_ __const ismbcl1 (int_));
_EXTERN (int_ __const ismbcl2 (int_));
_EXTERN (int_ __const ismbclegal (int_));
_EXTERN (int_ __const ismbclower (int_));
_EXTERN (int_ __const ismbcprint (int_));
_EXTERN (int_ __const ismbcspace (int_));
_EXTERN (int_ __const ismbcsymbol (int_));
_EXTERN (int_ __const ismbcupper (int_));
_EXTERN (int_ __const mbctohira (int_));
_EXTERN (int_ __const mbctokata (int_));
_EXTERN (int_ __const mbctolower (int_));
_EXTERN (int_ __const mbctoupper (int_));

#ifndef __NO_CTYPE_INLINE__

#define ismbbalnum(c)  (_mbctype[(unsigned char) (c)] & _MBALNUM)
#define ismbbalpha(c)  (_mbctype[(unsigned char) (c)] & _MBALPHA)
#define ismbbgraph(c)  (_mbctype[(unsigned char) (c)] & _MBGRAPH)
#define ismbbkalnum(c) (_mbctype[(unsigned char) (c)] & _MKMOJI )
#define ismbbkana(c)   (_mbctype[(unsigned char) (c)] & _MBKANA )
#define ismbbkpunct(c) (_mbctype[(unsigned char) (c)] & _MKPNCT )
#define ismbblead(c)   (_mbctype[(unsigned char) (c)] & _MLEAD  )
#define ismbbprint(c)  (_mbctype[(unsigned char) (c)] & _MBPRINT)
#define ismbbpunct(c)  (_mbctype[(unsigned char) (c)] & _MBPUNCT)
#define ismbbtrail(c)  (_mbctype[(unsigned char) (c)] & _MTRAIL )

#define ismbcalpha(c)  (ismbcupper (c) || ismbclower (c))
#define ismbcdigit(c)  ((c) >= 0x824f && (c) <= 0x8258)
#define ismbchira(c)   ((c) >= 0x829f && (c) <= 0x82f1)
#define ismbckata(c)   ((c) >= 0x8340 && (c) <= 0x8396 && (c) != 0x837f)
#define ismbcl0(c)     ((c) >= 0x8140 && (c) <= 0x889e)
#define ismbcl1(c)     ((c) >= 0x889f && (c) <= 0x9872)
#define ismbcl2(c)     ((c) >= 0x989f && (c) <= 0xea9e)
#define ismbclower(c)  ((c) >= 0x8281 && (c) <= 0x829a)
#define ismbcspace(c)  ((c) == 0x8140)
#define ismbcsymbol(c) ((c) >= 0x8141 && (c) <= 0x81ac && (c) != 0x817f)
#define ismbcupper(c)  ((c) >= 0x8260 && (c) <= 0x8279)

#define ismbclegal(c)  (ismbblead (_MBGETH (c)) && ismbbtrail (_MBGETL (c)))
#define ismbcprint(c)  (_MBHMASK (c) ? ismbclegal (c) : (isprint (c) || ismbbkana (c)))

#define mbctolower(c)  (ismbcupper (c) ? (c) + 0x21 : (c))
#define mbctoupper(c)  (ismbclower (c) ? (c) - 0x21 : (c))

#endif

#endif
