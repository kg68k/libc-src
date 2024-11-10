* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dateasc.s,v 1.2 1993/10/06 17:13:19 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_dateasc

		.offset		4

bindate		.ds.l		1
addr		.ds.l		1

		.text

__iocs_dateasc:
		movem.l		bindate(sp),d1/a1
		iocs		__DATEASC
		rts

		.end
