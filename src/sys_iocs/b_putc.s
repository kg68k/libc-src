* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_putc.s,v 1.2 1993/10/06 17:10:34 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_putc

		.offset		4

code		.ds.l		1

		.text

__iocs_b_putc:
		move.l		code(sp),d1	* code
		iocs		__B_PUTC
		rts

		.end
