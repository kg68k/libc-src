* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_locate.s,v 1.2 1993/10/06 17:10:06 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_locate

		.offset		4

x		.ds.l		1
y		.ds.l		1

		.text

__iocs_b_locate:
		movem.l		x(sp),d1-d2
		iocs		__B_LOCATE
		rts

		.end
