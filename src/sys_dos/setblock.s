* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: setblock.s,v 1.3 1993/10/06 17:04:35 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_setblock

		.offset		4

memptr:		.ds.l		1
newlen:		.ds.l		1

		.text

__dos_setblock:
		move.l		8(sp),-(sp)		* newlen
		move.l		8(sp),-(sp)		* memptr
		dc.w		__SETBLOCK
		addq.w		#8,sp
		rts

		.end
