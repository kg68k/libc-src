* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: readcap.s,v 1.3 1993/10/06 17:22:07 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_readcap

		.offset		4+4*1

id		.ds.l		1
buf		.ds.l		1

		.text

__scsi_readcap:
		move.l		d4,-(sp)	* push d4
		move.l		id(sp),d4	* scsi id
		move.l		buf(sp),a1	* data buf
		scsi		__S_READCAP
		move.l		(sp)+,d4	* pop d4
		rts

		.end
