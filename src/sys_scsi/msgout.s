* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: msgout.s,v 1.3 1993/10/06 17:21:52 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_msgout

		.offset		4

buf		.ds.l		1

		.text

__scsi_msgout:
		move.l		buf(sp),a1	* data buf
		scsi		__S_MSGOUT
		rts

		.end
