* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: c_print.s,v 1.3 1993/10/06 16:53:58 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_c_print

		.offset		4

msgptr:		.ds.l		1

		.text

__dos_c_print:
		move.l		4(sp),-(sp)		* msgptr
		move.w		#1,-(sp)
		dc.w		__CONCTRL
		addq.w		#6,sp
		rts

		.end
