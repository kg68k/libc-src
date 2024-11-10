/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xstat.h,v 1.6 1994/11/26 14:49:31 mura Exp $
 */

#ifndef __sys_xstat_h__
#define __sys_xstat_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_stat_h__
#include <sys/stat.h>
#endif

#ifndef __limits_h__
#include <limits.h>
#endif

#ifndef __sys_dos_h__
#include <sys/dos.h>
#endif

typedef struct {
    unsigned year:7;
    unsigned month:4;
    unsigned day:5;
    unsigned hour:5;
    unsigned minute:6;
    unsigned sec2:5;
} tstamp_t;

typedef struct {
    unsigned cdevice:1;
    unsigned ioctrl:1;
    unsigned dummy_bit_13:1;
    unsigned dummy_bit_12_6:7;
    unsigned mode:1;
    unsigned dummy_bit_4:1;
    unsigned clock_dev:1;
    unsigned null_dev:1;
    unsigned std_out_dev:1;
    unsigned std_in_dev:1;
} devatr_t;

typedef struct {
    void *next_header;
    union {
	unsigned short atr;
	devatr_t bit;
    } dev;
    void *strategy_entry;
    void *int_entry;
    char dev_name[8];
} devheader_t;

typedef struct {
    unsigned short drive;
    struct {
	unsigned int_ secno;
	unsigned int_ seclen;
    } chain[256];
} fatchain_t;

typedef struct {
    char name1[8];
    char ext[3];
    unsigned char attr;
    char name2[10];
    unsigned short time;
    unsigned short date;
    unsigned short fatno;
    unsigned long size;
} direntry_t;

typedef struct {
    char drive;
    char path[PATH_MAX + 1];
} virdirtbl_t;

/* this may be wrong... */
typedef struct {
    unsigned char drive;
    unsigned char unit;
    void *devheadptr;
    void *nexttblptr;
    unsigned short byte;
    unsigned char sec;
    unsigned char shift;
    unsigned short fatsec;
    unsigned char fatcount;
    unsigned char fatlen;
    unsigned short dircount;
    unsigned short datasec;
    unsigned short maxfat;
    unsigned short dirsec;
    unsigned char ide;
    unsigned char flg;
    unsigned short dirfat;
} dpbsrc_t;

typedef struct {
    char path[64];
    char null[4];
    char zero;
    char dirtype;
    dpbsrc_t *dpbsrcptr;
    short chain;
    short tow;
} drvtbl_t;

#define WILD_FALSE	    (0)
#define WILD_TRUE	    (1)
#define MAKEINODE(drv, sec) ((drv) << 24 | ((sec) & 0xffffff))

_EXTERN (char _phydrv2drvno (char drv));
_EXTERN (int_ _getinode (struct _filbuf *, int_));
_EXTERN (int_ _getphydriveno (const char *));
_EXTERN (int_ _iscdromdrive (int_));
_EXTERN (int_ _statsub (int_, const char *, struct stat *));
_EXTERN (void _getdpbsrc (int_, dpbsrc_t *));

#endif
