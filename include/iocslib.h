/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,	 and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iocslib.h,v 1.4 1994/11/26 14:48:20 mura Exp $
 */

/* for compatibility only */

#ifndef __iocslib_h__
#define __iocslib_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_iocs_h__
#include <sys/iocs.h>
#endif

struct GETPTR {
    short x1;
    short y1;
    short x2;
    short y2;
    unsigned char *buf_start;
    unsigned char *buf_end;
};

struct PAINTPTR {
    short x;
    short y;
    unsigned short color;
    unsigned char *buf_start;
    unsigned char *buf_end;
};

struct PUTPTR {
    short x1;
    short y1;
    short x2;
    short y2;
    unsigned char *buf_start;
    unsigned char *buf_end;
};

struct CHAIN {
    unsigned char *adr;
    unsigned short len;
};

struct CHAIN2 {
    unsigned char *adr;
    unsigned short len;
    struct CHAIN2 *next;
};

#define BOXPTR		_boxptr
#define CIRCLEPTR	_circleptr
#define CLIPXY		_clipxy
#define FILLPTR		_fillptr
#define FNTBUF		_fntbuf
#define LINEPTR		_lineptr
#define PATST		_patst
#define POINTPTR	_pointptr
#define PSETPTR		_psetptr
#define REGS		_regs
#define SYMBOLPTR	_symbolptr
#define TBOXPTR		_tboxptr
#define TREVPTR		_trevptr
#define TXFILLPTR	_txfillptr
#define XLINEPTR	_xlineptr
#define YLINEPTR	_ylineptr

#define READCAP		_readcap
#define INQUIRY		_inquiry

