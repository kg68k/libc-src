* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: textput.s,v 1.2 1993/10/06 17:19:15 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_textput

		.offset		4

xdot		.ds.l		1
ydot		.ds.l		1
buf		.ds.l		1

		.text

__iocs_textput:
		movem.l		xdot(sp),d1-d2/a1
		iocs		__TEXTPUT
		rts

		.end
