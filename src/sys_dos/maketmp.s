* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: maketmp.s,v 1.3 1993/10/06 17:02:25 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_maketmp

		.offset		4

file:		.ds.l		1
atr:		.ds.l		1

		.text

__dos_maketmp:
		move.w		10(sp),-(sp)		* atr
		move.l		6(sp),-(sp)		* file
		dc.w		__MAKETMP
		addq.w		#6,sp
		rts

		.end
