/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: dos.h,v 1.6 1994/07/27 13:44:11 mura Exp $
 */

#ifndef __sys_dos_h__
#define __sys_dos_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define _DOS_IRDONLY	0x001
#define _DOS_IHIDDEN	0x002
#define _DOS_ISYS	0x004
#define _DOS_IFVOL	0x008
#define _DOS_IFDIR	0x010
#define _DOS_IFREG	0x020
#define _DOS_IFLNK	0x060 /* IFLNK | IFREG */
#define _DOS_IEXEC	0x080
#define _DOS_IFMT	0x078

#define _DOS_ISVOL(m)	(((m) & _DOS_IFMT) == _DOS_IFVOL)
#define _DOS_ISDIR(m)	(((m) & _DOS_IFMT) == _DOS_IFDIR)
#define _DOS_ISREG(m)	(((m) & _DOS_IFMT) == _DOS_IFREG)
#define _DOS_ISLNK(m)	(((m) & _DOS_IFMT) == _DOS_IFLNK)

#define _DEV_STDIN	0x0001
#define _DEV_STDOUT	0x0002
#define _DEV_NUL	0x0004
#define _DEV_CLOCK	0x0008
#define _DEV_RAW	0x0020
#define _DEV_IOCTRL	0x4000
#define _DEV_CDEV	0x8000

#define _DOSE_MAX       39

#define _DOSE_ILGFNC	-1
#define _DOSE_NOENT	-2
#define _DOSE_NODIR	-3
#define _DOSE_MFILE	-4
#define _DOSE_ISDIR	-5
#define _DOSE_BADF	-6
#define _DOSE_BROKNMEM	-7
#define _DOSE_NOMEM	-8
#define _DOSE_ILGMPTR	-9
#define _DOSE_ILGENV	-10
#define _DOSE_ILGFMT	-11
#define _DOSE_ILGARG	-12
#define _DOSE_ILGFNAME	-13
#define _DOSE_ILGPARM	-14
#define _DOSE_ILGDRV	-15
#define _DOSE_ISCURDIR	-16
#define _DOSE_CANTIOC	-17
#define _DOSE_NOMORE	-18
#define _DOSE_RDONLY	-19
#define _DOSE_EXISTDIR	-20
#define _DOSE_NOTEMPTY	-21
#define _DOSE_CANTREN	-22
#define _DOSE_DISKFULL	-23
#define _DOSE_DIRFULL	-24
#define _DOSE_CANTSEEK	-25
#define _DOSE_SUPER	-26
#define _DOSE_DUPTHNAM	-28
#define _DOSE_CANTRECV	-29
#define _DOSE_ILGTHID	-30
#define _DOSE_NFILE	-32
#define _DOSE_LCKERR	-33
#define _DOSE_SYMLOOP	-35
#define _DOSE_FEXIST	-36
#define _DOSE_BUFOVER	-37
#define _DOSE_NOSYS	-38
#define _DOSE_ALRDYEX	-39

#ifndef __dosmode_t_defined__
#define __dosmode_t_defined__
typedef int_ dosmode_t;
#endif

#ifndef __devmode_t_defined__
#define __devmode_t_defined__
typedef int_ devmode_t;
#endif

struct _inpptr {
    unsigned char max;
    unsigned char length;
    char buffer[256];
};

struct _nameckbuf {
    char drive[2];
    char path[65];
    char name[19];
    char ext[5];
};

union _fcb {
    struct {
	unsigned char dupcnt;
	unsigned char devattr;
	void *deventry;
	char nouse_1[8];
	unsigned char openmode;
	char nouse_2[21];
	char name1[8];
	char ext[3];
	char nouse_3;
	char name2[10];
	char nouse_4[38];
    } chr;
    struct {
	unsigned char dupcnt;
	unsigned mode    : 1;
	unsigned unknown : 2;
	unsigned physdrv : 5;
	void *deventry;
	unsigned int_ fileptr;
	unsigned int_ exclptr;
	unsigned char openmode;
	unsigned char entryidx;
	unsigned char clustidx;
	char nouse_2;
	unsigned short acluster;
	unsigned int_ asector;
	void *iobuf;
	unsigned long dirsec;
	unsigned int_ fptrmax;
	char name1[8];
	char ext[3];
	unsigned char attr;
	char name2[10];
	unsigned short time;
	unsigned short date;
	unsigned short fatno;
	unsigned long size;
	char nouse_4[28];
    } blk;
};

