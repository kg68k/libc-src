* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: tpalet.s,v 1.2 1993/10/06 17:20:03 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_tpalet

		.offset		4

paletno		.ds.l		1
color		.ds.l		1

		.text

__iocs_tpalet:
		movem.l		paletno(sp),d1-d2
		iocs		__TPALET
		rts

		.end
