* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: settim2.s,v 1.3 1993/10/06 17:04:53 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_settim2

		.offset		4

time:		.ds.l		1

		.text

__dos_settim2:
		move.l		4(sp),-(sp)		* time
		dc.w		__SETTIM2
		addq.w		#4,sp
		rts

		.end
