* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: opmset.s,v 1.2 1993/10/06 17:16:40 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_opmset

		.offset		4

addr		.ds.l		1
data		.ds.l		1

		.text

__iocs_opmset:
		movem.l		addr(sp),d1-d2
		iocs		__OPMSET
		rts

		.end
