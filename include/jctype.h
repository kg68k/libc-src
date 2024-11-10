/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: jctype.h,v 1.1.1.1 1993/04/18 16:13:11 mura Exp $
 */

/* for compatibility only */

#ifndef __jctype_h__
#define __jctype_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __mbctype_h__
#include <mbctype.h>
#endif

#define isalkana   ismbbalpha
#define isalnmkana ismbbalnum
#define isgrkana   ismbbgraph
#define iskana     ismbbkana
#define iskanji    ismbblead
#define iskanji2   ismbbtrail
#define iskmoji    ismbbkalnum
#define iskpun     ismbbkpunct
#define ispnkana   ismbbpunct
#define isprkana   ismbbprint

#define jisalpha   ismbcalpha
#define jisdigit   ismbcdigit
#define jishira    ismbchira
#define jiskata    ismbckata
#define jiskigou   ismbcsymbol
#define jisl0      ismbcl0
#define jisl1      ismbcl1
#define jisl2      ismbcl2
#define jislower   ismbclower
#define jisprint   ismbcprint
#define jisspace   ismbcspace
#define jisupper   ismbcupper
#define jiszen     ismbclegal

#define jtohira    mbctohira
#define jtokata    mbctokata
#define jtolower   mbctolower
#define jtoupper   mbctoupper

#endif
