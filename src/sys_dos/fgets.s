* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: fgets.s,v 1.3 1993/10/06 16:57:23 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_fgets

		.offset		4

inpptr:		.ds.l		1
fno:		.ds.l		1

		.text

__dos_fgets:
		move.w		10(sp),-(sp)		* fno
		move.l		6(sp),-(sp)		* inpptr
		dc.w		__FGETS
		addq.w		#6,sp
		rts

		.end
