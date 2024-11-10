* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: tpalet2.s,v 1.2 1993/10/06 17:20:08 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_tpalet2

		.offset		4

paletno		.ds.l		1
color		.ds.l		1

		.text

__iocs_tpalet2:
		move.l		paletno(sp),d1
		move.l		color(sp),d2
		iocs		__TPALET2
		rts

		.end
