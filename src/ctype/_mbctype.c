/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _mbctype.c,v 1.3 1994/07/27 13:46:45 mura Exp $
 */

/* System headers */
#include <mbctype.h>

/* Macros */
#define B _MBLANK
#define D _MDIGIT
#define P _MPUNCT
#define T _MTRAIL

/* Macros */
#define AT (_MALPHA | _MTRAIL)
#define GT (_MKPNCT | _MTRAIL)
#define KT (_MKMOJI | _MTRAIL)
#define LT (_MLEAD  | _MTRAIL)
#define PT (_MPUNCT | _MTRAIL)

/* File scope variables */
static __common const unsigned char _lc_C_mbctype[257] = {
    0,						     /* EOF */
    0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , /* 0 */
    0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , /* 1 */
    B ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P , /* 2 */
    D ,D ,D ,P ,D ,D ,D ,D ,D ,D ,P ,P ,P ,P ,P ,P , /* 3 */
    PT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT, /* 4 */
    AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,PT,PT,PT,PT,PT, /* 5 */
    PT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT, /* 6 */
    AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,AT,PT,PT,PT,PT,0 , /* 7 */
    T ,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT, /* 8 */
    LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT, /* 9 */
    T ,GT,GT,GT,GT,GT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT, /* A */
    KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT, /* B */
    KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT, /* C */
    KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,KT,GT,GT, /* D */
    LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT, /* E */
    LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,LT,0 ,0 ,0 ,  /* F */
};

/* External variables */
__common const unsigned char *_mbctype = &_lc_C_mbctype[1];
