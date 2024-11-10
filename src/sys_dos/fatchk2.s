* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: fatchk2.s,v 1.4 1993/10/06 16:57:10 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_fatchk2

		.offset		4

file:		.ds.l		1
bufptr:		.ds.l		1
length:		.ds.l		1

		.text

__dos_fatchk2:
		move.w		14(sp),-(sp)		* length
		move.l		10(sp),d0		* bufptr
		bset.l		#31,d0
		move.l		d0,-(sp)
		move.l		10(sp),-(sp)		* file
		dc.w		__FATCHK
		lea.l		10(sp),sp
		rts

		.end
