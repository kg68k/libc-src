* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: move.s,v 1.3 1993/10/06 17:02:52 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_move

		.offset		4

old:		.ds.l		1
new:		.ds.l		1

		.text

__dos_move:
		move.l		8(sp),-(sp)		* new
		move.l		8(sp),-(sp)		* old
		dc.w		__RENAME
		addq.w		#8,sp
		rts

		.end
