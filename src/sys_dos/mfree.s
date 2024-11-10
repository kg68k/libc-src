* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: mfree.s,v 1.3 1993/10/06 17:02:43 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_mfree

		.offset		4

memptr:		.ds.l		1

		.text

__dos_mfree:
		move.l		4(sp),-(sp)		* memptr
		dc.w		__MFREE
		addq.w		#4,sp
		rts

		.end
