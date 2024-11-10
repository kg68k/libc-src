* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_up.s,v 1.2 1993/10/06 17:11:26 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_up

		.offset		4

num		.ds.l		1

		.text

__iocs_b_up:
		move.l		num(sp),d1
		iocs		__B_UP
		rts

		.end
