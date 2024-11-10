* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: prnout.s,v 1.3 1993/10/06 17:03:32 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_prnout

		.offset		4

code:		.ds.l		1

		.text

__dos_prnout:
		move.w		6(sp),-(sp)		* code
		dc.w		__PRNOUT
		addq.w		#2,sp
		rts

		.end
