* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dmamove.s,v 1.3 1993/10/06 17:14:03 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_dmamove

		.offset		4

addr1		.ds.l		1
addr2		.ds.l		1
mode		.ds.l		1
cnt		.ds.l		1

		.text

__iocs_dmamove:
		movem.l		addr1(sp),a1-a2
		movem.l		mode(sp),d1-d2
		iocs		__DMAMOVE
		rts

		.end
