* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: comout.s,v 1.3 1993/10/06 16:55:25 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_comout

		.offset		4

code:		.ds.l		1

		.text

__dos_comout:
		move.w		6(sp),-(sp)		* code
		dc.w		__COMOUT
		addq.w		#2,sp
		rts

		.end