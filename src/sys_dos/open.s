* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: open.s,v 1.3 1993/10/06 17:03:14 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_open

		.offset		4

file:		.ds.l		1
mode:		.ds.l		1

		.text

__dos_open:
		move.w		10(sp),-(sp)		* mode
		move.l		6(sp),-(sp)		* file
		dc.w		__OPEN
		addq.w		#6,sp
		rts

		.end
