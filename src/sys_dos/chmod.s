* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: chmod.s,v 1.3 1993/10/06 16:54:42 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_chmod

		.offset		4

file:		.ds.l		1
attr:		.ds.l		1

		.text

__dos_chmod:
		move.w		10(sp),-(sp)		* attr
		move.l		6(sp),-(sp)		* file
		dc.w		__CHMOD
		addq.w		#6,sp
		rts

		.end
