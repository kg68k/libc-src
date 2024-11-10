/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _ctype.c,v 1.5 1994/07/27 13:46:33 mura Exp $
 */

/* System headers */
#include <ctype.h>

/* Macros */
#define U _ISUPPER
#define L _ISLOWER
#define D _ISDIGIT
#define S _ISSPACE
#define P _ISPUNCT
#define C _ISCNTRL

/* Macros */
#define CS  (_ISCNTRL | _ISSPACE)
#define DX  (_ISDIGIT | _ISXDIGT)
#define UX  (_ISUPPER | _ISXDIGT)
#define LX  (_ISLOWER | _ISXDIGT)
#define SB  (_ISSPACE | _ISBLANK)

/* File scope variables */
static __common const unsigned char _lc_C_ctype[257] = {
    0,						     /* EOF */
    C ,C ,C ,C ,C ,C ,C ,C ,C ,CS,CS,CS,CS,CS,C ,C , /* 0 */
    C ,C ,C ,C ,C ,C ,C ,C ,C ,C ,C ,C ,C ,C ,C ,C , /* 1 */
    SB,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P , /* 2 */
    DX,DX,DX,DX,DX,DX,DX,DX,DX,DX,P ,P ,P ,P ,P ,P , /* 3 */
    P ,UX,UX,UX,UX,UX,UX,U ,U ,U ,U ,U ,U ,U ,U ,U , /* 4 */
    U ,U ,U ,U ,U ,U ,U ,U ,U ,U ,U ,P ,P ,P ,P ,P , /* 5 */
    P ,LX,LX,LX,LX,LX,LX,L ,L ,L ,L ,L ,L ,L ,L ,L , /* 6 */
    L ,L ,L ,L ,L ,L ,L ,L ,L ,L ,L ,P ,P ,P ,P ,C , /* 7 */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , /* 8 */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , /* 9 */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , /* A */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , /* B */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , /* C */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , /* D */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , /* E */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , /* F */
};

/* External variables */
__common const unsigned char *_ctype = &_lc_C_ctype[1];
