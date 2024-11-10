* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_del.s,v 1.2 1993/10/06 17:08:47 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_del

		.offset		4

num		.ds.l		1

		.text

__iocs_b_del:
		move.l		num(sp),d1
		iocs		__B_DEL
		rts

		.end
