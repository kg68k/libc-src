* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: modesense.s,v 1.4 1993/11/13 06:36:26 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_modesense

		.offset		4+4*2

page		.ds.l		1
		.ds.w		1
len		.ds.w		1
id		.ds.l		1
buf		.ds.l		1

		.text

__scsi_modesense:
		movem.l		d3-d4,-(sp)	* pop d3,d4
		move.l		page(sp),d2	* page
		moveq.l		#0,d3
		move.w		len(sp),d3	* len
		move.l		id(sp),d4	* scsi id
		move.l		buf(sp),a1	* data buf
		scsi		__S_MODESENSE
		movem.l		(sp)+,d3-d4	* pop d3,d4
		rts

		.end
