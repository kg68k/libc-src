* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_read.s,v 1.3 1993/10/06 17:10:44 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_read

		.offset		4+4	* d3

drive		.ds.l		1
recno		.ds.l		1
length		.ds.l		1
addr		.ds.l		1

		.text

__iocs_b_read:
		movem.l		d3,-(sp)	* save reg
		movem.l		drive(sp),d1-d3/a1
		iocs		__B_READ
		movem.l		(sp)+,d3	* load reg
		rts

		.end
