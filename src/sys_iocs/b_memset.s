* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_memset.s,v 1.3 1993/10/06 17:10:19 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_memset

		.offset		4

addr		.ds.l		1
databuf		.ds.l		1
cnt		.ds.l		1

		.text

__iocs_b_memset:
		movem.l		addr(sp),a1-a2
		move.l		cnt(sp),d1
		iocs		__B_MEMSET
		rts

		.end
