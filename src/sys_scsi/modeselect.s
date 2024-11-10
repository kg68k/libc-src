* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: modeselect.s,v 1.4 1993/11/13 06:36:22 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_modeselect

		.offset		4+4*2

pagelst		.ds.l		1
		.ds.w		1
llen		.ds.w		1
id		.ds.l		1
buf		.ds.l		1

		.text

__scsi_modeselect:
		movem.l		d3-d4,-(sp)	* push d3,d4
		move.l		pagelst(sp),d2	* page list
		moveq.l		#0,d3
		move.w		llen(sp),d3	* list length
		move.l		id(sp),d4	* scsi id
		move.l		buf(sp),a1	* data buf
		scsi		__S_MODESELECT
		movem.l		(sp)+,d3-d4	* pop d3,d4
		rts

		.end
