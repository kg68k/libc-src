* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_print.s,v 1.2 1993/10/06 17:10:29 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_print

		.offset		4

msg		.ds.l		1

		.text

__iocs_b_print:
		movea.l		msg(sp),a1
		iocs		__B_PRINT
		rts

		.end