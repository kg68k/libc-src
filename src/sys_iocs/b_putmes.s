* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_putmes.s,v 1.2 1993/10/06 17:10:39 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_putmes

		.offset		8+4	* d3 + d4 + ret-addr

color		.ds.l		1
x		.ds.l		1
y		.ds.l		1
max		.ds.l		1
addr		.ds.l		1


		.text

__iocs_b_putmes:
		movem.l		d3-d4,-(sp)	* save regs
		movem.l		color(sp),d1-d4/a1
		iocs		__B_PUTMES
		move.l		d2,d0		* return value
		movem.l		(sp)+,d3-d4	* load regs
		rts

		.end
