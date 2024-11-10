* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dmamov_a.s,v 1.3 1993/10/06 17:13:54 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_dmamov_a

		.offset		4

addr1		.ds.l		1
addr2		.ds.l		1
mode		.ds.l		1
cnt		.ds.l		1

		.text

__iocs_dmamov_a:
		movem.l		addr1(sp),a1-a2
		movem.l		mode(sp),d1-d2
		iocs		__DMAMOV_A
		rts

		.end
