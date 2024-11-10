* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: inpout.s,v 1.3 1993/10/06 16:59:54 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_inpout

		.offset		4

code:		.ds.l		1

		.text

__dos_inpout:
		move.w		6(sp),-(sp)		* code
		dc.w		__INPOUT
		addq.w		#2,sp
		rts

		.end
