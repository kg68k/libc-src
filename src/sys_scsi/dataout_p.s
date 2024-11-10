* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dataout_p.s,v 1.3 1993/10/06 17:21:31 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_dataout_p

		.offset		4+4*1

byte		.ds.l		1
buf		.ds.l		1

		.text

__scsi_dataout_p:
		move.l		d3,-(sp)	* push d3
		move.l		byte(sp),d3	* data byte
		move.l		buf(sp),a1	* data buf
		scsi		__S_DATAOUT_P
		move.l		(sp)+,d3	* pop d3
		rts

		.end
