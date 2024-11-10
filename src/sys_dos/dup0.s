* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dup0.s,v 1.3 1993/10/06 16:56:35 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_dup0

		.offset		4

fno:		.ds.l		1
newno:		.ds.l		1

		.text

__dos_dup0:
		move.w		10(sp),-(sp)		* newno
		move.w		8(sp),-(sp)		* fno
		dc.w		__DUP0
		addq.w		#4,sp
		rts

		.end