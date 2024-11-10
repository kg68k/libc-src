/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xsignal.h,v 1.6 1994/11/26 14:49:21 mura Exp $
 */

#ifndef __sys_xsignal_h__
#define __sys_xsignal_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __signal_h__
#include <signal.h>
#endif

#define ABRTJB_VECTORNO (0x01ff)
#define CTLABT_VECTORNO (0xfff1)
#define DEXIT2_VECTORNO (0xff4c)
#define ERRABT_VECTORNO (0xfff2)
#define KILLPR_VECTORNO (0xfff9)
#define SPURIO_VECTORNO (0x0024)
#define TRAP13_VECTORNO (0x002d)
#define TRAP14_VECTORNO (0x002e)

#define RTC_HZ		16
#define RTC_MODE	(*(volatile unsigned char *) 0xe8a01b)
#define RTC_RESET_CTRL	(*(volatile unsigned char *) 0xe8a01f)
#define MFP		((volatile mfp_t *) 0xe88000)

#define _TE_ABORT    0  /* A is selected */
#define _TE_RETRY    1  /* R is selected */
#define _TE_IGNORE   2  /* I is selected */
#define _TE_OLDVEC (-1) /* jump to original handler */

#define S_ABRT			0x0101
#define S_FPE			0x0102
#define S_ILL			0x0103
#define S_INT			0x0104
#define S_SEGV			0x0105
#define S_TERM			0x0106
#define S_ALRM			0x0107
#define S_KILL			0x0108
#define S_BUS			0x0109
#define S_STOP			0x010a
#define S_EMT			0x010b
#define S_USR1			0x010c
#define S_USR2			0x010d

#define S_BUS_ERROR		0x0002
#define S_ADDRESS_ERROR 	0x0003
#define S_ILLEGAL_INSTRUCTION	0x0004
#define S_DIVISION_BY_ZERO	0x0005
#define S_CHK_EXECUTION 	0x0006
#define S_TRAPV_EXECUTION	0x0007
#define S_PRIVINTR_VIOLATION	0x0008
#define S_NMI1			0x001f
#define S_NMI2			0x301f

#define S_UNDEFINED_INTERRUPT	0x0000
#define S_UNDEFINED_IOCSCALL	0x0100
#define S_UNDEFINED_LINE_F	0xf000
#define S_UNDEFINED_DOSCALL	0xff00

#define S_INVALID_UNIT		0x0001
#define S_DRIVE_NOT_READY	0x0002
#define S_INVALID_DEVICE_CMD	0x0003
#define S_CRC_ERROR		0x0004
#define S_BROKEN_FAT		0x0005
#define S_SEEK_ERROR		0x0006
#define S_INVALID_MEDIA 	0x0007
#define S_SECTOR_NOT_FOUND	0x0008
#define S_PRINTER_OFFLINE	0x0009
#define S_WRITE_ERROR		0x000A
#define S_READ_ERROR		0x000B
#define S_UNKNOWN_ERROR 	0x000C
#define S_WRITE_PROTECT_FIXED	0x000D
#define S_WRITE_PROTECT 	0x000E

typedef enum {
    ERR_INVALID_UNIT,
    ERR_DRIVE_NOT_READY,
    ERR_INVALID_DEVICE_COMMAND,
    ERR_CRC_ERROR,
    ERR_BROKEN_FAT,
    ERR_SEEK_ERROR,
    ERR_INVALID_MEDIA,
    ERR_SECTOR_NOT_FOUND,
    ERR_PRINTER_OFFLINE,
    ERR_WRITE_ERROR,
    ERR_READ_ERROR,
    ERR_UNKNOWN_ERROR,
    ERR_WRITE_PROTECT_FIXED,
    ERR_WRITE_PROTECT,
    ERR_NMI,
    ERR_BUS_ERROR,
    ERR_ADDRESS_ERROR,
    ERR_ILLEGAL_INSTRUCTION,
    ERR_DIVISION_BY_ZERO,
    ERR_CHK_EXECUTION,
    ERR_TRAPV_EXECUTION,
    ERR_PRIVINTR_VIOLATION,
    ERR_UNDEFINED_INTERRUPT,
    ERR_UNDEFINED_IOCSCALL,
    ERR_UNDEFINED_LINE_F,
    ERR_UNDEFINED_DOSCALL,
    ERR_USERSIG_ABRT,
    ERR_USERSIG_FPE,
    ERR_USERSIG_ILL,
    ERR_USERSIG_INT,
    ERR_USERSIG_SEGV,
    ERR_USERSIG_TERM,
    ERR_USERSIG_ALRM,
    ERR_USERSIG_KILL,
    ERR_USERSIG_BUS,
    ERR_USERSIG_STOP,
    ERR_USERSIG_EMT,
    ERR_USERSIG_USR1,
    ERR_USERSIG_USR2,
} ecode_t;