struct _indos {
    unsigned short indosf;
    unsigned char doscmd;
    unsigned char fat_flg;
    unsigned short retry_count;
    unsigned short retry_time;
    unsigned short verifyf;
    unsigned char breakf;
    unsigned char ctrlpf;
    unsigned char reserved;
    unsigned char wkcurdrv;
};

struct _mep {
    void *prev_mp;
    void *parent_mp;
    void *block_end;
    void *next_mp;
};

struct _psp {
    char *env;
    void *exit;
    void *ctrlc;
    void *errexit;
    char *comline;
    unsigned char handle[12];
    void *bss;
    void *heap;
    void *stack;
    void *usp;
    void *ssp;
    unsigned short sr;
    unsigned short abort_sr;
    void *abort_ssp;
    void *trap10;
    void *trap11;
    void *trap12;
    void *trap13;
    void *trap14;
    unsigned int_ osflg;
    unsigned char reserve_1[28];
    char exe_path[68];
    char exe_name[24];
    char reserve_2[36];
};

struct _comline {
    unsigned char len;
    char buffer[255];
};

struct _namestbuf {
    unsigned char flg;
    unsigned char drive;
    char path[65];
    char name1[8];
    char ext[3];
    char name2[10];
};

struct _freeinf {
    unsigned short free;
    unsigned short max;
    unsigned short sec;
    unsigned short byte;
};

struct _dpbptr {
    unsigned char drive;
    unsigned char unit;
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
    int_ driver;
    unsigned char ide;
    unsigned char flg;
    struct _dpbptr *next;
    unsigned short dirfat;
    char dirbuf[64];
};

struct _filbuf {
    unsigned char searchatr;
    unsigned char driveno;
    unsigned long dirsec;
    unsigned short dirlft;
    unsigned short dirpos;
    char filename[8];
    char ext[3];
    unsigned char atr;
    unsigned short time;
    unsigned short date;
    unsigned int_ filelen;
    char name[23];
};

struct _dregs {
    int_ d0;
    int_ d1;
    int_ d2;
    int_ d3;
    int_ d4;
    int_ d5;
    int_ d6;
    int_ d7;
    int_ a0;
    int_ a1;
    int_ a2;
    int_ a3;
    int_ a4;
    int_ a5;
    int_ a6;
};

struct _prcctrl {
    long length;
    unsigned char *buf_ptr;
    unsigned short command;
    unsigned short your_id;
};

struct _prcptr {
    struct _prcptr *next_ptr;
    unsigned char wait_flg;
    unsigned char counter;
    unsigned char max_counter;
    unsigned char doscmd;
    unsigned int_ psp_id;
    unsigned int_ usp_reg;
    unsigned int_ d_reg[8];
    unsigned int_ a_reg[7];
    unsigned short sr_reg;
    unsigned int_ pc_reg;
    unsigned int_ ssp_reg;
    unsigned short indosf;
    unsigned int_ indosp;
    struct _prcctrl *buf_ptr;
    unsigned char name[16];
    long wait_time;
};

/*
** If you want to use other inline headers, please add your selection
** mechanism here...
*/

#ifdef __DOS_INLINE__
#include <sys/dos_i.h>
#else
#include <sys/dos_p.h>
#endif

/*
** The following functions should be replaced with the corresponding
** SX-calls to create SX-libc libraries.
*/

#ifdef __LIBSXC__

#ifndef __sxlib_h__
#include <sxlib.h>
#endif

#define _dos_open   TSOpen    /* replaced */
#define _dos_close  TSClose   /* replaced */
#define _dos_create TSCreate  /* replaced */
#define _dos_files  TSFiles   /* replaced */
#define _dos_delete TSDeleteP /* replaced */
#define _dos_rmdir  TSRmDirP  /* replaced */
#define _dos_mkdir  TSMkDirP  /* replaced */
#define _dos_move   TSMoveP   /* replaced */
#define _dos_chmod  TSChMod   /* replaced */

#endif

#endif
