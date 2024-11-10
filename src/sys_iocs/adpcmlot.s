* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: adpcmlot.s,v 1.2 1993/10/06 17:07:04 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_adpcmlot

		.offset		4

tbladdr		.ds.l		1
mode		.ds.l		1

		.text

__iocs_adpcmlot:
		movea.l		tbladdr(sp),a1
		move.l		mode(sp),d1
		iocs		__ADPCMLOT
		rts

		.end
