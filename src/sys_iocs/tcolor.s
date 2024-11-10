* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: tcolor.s,v 1.2 1993/10/06 17:19:04 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_tcolor

		.offset		4

color		.ds.l		1

		.text

__iocs_tcolor:
		move.l		color(sp),d1
		iocs		__TCOLOR
		rts

		.end
