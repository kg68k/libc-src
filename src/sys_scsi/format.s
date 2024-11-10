* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: format.s,v 1.3 1993/10/06 17:21:35 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_format

		.offset		4+4*2

sift		.ds.l		1
id		.ds.l		1

		.text

__scsi_format:
		movem.l		d3-d4,-(sp)	* push d3
		move.l		sift(sp),d3	* sift
		move.l		id(sp),d4	* scsi id
		scsi		__S_FORMAT
		movem.l		(sp)+,d3-d4	* pop d3
		rts

		.end
