* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_intvcs.s,v 1.3 1993/10/06 17:09:45 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_intvcs

		.offset		4

vector		.ds.l		1
addr		.ds.l		1

		.text

__iocs_b_intvcs:
		movem.l		vector(sp),d1/a1
		iocs		__B_INTVCS
		rts

		.end
