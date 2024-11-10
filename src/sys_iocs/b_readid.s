* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_readid.s,v 1.3 1993/10/06 17:10:57 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_readid

		.offset		4

drive		.ds.l		1
track		.ds.l		1
addr		.ds.l		1

		.text

__iocs_b_readid:
		movem.l		drive(sp),d1-d2
		iocs		__B_READID
		movea.l		addr(sp),a0
		move.l		d2,(a0)		* buffer set
		rts

		.end
