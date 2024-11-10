* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: c_window.s,v 1.3 1993/10/06 16:54:24 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_c_window

		.offset		4

ys:		.ds.l		1
yl:		.ds.l		1

		.text

__dos_c_window:
		move.w		10(sp),-(sp)		* yl
		move.w		8(sp),-(sp)		* ys
		move.w		#15,-(sp)
		dc.w		__CONCTRL
		addq.w		#6,sp
		rts

		.end
