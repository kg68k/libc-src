* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: keeppr.s,v 1.3 1993/10/06 17:01:28 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_keeppr

		.offset		4

prglen:		.ds.l		1
code:		.ds.l		1

		.text

__dos_keeppr:
		move.w		10(sp),-(sp)		* code
		move.l		6(sp),-(sp)		* prglen
		dc.w		__KEEPPR
		rts

		.end
