* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: trap15.s,v 1.1.1.1 1993/04/18 16:36:18 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_trap15

		.offset		36+4	* d3-d7/a3-a6(5 + 4) + return address

inregs		.ds.l	1
outregs		.ds.l	1

		.text

__iocs_trap15:
		movem.l		d3-d7/a3-a6,-(sp)	* save registers
		movea.l		inregs(sp),a0
		movem.l		(a0),d0-d7/a1-a6
		trap		#15
		movea.l		outregs(sp),a0
		movem.l		d0-d7/a1-a6,(a0)	* load registers
		movem.l		(sp)+,d3-d7/a3-a6
		rts

		.end
