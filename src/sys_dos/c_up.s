* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: c_up.s,v 1.3 1993/10/06 16:54:11 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_c_up

		.offset		4

n:		.ds.l		1

		.text

__dos_c_up:
		move.w		6(sp),-(sp)		* n
		move.w		#6,-(sp)
		dc.w		__CONCTRL
		addq.w		#4,sp
		rts

		.end
