* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: malloc2.s,v 1.3 1993/10/06 17:02:34 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_malloc2

		.offset		4

md:		.ds.l		1
size:		.ds.l		1

		.text

__dos_malloc2:
		move.l		8(sp),-(sp)		* size
		move.w		10(sp),-(sp)		* md
		dc.w		__MALLOC2
		addq.w		#6,sp
		rts

		.end
