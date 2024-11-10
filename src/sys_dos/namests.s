* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: namests.s,v 1.3 1993/10/06 17:03:01 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_namests

		.offset		4

file:		.ds.l		1
buffer:		.ds.l		1

		.text

__dos_namests:
		move.l		8(sp),-(sp)		* buffer
		move.l		8(sp),-(sp)		* file
		dc.w		__NAMESTS
		addq.w		#8,sp
		rts

		.end
