* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: c_locate.s,v 1.3 1993/10/06 16:53:54 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_c_locate

		.offset		4

x:		.ds.l		1
y:		.ds.l		1

		.text

__dos_c_locate:
		move.w		10(sp),-(sp)		* y
		move.w		8(sp),-(sp)		* x
		move.w		#3,-(sp)
		dc.w		__CONCTRL
		addq.w		#6,sp
		rts

		.end
