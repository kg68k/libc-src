* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_seek.s,v 1.3 1993/10/06 17:11:11 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_seek

		.offset		4

drive		.ds.l		1
recno		.ds.l		1

		.text

__iocs_b_seek:
		movem.l		drive(sp),d1-d2	* d1 = drive, d2 = recno
		iocs		__B_SEEK
		rts

		.end
