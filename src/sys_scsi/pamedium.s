* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: pamedium.s,v 1.3 1993/10/06 17:21:56 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_pamedium

		.offset		4+4*2

eject		.ds.l		1
id		.ds.l		1

		.text

__scsi_pamedium:
		movem.l		d3-d4,-(sp)	* push d3,d4
		move.l		eject(sp),d3	* eject
		move.l		id(sp),d4	* scsi id
		scsi		__S_PAMEDIUM
		movem.l		(sp)+,d3-d4	* pop d3,d4
		rts

		.end
