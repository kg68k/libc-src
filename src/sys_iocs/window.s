* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: window.s,v 1.3 1993/10/06 17:21:00 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_window

		.offset		4+8	* d3, d4

sx		.ds.l		1
sy		.ds.l		1
ex		.ds.l		1
ey		.ds.l		1

		.text

__iocs_window:
		movem.l		d3-d4,-(sp)	* save regs
		movem.l		sx(sp),d1-d4
		iocs		__WINDOW
		movem.l		(sp)+,d3-d4	* save regs
		rts

		.end
