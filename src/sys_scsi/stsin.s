* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: stsin.s,v 1.3 1993/10/06 17:22:39 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_stsin

		.offset		4

buf		.ds.l		1

		.text

__scsi_stsin:
		move.l		buf(sp),a1	* data buf
		scsi		__S_STSIN
		rts

		.end
