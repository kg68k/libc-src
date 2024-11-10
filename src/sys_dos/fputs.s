* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: fputs.s,v 1.3 1993/10/06 16:57:50 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_fputs

		.offset		4

mesptr:		.ds.l		1
fno:		.ds.l		1

		.text

__dos_fputs:
		move.w		10(sp),-(sp)		* fno
		move.l		6(sp),-(sp)		* mesptr
		dc.w		__FPUTS
		addq.w		#6,sp
		rts

		.end
