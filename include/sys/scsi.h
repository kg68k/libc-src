/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: scsi.h,v 1.3 1994/07/31 17:21:50 mura Exp $
 */

#ifndef __sys_scsi_h__
#define __sys_scsi_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

struct _readcap {
    unsigned long block;
    unsigned long size;
};

struct _inquiry {
    unsigned char unit;
    unsigned char info;
    unsigned char ver;
    unsigned char reserve;
    unsigned char size;
    unsigned char buff[_ZEROARRAY];
};

_EXTERN (int_ _scsi_cmdout (int_, const void *));
_EXTERN (int_ _scsi_datain (int_, void *));
_EXTERN (int_ _scsi_datain_p (int_, void *));
_EXTERN (int_ _scsi_dataout (int_, const void *));
_EXTERN (int_ _scsi_dataout_p (int_, const void *));
_EXTERN (int_ _scsi_format (int_, int_));
_EXTERN (int_ _scsi_inquiry (int_, int_, struct _inquiry *));
_EXTERN (int_ _scsi_modeselect (int_, int_, int_, const void *));
_EXTERN (int_ _scsi_modesense (int_, int_, int_, void *));
_EXTERN (int_ _scsi_msgin (void *));
_EXTERN (int_ _scsi_msgout (const void *));
_EXTERN (int_ _scsi_pamedium (int_, int_));
_EXTERN (int_ _scsi_phase (void_));
_EXTERN (int_ _scsi_read (int_, int_, int_, int_, void *));
_EXTERN (int_ _scsi_readcap (int_, struct _readcap *));
_EXTERN (int_ _scsi_readext (int_, int_, int_, int_, void *));
_EXTERN (int_ _scsi_reassign (int_, int_, void *));
_EXTERN (int_ _scsi_request (int_, int_, void *));
_EXTERN (int_ _scsi_rezerounit (int_));
_EXTERN (int_ _scsi_seek (int_, int_));
_EXTERN (int_ _scsi_select (int_));
_EXTERN (int_ _scsi_startstop (int_, int_));
_EXTERN (int_ _scsi_stsin (void *));
_EXTERN (int_ _scsi_testunit (int_));
_EXTERN (int_ _scsi_write (int_, int_, int_, int_, const void *));
_EXTERN (int_ _scsi_writeext (int_, int_, int_, int_, const void *));
_EXTERN (void _scsi_reset (void_));

#endif
