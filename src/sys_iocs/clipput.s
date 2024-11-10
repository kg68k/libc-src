* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: clipput.s,v 1.2 1993/10/06 17:12:54 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_clipput

		.offset		4

xdot		.ds.l		1
ydot		.ds.l		1
buf1		.ds.l		1
buf2		.ds.l		1

		.text

__iocs_clipput:
		movem.l		xdot(sp),d1-d2/a1-a2
		iocs		__CLIPPUT
		rts

		.end