typedef enum {
    TYPE_NMI,			/* nmi */
    TYPE_SYS,			/* system error */
    TYPE_SIG,			/* signal trap */
    TYPE_DOS,			/* os error */
    TYPE_UNDEFINT,		/* undefined interrupt error */
} etype_t;

typedef struct {
    etype_t mode;		/* error type */
    ecode_t code;		/* error code */
    int_ must;			/* permitted action flag */
    unsigned long pc;		/* program counter (pc) */
    unsigned long sp;		/* user stack pointer (usp) */
    unsigned short sr;		/* system register (sr) */
} einfo_t;

typedef void (*efunc_t) (void_);

typedef struct {
    unsigned:8;
    unsigned hsync:1;
    unsigned cirq:1;
    unsigned:1;
    unsigned vsync:1;
    unsigned fmirq:1;
    unsigned powsw:1;
    unsigned expon:1;
    unsigned alarm:1;
} gpip_t;

typedef struct {
    unsigned:8;
    unsigned hsync:1;
    unsigned cirq:1;
    unsigned timera:1;
    unsigned rbfull:1;
    unsigned rerror:1;
    unsigned sbempty:1;
    unsigned serror:1;
    unsigned timeb:1;
} iera_t;

typedef struct {
    unsigned:8;
    unsigned:1;
    unsigned vdisp:1;
    unsigned timerc:1;
    unsigned timerd:1;
    unsigned fmirq:1;
    unsigned powsw:1;
    unsigned expon:1;
    unsigned alarm:1;
} ierb_t;

typedef struct {
    gpip_t gpip;
    gpip_t aer;
    gpip_t ddr;
    iera_t iera;
    ierb_t ierb;
    iera_t ipra;
    ierb_t iprb;
    iera_t isra;
    ierb_t isrb;
    iera_t imra;
    ierb_t imrb;
    unsigned:8;
    unsigned char vr;
} mfp_t;

typedef struct {
    unsigned aer:1;
    unsigned imrb:1;
    unsigned ierb:1;
} mfpsave_t;

extern efunc_t _oldabj;
extern efunc_t _oldabt;
extern efunc_t _oldctl;
extern efunc_t _olderr;
extern efunc_t _oldex2;
extern efunc_t _oldkpr;
extern efunc_t _oldspr;
extern efunc_t _oldrtc;
extern hardfunc_t _harderr_handler;
extern int_ _oldbrk;
extern mfpsave_t _oldmfp;
extern volatile einfo_t _sigpendinginfo[];
extern volatile int_ _alarm_on;
extern volatile int_ _pause;
extern volatile int_ _rtccnt;
extern volatile int_ _rtcnxt;
extern volatile sigset_t _sigmask;
extern volatile sigset_t _sigpendingset;
extern volatile struct sigaction _sigactions[];

_EXTERN (int_ _raise (int_));
_EXTERN (int_ _sigdispatch (void_));
_EXTERN (int_ _signal (einfo_t *));
_EXTERN (int_ _sigparse (einfo_t *));
_EXTERN (void __volatile _doscall_escape (int_));
_EXTERN (void __volatile _harderror_return (void_));
_EXTERN (void __volatile _intabt (void_));
_EXTERN (void __volatile _intctl (void_));
_EXTERN (void __volatile _interr (void_));
_EXTERN (void __volatile _intrtc (void_));
_EXTERN (void __volatile _intrte (void_));
_EXTERN (void _sigclrcnt (void_));
_EXTERN (void _sigdfl (int_, einfo_t *));
_EXTERN (void _sigend (void_));
_EXTERN (void _siginit (void_));
_EXTERN (void _sigrtcsave (int_));
_EXTERN (void _sigsetcnt (int_, int_));

#endif
