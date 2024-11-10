* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: intvcg.s,v 1.3 1993/10/06 16:59:59 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_intvcg

		.offset		4

intno:		.ds.l		1

		.text

__dos_intvcg:
		move.w		6(sp),-(sp)		* intno
		dc.w		__INTVCG
		addq.w		#2,sp
		rts

		.end
