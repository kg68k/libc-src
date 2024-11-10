* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: s_mfree.s,v 1.4 1993/10/06 17:04:17 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_s_mfree

		.offset		4

memptr:		.ds.l		1

		.text

__dos_s_mfree:
		move.l		4(sp),-(sp)		* memptr
		dc.w		__S_MFREE
		addq.w		#4,sp
		rts

		.end
