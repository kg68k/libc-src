/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: exec.h,v 1.3 1993/05/15 15:34:48 mura Exp $
 */

#ifndef __sys_exec_h__
#define __sys_exec_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __size_t_defined__
#define __size_t_defined__
typedef unsigned int_ size_t;
#endif

#define XMAGIC ((short) 0x4855)
#define CMAGIC ((long) 0x636f7265)

#define N_BADMAG(x) ((x).magic != XMAGIC)
#define N_TXTOFF(x) (0)
#define N_DATOFF(x) (N_TXTOFF (x) + (x).text)
#define N_OFFOFF(x) (N_DATOFF (x) + (x).data)
#define N_SYMOFF(x) (N_OFFOFF (x) + (x).offset)

struct aouthdr {
    short magic;		/* magic code */
    short memalloc;		/* memory allocation mode */
    long base;			/* base load addr */
    long exec;			/* execution point */
    size_t text;		/* text size */
    size_t data;		/* data size */
    size_t bss;			/* bss size */
    size_t offset;		/* offset data size */
    size_t symbol;		/* symbol size */
    size_t scd_linenum;		/* scd linenum info size */
    size_t scd_symbol;		/* scd symbol size */
    size_t scd_long_symbol;	/* scd long symbol size */
    char reserved[16];		/* reserved for future */
    size_t bind_offset;		/* offset to bind info. */
};

struct corehdr {
    long magic;			/* magic core */
    unsigned long pc;		/* program counter */
    unsigned long sp;		/* stack pointer */
    unsigned short sr;		/* system register */
    char fname[24];		/* process name */
    long memcp;			/* memory management block addr */
    long procp;			/* process management block addr */
    long psta;			/* text top */
    long dsta;			/* data top */
    long bsta;			/* bss top */
    long csta;			/* command line */
    long vsta;			/* argv buffer */
    long esta;			/* environmental variables */
    long fsta;			/* environ buffer */
    long ssta;			/* stack bottom */
    long hsta;			/* heap top */
    long last;			/* memory block last addr */
    long mmax;			/* maximum memory addr */
    char reserve[38];		/* reserved for future */
    char image[_ZEROARRAY];	/* memory image begins from here... */
};

#endif
