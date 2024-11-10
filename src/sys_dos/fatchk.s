* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: fatchk.s,v 1.3 1993/10/06 16:57:06 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_fatchk

		.offset		4

file:		.ds.l		1
bufptr:		.ds.l		1

		.text

__dos_fatchk:
		move.l		8(sp),-(sp)		* bufptr
		move.l		8(sp),-(sp)		* file
		dc.w		__FATCHK
		addq.w		#8,sp
		rts

		.end
