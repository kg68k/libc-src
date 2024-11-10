* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: newfile.s,v 1.3 1993/10/06 17:03:05 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_newfile

		.offset		4

file:		.ds.l		1
atr:		.ds.l		1

		.text

__dos_newfile:
		move.w		10(sp),-(sp)		* atr
		move.l		6(sp),-(sp)		* file
		dc.w		__NEWFILE
		addq.w		#6,sp
		rts

		.end
