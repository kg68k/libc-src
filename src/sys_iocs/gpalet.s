* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: gpalet.s,v 1.3 1993/10/06 17:14:26 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_gpalet

		.offset		4

no		.ds.l		1
color		.ds.l		1

		.text

__iocs_gpalet:
		movem.l		no(sp),d1-d2
		iocs		__GPALET
		rts

		.end