#define ABORTJOB	_iocs_abortjob
#define ABORTRST	_iocs_abortrst
#define ADPCMINP	_iocs_adpcminp
#define ADPCMMOD	_iocs_adpcmmod
#define ADPCMOUT	_iocs_adpcmout
#define ADPCMSNS	_iocs_adpcmsns
#define AKCONV		_iocs_akconv
#define ALARMGET	_iocs_alarmget
#define ALARMMOD	_iocs_alarmmod
#define ALARMSET	_iocs_alarmset
#define APAGE		_iocs_apage
#define BGCTRLGT	_iocs_bgctrlgt
#define BGCTRLST	_iocs_bgctrlst
#define BGSCRLGT	_iocs_bgscrlgt
#define BGSCRLST	_iocs_bgscrlst
#define BGTEXTCL	_iocs_bgtextcl
#define BGTEXTGT	_iocs_bgtextgt
#define BGTEXTST	_iocs_bgtextst
#define BINDATEBCD	_iocs_bindatebcd
#define BINDATEGET	_iocs_bindateget
#define BINDATESET	_iocs_bindateset
#define BITSNS		_iocs_bitsns
#define BOOTINF		_iocs_bootinf
#define BOX		_iocs_box
#define B_ASSIGN	_iocs_b_assign
#define B_BADFMT	_iocs_b_badfmt
#define B_BPEEK		_iocs_b_bpeek
#define B_BPOKE		_iocs_b_bpoke
#define B_CLR_AL	_iocs_b_clr_al
#define B_CLR_ED	_iocs_b_clr_ed
#define B_CLR_ST	_iocs_b_clr_st
#define B_COLOR		_iocs_b_color
#define B_CONSOL	_iocs_b_consol
#define B_CUROFF	_iocs_b_curoff
#define B_CURON		_iocs_b_curon
#define B_DEL		_iocs_b_del
#define B_DOWN		_iocs_b_down
#define B_DOWN_S	_iocs_b_down_s
#define B_DRVCHK	_iocs_b_drvchk
#define B_DRVSNS	_iocs_b_drvsns
#define B_DSKINI	_iocs_b_dskini
#define B_EJECT		_iocs_b_eject
#define B_ERA_AL	_iocs_b_era_al
#define B_ERA_ED	_iocs_b_era_ed
#define B_ERA_ST	_iocs_b_era_st
#define B_FORMAT	_iocs_b_format
#define B_INS		_iocs_b_ins
#define B_INTVCS	_iocs_b_intvcs
#define B_KEYINP	_iocs_b_keyinp
#define B_KEYSNS	_iocs_b_keysns
#define B_LEFT		_iocs_b_left
#define B_LOCATE	_iocs_b_locate
#define B_LPEEK		_iocs_b_lpeek
#define B_LPOKE		_iocs_b_lpoke
#define B_MEMSET	_iocs_b_memset
#define B_MEMSTR	_iocs_b_memstr
#define B_PRINT		_iocs_b_print
#define B_PUTC		_iocs_b_putc
#define B_PUTMES	_iocs_b_putmes
#define B_READ		_iocs_b_read
#define B_READDI	_iocs_b_readdi
#define B_READDL	_iocs_b_readdl
#define B_READID	_iocs_b_readid
#define B_RECALI	_iocs_b_recali
#define B_RIGHT		_iocs_b_right
#define B_SEEK		_iocs_b_seek
#define B_SFTSNS	_iocs_b_sftsns
#define B_SUPER		_iocs_b_super
#define B_UP		_iocs_b_up
#define B_UP_S		_iocs_b_up_s
#define B_VERIFY	_iocs_b_verify
#define B_WPEEK		_iocs_b_wpeek
#define B_WPOKE		_iocs_b_wpoke
#define B_WRITE		_iocs_b_write
#define B_WRITED	_iocs_b_writed
#define CIRCLE		_iocs_circle
#define CLIPPUT		_iocs_clipput
#define CONTRAST	_iocs_contrast
#define CRTCRAS		_iocs_crtcras
#define CRTMOD		_iocs_crtmod
#define DAKJOB		_iocs_dakjob
#define DATEASC		_iocs_dateasc
#define DATEBIN		_iocs_datebin
#define DATECNV		_iocs_datecnv
#define DAYASC		_iocs_dayasc
#define DEFCHR		_iocs_defchr
#define DENSNS		_iocs_densns
#define DMAMODE		_iocs_dmamode
#define DMAMOVE		_iocs_dmamove
#define FILL		_iocs_fill
#define FNTGET		_iocs_fntget
#define GPALET		_iocs_gpalet
#define G_CLR_ON	_iocs_g_clr_on
#define HANJOB		_iocs_hanjob
#define HOME		_iocs_home
#define HSVTORGB	_iocs_hsvtorgb
#define HSYNCST		_iocs_hsyncst
#define INIT_PRN	_iocs_init_prn
#define INP232C		_iocs_inp232c
#define IPLERR		_iocs_iplerr
#define ISNS232C	_iocs_isns232c
#define JISSFT		_iocs_jissft
#define JOYGET		_iocs_joyget
#define LEDMOD		_iocs_ledmod
#define LINE		_iocs_line
#define LOF232C		_iocs_lof232c
#define MS_CURGT	_iocs_ms_curgt
#define MS_CUROF	_iocs_ms_curof
#define MS_CURON	_iocs_ms_curon
#define MS_CURST	_iocs_ms_curst
#define MS_GETDT	_iocs_ms_getdt
#define MS_INIT		_iocs_ms_init
#define MS_LIMIT	_iocs_ms_limit
#define MS_OFFTM	_iocs_ms_offtm
#define MS_ONTM		_iocs_ms_ontm
#define MS_PATST	_iocs_ms_patst
#define MS_SEL		_iocs_ms_sel
#define MS_SEL2		_iocs_ms_sel2
#define MS_STAT		_iocs_ms_stat
#define ONTIME		_iocs_ontime
#define OPMINTST	_iocs_opmintst
#define OPMSET		_iocs_opmset
#define OPMSNS		_iocs_opmsns
#define OSNS232C	_iocs_osns232c
#define OS_CUROF	_iocs_os_curof
#define OS_CURON	_iocs_os_curon
#define OUT232C		_iocs_out232c
#define OUTLPT		_iocs_outlpt
#define OUTPRN		_iocs_outprn
#define POINT		_iocs_point
#define PRNINTST	_iocs_prnintst
#define PSET		_iocs_pset
#define RMACNV		_iocs_rmacnv
#define ROMVER		_iocs_romver
#define SCROLL		_iocs_scroll
#define SET232C		_iocs_set232c
#define SFTJIS		_iocs_sftjis
#define SKEYSET		_iocs_skeyset
#define SKEY_MOD	_iocs_skey_mod
#define SNSPRN		_iocs_snsprn
#define SPALET		_iocs_spalet
#define SP_CGCLR	_iocs_sp_cgclr
#define SP_DEFCG	_iocs_sp_defcg
#define SP_GTPCG	_iocs_sp_gtpcg
#define SP_INIT		_iocs_sp_init
#define SP_OFF		_iocs_sp_off
#define SP_ON		_iocs_sp_on
#define SP_REGGT	_iocs_sp_reggt
#define SP_REGST	_iocs_sp_regst
#define SYMBOL		_iocs_symbol
#define TCOLOR		_iocs_tcolor
#define TEXTGET		_iocs_textget
#define TEXTPUT		_iocs_textput
#define TGUSEMD		_iocs_tgusemd
#define TIMEASC		_iocs_timeasc
#define TIMEBCD		_iocs_timebcd
#define TIMEBIN		_iocs_timebin
#define TIMECNV		_iocs_timecnv
#define TIMEGET		_iocs_timeget
#define TIMERDST	_iocs_timerdst
#define TIMESET		_iocs_timeset
#define TPALET		_iocs_tpalet
#define TPALET2		_iocs_tpalet2
#define TRAP15		_iocs_trap15
#define TVCTRL		_iocs_tvctrl
#define TXBOX		_iocs_txbox
#define TXFILL		_iocs_txfill
#define TXRASCPY	_iocs_txrascpy
#define TXREV		_iocs_txrev
#define TXXLINE		_iocs_txxline
#define TXYLINE		_iocs_txyline
#define VDISPST		_iocs_vdispst
#define VPAGE		_iocs_vpage
#define WINDOW		_iocs_window
#define WIPE		_iocs_wipe

