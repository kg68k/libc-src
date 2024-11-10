* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: inquiry.s,v 1.3 1993/10/06 17:21:38 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_inquiry

		.offset		4+4*2

byte		.ds.l		1
id		.ds.l		1
buf		.ds.l		1

		.text

__scsi_inquiry:
		movem.l		d3-d4,-(sp)	* push d3,d4
		move.l		byte(sp),d3	* data byte
		move.l		id(sp),d4	* scsi id
		move.l		buf(sp),a1	* data buf
		scsi		__S_INQUIRY
		movem.l		(sp)+,d3-d4	* pop d3,d4
		rts

		.end
