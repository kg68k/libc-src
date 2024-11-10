* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: tgusemd.s,v 1.2 1993/10/06 17:19:20 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_tgusemd

		.offset		4

text_gr		.ds.l		1
mode		.ds.l		1

		.text

__iocs_tgusemd:
		move.l		text_gr(sp),d1	* text = 1, gr = 0
		move.l		mode(sp),d2	* use mode
		iocs		__TGUSEMD
		rts

		.end