#define S_CMDOUT	_scsi_cmdout
#define S_DATAIN	_scsi_datain
#define S_DATAIN_P	_scsi_datain_p
#define S_DATAOUT	_scsi_dataout
#define S_DATAOUT_P	_scsi_dataout_p
#define S_FORMAT	_scsi_format
#define S_INQUIRY	_scsi_inquiry
#define S_MODESELECT	_scsi_modeselect
#define S_MODESENSE	_scsi_modesense
#define S_MSGIN		_scsi_msgin
#define S_MSGOUT	_scsi_msgout
#define S_PAMEDIUM	_scsi_pamedium
#define S_PHASE		_scsi_phase
#define S_READ		_scsi_read
#define S_READCAP	_scsi_readcap
#define S_READEXT	_scsi_readext
#define S_REASSIGN	_scsi_reassign
#define S_REQUEST	_scsi_request
#define S_RESET		_scsi_reset
#define S_REZEROUNIT	_scsi_rezerounit
#define S_SEEK		_scsi_seek
#define S_SELECT	_scsi_select
#define S_STARTSTOP	_scsi_startstop
#define S_STSIN		_scsi_stsin
#define S_TESTUNIT	_scsi_testunit
#define S_WRITE		_scsi_write
#define S_WRITEEXT	_scsi_writeext

/* The following 9 macros prevent from conflictions */

#define GETGRM(a) _iocs_getgrm ((struct _getptr *) (a))
#define PUTGRM(a) _iocs_putgrm ((const struct _putptr *) (a))
#define PAINT(a) _iocs_paint ((struct _paintptr *) (a))
#define ADPCMAIN(a,b,c) _iocs_adpcmain ((const struct _chain *) (a), (b), (c))
#define ADPCMAOT(a,b,c) _iocs_adpcmaot ((const struct _chain *) (a), (b), (c))
#define ADPCMLIN(a,b) _iocs_adpcmlin ((const struct _chain2 *) (a), (b))
#define ADPCMLOT(a,b) _iocs_adpcmlot ((const struct _chain2 *) (a), (b))
#define DMAMOV_A(a,b,c,d) _iocs_dmamov_a ((const struct _chain *) (a), (b), (c), (d))
#define DMAMOV_L(a,b,c) _iocs_dmamov_l ((const struct _chain2 *) (a), (b), (c))

#endif
