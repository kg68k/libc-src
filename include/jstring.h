/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: jstring.h,v 1.4 1993/08/16 13:31:34 mura Exp $
 */

/* for compatibility only */

#ifndef __jstring_h__
#define __jstring_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __mbstring_h__
#include <mbstring.h>
#endif

#define CT_ANK    _MBC_SINGLE
#define CT_KJ1    _MBC_LEAD
#define CT_KJ2    _MBC_TRAIL
#define CT_ILGL   _MBC_ILLEGAL

#define btom      mbsnccnt
#define chkctype  mbbtype
#define hantozen  mbbtombc
#define jstradv   mbsninc
#define jstrcat   mbscat
#define jstrchr   mbschr
#define jstrcmp   mbscmp
#define jstrcpy   mbscpy
#define jstrcspn  mbscspn
#define jstricmp  mbsicmp
#define jstrlen   mbslen
#define jstrlwr   mbslwr
#define jstrmatch mbspbrk
#define jstrncat  mbsncat
#define jstrncmp  mbsncmp
#define jstrncpy  mbsncpy
#define jstrnicmp mbsnicmp
#define jstrrev   mbsrev
#define jstrrchr  mbsrchr
#define jstrset   mbsset
#define jstrskip  mbsspnp
#define jstrspn   mbsspn
#define jstrstr   mbsstr
#define jstrtok   mbstok
#define jstrupr   mbsupr
#define mtob      mbsnbcnt
#define nthctype  mbsbtype
#define zentohan  mbctombb

#endif
