* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: out232c.s,v 1.3 1993/10/06 17:17:04 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_out232c

		.offset		4

code		.ds.l		1

		.text

__iocs_out232c:
		move.l		code(sp),d1	* code
		iocs		__OUT232C
		rts

		.end
