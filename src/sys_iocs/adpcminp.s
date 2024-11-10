* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: adpcminp.s,v 1.2 1993/10/06 17:06:53 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_adpcminp

		.offset		4

addr		.ds.l		1
mode		.ds.l		1
length		.ds.l		1

		.text

__iocs_adpcminp:
		movea.l		addr(sp),a1
		movem.l		mode(sp),d1-d2
		iocs		__ADPCMINP
		rts

		.end
