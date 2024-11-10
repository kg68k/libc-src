* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: scroll.s,v 1.2 1993/10/06 17:17:50 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_scroll

		.offset		4+4	* d3

mode		.ds.l		1
xdot		.ds.l		1
ydot		.ds.l		1

		.text

__iocs_scroll:
		movem.l		d3,-(sp)	* save d3 reg
		movem.l		mode(sp),d1-d3
		iocs		__SCROLL
		movem.l		(sp)+,d3	* load d3 reg
		rts

		.end
