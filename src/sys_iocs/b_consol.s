* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_consol.s,v 1.2 1993/10/06 17:08:32 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_consol

		.offset		4

xs		.ds.l		1
ys		.ds.l		1
xl		.ds.l		1
yl		.ds.l		1

		.text

__iocs_b_consol:
		move.w		xs+2(sp),d1
		swap.w		d1
		move.w		ys+2(sp),d1
		move.w		xl+2(sp),d2
		swap.w		d2
		move.w		yl+2(sp),d2
		iocs		__B_CONSOL
		move.l		d2,d0		* return value set
		rts

		.end
