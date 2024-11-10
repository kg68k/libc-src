* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dmamov_l.s,v 1.3 1993/10/06 17:13:58 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_dmamov_l

		.offset		4

addr1		.ds.l		1
addr2		.ds.l		1
mode		.ds.l		1

		.text

__iocs_dmamov_l:
		movem.l		addr1(sp),a1-a2
		move.l		mode(sp),d1
		iocs		__DMAMOV_L
		rts

		.end
