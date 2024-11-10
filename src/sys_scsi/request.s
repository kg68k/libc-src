* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: request.s,v 1.4 1994/05/02 17:20:48 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_request

		.offset		4+4*2

byte		.ds.l		1
id		.ds.l		1
buf		.ds.l		1

		.text

__scsi_request:
		movem.l		d3/d4,-(sp)	* push d3, d4
		movem.l		byte(sp),d3/d4	* d3=data byte, d4=scsi id
		move.l		buf(sp),a1	* data buf
		scsi		__S_REQUEST
		movem.l		(sp)+,d3/d4	* pop d3, d4
		rts

		.end
