* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_dskini.s,v 1.3 1993/10/06 17:09:11 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_dskini

		.offset		4

drive		.ds.l		1
addr		.ds.l		1
offtm		.ds.l		1

		.text

__iocs_b_dskini:
		move.l		drive(sp),d1	* drive
		movea.l		addr(sp),a1	* data address
		move.l		offtm(sp),d2	* off time
		iocs		__B_DSKINI
		rts

		.end
