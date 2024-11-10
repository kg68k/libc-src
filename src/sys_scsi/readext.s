* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: readext.s,v 1.4 1993/11/13 06:36:33 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_readext

		.offset		4+4*3

pos		.ds.l		1
		.ds.w		1
blk		.ds.w		1
id		.ds.l		1
secsize		.ds.l		1
buf		.ds.l		1

		.text

__scsi_readext:
		movem.l		d3-d5,-(sp)	* push d3,d4,d5
		move.l		pos(sp),d2	* pos
		moveq.l		#0,d3
		move.w		blk(sp),d3	* blk
		move.l		id(sp),d4	* scsi id
		move.l		secsize(sp),d5	* sec size
		move.l		buf(sp),a1	* data buf
		scsi		__S_READEXT
		movem.l		(sp)+,d3-d5	* pop d3,d4,d5
		rts

		.end
