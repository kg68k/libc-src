* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: drvxchg.s,v 1.3 1993/10/06 16:56:22 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_drvxchg

		.offset		4

old:		.ds.l		1
new:		.ds.l		1

		.text

__dos_drvxchg:
		move.w		10(sp),-(sp)		* new
		move.w		8(sp),-(sp)		* old
		dc.w		__DRVXCHG
		addq.w		#4,sp
		rts

		.end
